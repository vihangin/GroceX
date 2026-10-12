#pragma once
#using "lib/MySql.Data.dll"
#include <string>
#include <vector>
#include "GroceryItem.h"
#include "PackagedItem.h"
#include "Supplier.h"
#include "User.h"
#include "Helpers.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace GroceX {

	// Handles every MySQL operation (create database/tables + add/view/update/delete).
	// Change the settings below to match your MySQL installation.
	ref class Database
	{
	private:
		String^ server = "localhost";
		String^ user = "root";
		String^ password = "1111111111";       // <-- put your MySQL password here
		String^ dbName = "groceX";

		String^ serverConnString()
		{
			return "Server=" + server + ";User ID=" + user + ";Password=" + password + ";";
		}
		String^ dbConnString()
		{
			return serverConnString() + "Database=" + dbName + ";";
		}

		// Runs an INSERT / UPDATE / DELETE with a list of parameter names and values.
		void run(String^ sql, array<String^>^ names, array<Object^>^ values)
		{
			MySqlConnection conn(dbConnString());
			conn.Open();
			MySqlCommand cmd(sql, % conn);
			for (int i = 0; i < names->Length; i++)
				cmd.Parameters->AddWithValue(names[i], values[i]);
			cmd.ExecuteNonQuery();
		}

	public:
		// Creates the database and tables if they do not exist yet.
		void initialize()
		{
			{
				MySqlConnection c(serverConnString());
				c.Open();
				MySqlCommand cmd("CREATE DATABASE IF NOT EXISTS " + dbName, % c);
				cmd.ExecuteNonQuery();
			}
			MySqlConnection conn(dbConnString());
			conn.Open();
			MySqlCommand t1("CREATE TABLE IF NOT EXISTS products ("
				"id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100) NOT NULL, "
				"type VARCHAR(20) NOT NULL, price DECIMAL(10,2) NOT NULL, quantity INT NOT NULL)", % conn);
			t1.ExecuteNonQuery();
			MySqlCommand t2("CREATE TABLE IF NOT EXISTS suppliers ("
				"id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100) NOT NULL, "
				"phone VARCHAR(20) NOT NULL, supplies VARCHAR(150))", % conn);
			t2.ExecuteNonQuery();
			MySqlCommand t3("CREATE TABLE IF NOT EXISTS users ("
				"id INT AUTO_INCREMENT PRIMARY KEY, username VARCHAR(50) NOT NULL UNIQUE, "
				"password_hash VARCHAR(64) NOT NULL, role VARCHAR(20) NOT NULL DEFAULT 'Pending')", % conn);
			t3.ExecuteNonQuery();

			// Create the built-in super admin account the first time
			User* admin = getUser("super_admin");
			if (admin == nullptr)
			{ 
				User newAdmin(0, "super_admin", hashPassword("supersuper"), "SuperAdmin");

				addUser(newAdmin);
			}
			delete admin;
		}

		// ---------------- PRODUCTS ----------------

		// Returns all products whose name contains "search".
		// The items are created with new, so the caller must call deleteAll() on the vector.
		std::vector<GroceryItem*> getProducts(const std::string& search)
		{
			std::vector<GroceryItem*> list;
			MySqlConnection conn(dbConnString());
			conn.Open();
			MySqlCommand cmd("SELECT * FROM products WHERE name LIKE @s ORDER BY name", % conn);
			cmd.Parameters->AddWithValue("@s", "%" + toManaged(search) + "%");
			MySqlDataReader^ r = cmd.ExecuteReader();
			while (r->Read())
			{
				list.push_back(createItem(
					toNative(Convert::ToString(r["type"])),
					Convert::ToInt32(r["id"]),
					toNative(Convert::ToString(r["name"])),
					Convert::ToDouble(r["price"]),
					Convert::ToInt32(r["quantity"])));
			}
			r->Close();
			return list;
		}

		void addProduct(const GroceryItem& item)
		{
			run("INSERT INTO products (name, type, price, quantity) VALUES (@n, @t, @p, @q)",
				gcnew array<String^>{"@n", "@t", "@p", "@q"},
				gcnew array<Object^>{toManaged(item.getName()), toManaged(item.getTypeName()), item.getPrice(), item.getQuantity()});
		}

		void updateProduct(const GroceryItem& item)
		{
			run("UPDATE products SET name=@n, type=@t, price=@p, quantity=@q WHERE id=@id",
				gcnew array<String^>{"@n", "@t", "@p", "@q", "@id"},
				gcnew array<Object^>{toManaged(item.getName()), toManaged(item.getTypeName()), item.getPrice(), item.getQuantity(), item.getId()});
		}

		void deleteProduct(int id)
		{
			run("DELETE FROM products WHERE id=@id",
				gcnew array<String^>{"@id"}, gcnew array<Object^>{id});
		}

		// ---------------- SUPPLIERS ----------------

		// The caller must call deleteAll() on the returned vector.
		std::vector<Supplier*> getSuppliers(const std::string& search)
		{
			std::vector<Supplier*> list;
			MySqlConnection conn(dbConnString());
			conn.Open();
			MySqlCommand cmd("SELECT * FROM suppliers WHERE name LIKE @s ORDER BY name", % conn);
			cmd.Parameters->AddWithValue("@s", "%" + toManaged(search) + "%");
			MySqlDataReader^ r = cmd.ExecuteReader();
			while (r->Read())
			{
				list.push_back(new Supplier(
					Convert::ToInt32(r["id"]),
					toNative(Convert::ToString(r["name"])),
					toNative(Convert::ToString(r["phone"])),
					toNative(Convert::ToString(r["supplies"]))));
			}
			r->Close();
			return list;
		}

		void addSupplier(const Supplier& s)
		{
			run("INSERT INTO suppliers (name, phone, supplies) VALUES (@n, @p, @s)",
				gcnew array<String^>{"@n", "@p", "@s"},
				gcnew array<Object^>{toManaged(s.getName()), toManaged(s.getPhone()), toManaged(s.getSupplies())});
		}

		void updateSupplier(const Supplier& s)
		{
			run("UPDATE suppliers SET name=@n, phone=@p, supplies=@s WHERE id=@id",
				gcnew array<String^>{"@n", "@p", "@s", "@id"},
				gcnew array<Object^>{toManaged(s.getName()), toManaged(s.getPhone()), toManaged(s.getSupplies()), s.getId()});
		}

		void deleteSupplier(int id)
		{
			run("DELETE FROM suppliers WHERE id=@id",
				gcnew array<String^>{"@id"}, gcnew array<Object^>{id});
		}

		// ---------------- USERS ----------------

		// Returns the user with this username (created with new), or nullptr if none exists.
		// The caller must delete the returned user.
		User* getUser(const std::string& username)
		{
			User* result = nullptr;
			MySqlConnection conn(dbConnString());
			conn.Open();
			MySqlCommand cmd("SELECT * FROM users WHERE username=@u", % conn);
			cmd.Parameters->AddWithValue("@u", toManaged(username));
			MySqlDataReader^ r = cmd.ExecuteReader();
			if (r->Read())
			{
				result = new User(
					Convert::ToInt32(r["id"]),
					toNative(Convert::ToString(r["username"])),
					toNative(Convert::ToString(r["password_hash"])),
					toNative(Convert::ToString(r["role"])));
			}
			r->Close();
			return result;
		}

		void addUser(const User& u)
		{
			run("INSERT INTO users (username, password_hash, role) VALUES (@u, @p, @r)",
				gcnew array<String^>{"@u", "@p", "@r"},
				gcnew array<Object^>{toManaged(u.getUsername()), toManaged(u.getPasswordHash()), toManaged(u.getRole())});
		}

		// All users except the super admin. The caller must call deleteAll() on the vector.
		std::vector<User*> getUsers()
		{
			std::vector<User*> list;
			MySqlConnection conn(dbConnString());
			conn.Open();
			MySqlCommand cmd("SELECT * FROM users WHERE role <> 'SuperAdmin' ORDER BY id", % conn);
			MySqlDataReader^ r = cmd.ExecuteReader();
			while (r->Read())
			{
				list.push_back(new User(
					Convert::ToInt32(r["id"]),
					toNative(Convert::ToString(r["username"])),
					toNative(Convert::ToString(r["password_hash"])),
					toNative(Convert::ToString(r["role"]))));
			}
			r->Close();
			return list;
		}

		void updateUserRole(int id, const std::string& role)
		{
			run("UPDATE users SET role=@r WHERE id=@id AND role <> 'SuperAdmin'",
				gcnew array<String^>{"@r", "@id"}, gcnew array<Object^>{toManaged(role), id});
		}

		void deleteUser(int id)
		{
			run("DELETE FROM users WHERE id=@id AND role <> 'SuperAdmin'",
				gcnew array<String^>{"@id"}, gcnew array<Object^>{id});
		}
	};
}