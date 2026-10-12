#pragma once
#include <string>
#include <stdexcept>

// A person who can sign in to GroceX.
// Roles: "SuperAdmin", "Manager", "Staff" and "Pending" (new sign-ups, no access yet).
class User
{
private:
	int id;
	std::string username;
	std::string passwordHash;
	std::string role;

public:
	User(int id, const std::string& username, const std::string& passwordHash, const std::string& role)
	{
		setId(id);
		setUsername(username);
		setPasswordHash(passwordHash);
		setRole(role);
	}

	int getId() const { return id; }
	std::string getUsername() const { return username; }
	std::string getPasswordHash() const { return passwordHash; }
	std::string getRole() const { return role; }

	void setId(int newId) { id = newId; }

	void setUsername(const std::string& newUsername)
	{
		if (newUsername.size() < 3 || newUsername.find(' ') != std::string::npos)
			throw std::invalid_argument("Username must be at least 3 characters with no spaces.");
		username = newUsername;
	}

	void setPasswordHash(const std::string& newHash) { passwordHash = newHash; }
	void setRole(const std::string& newRole) { role = newRole; }

	// What each role is allowed to do
	bool isApproved() const { return role != "Pending"; }
	bool canManageProducts() const { return role == "SuperAdmin" || role == "Manager" || role == "Staff"; }
	bool canManageSuppliers() const { return role == "SuperAdmin" || role == "Manager"; }
	bool canManageUsers() const { return role == "SuperAdmin"; }
};