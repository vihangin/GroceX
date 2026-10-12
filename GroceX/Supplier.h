#pragma once
#include "Person.h"

// INHERITANCE: Supplier inherits id, name and phone from Person.
class Supplier : public Person
{
private:
	std::string supplies;

public:
	Supplier(int id, const std::string& name, const std::string& phone, const std::string& supplies)
		: Person(id, name, phone)
	{
		setSupplies(supplies);
	}

	std::string getSupplies() const { return supplies; }
	void setSupplies(const std::string& newSupplies) { supplies = newSupplies; }

	// POLYMORPHISM: Supplier's own version of getRole().
	std::string getRole() const override { return "Supplier"; }
};