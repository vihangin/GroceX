#pragma once
#include <string>
#include "GroceryItem.h"
#include "FreshItem.h"

// INHERITANCE: PackagedItem (rice, biscuits, tins...) inherits from GroceryItem.
class PackagedItem : public GroceryItem
{
public:
	PackagedItem(int id, const std::string& name, double price, int quantity)
		: GroceryItem(id, name, price, quantity) {}

	std::string getTypeName() const override { return "Packaged"; }

	// POLYMORPHISM: packaged items are sold at the normal price.
	double getFinalPrice() const override { return getPrice(); }
};

// Creates the correct kind of item ("Fresh" or "Packaged") using new.
// The caller must delete it when finished.
inline GroceryItem* createItem(const std::string& type, int id, const std::string& name, double price, int quantity)
{
	if (type == "Fresh")
		return new FreshItem(id, name, price, quantity);
	return new PackagedItem(id, name, price, quantity);
}