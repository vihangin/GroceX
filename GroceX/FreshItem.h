#pragma once
#include "GroceryItem.h"

// INHERITANCE: FreshItem (fruit, vegetables...) inherits from GroceryItem.
class FreshItem : public GroceryItem
{
public:
	FreshItem(int id, const std::string& name, double price, int quantity)
		: GroceryItem(id, name, price, quantity) {}

	std::string getTypeName() const override { return "Fresh"; }

	// POLYMORPHISM: same function name, different behaviour (10% fresh discount).
	double getFinalPrice() const override { return getPrice() * 0.9; }

	// Fresh items spoil quickly, so a higher stock level is treated as "low".
	bool isLowStock() const override { return getQuantity() <= 20; }

	std::string getInfo() const override
	{
		return GroceryItem::getInfo() + " [10% fresh discount]";
	}
};