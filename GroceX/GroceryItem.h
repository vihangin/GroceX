#pragma once
#include <string>
#include <stdexcept>

// ABSTRACTION: GroceryItem is an abstract class (it has pure virtual functions),
// so we can never create a plain GroceryItem object. Only its child classes.
class GroceryItem
{
private:
	// ENCAPSULATION: data members are private.
	// They can only be changed through the set functions, which check the values.
	int id;
	std::string name;
	double price;
	int quantity;

public:
	GroceryItem(int id, const std::string& name, double price, int quantity)
	{
		setId(id);
		setName(name);
		setPrice(price);
		setQuantity(quantity);
	}

	// Virtual destructor so that "delete" works correctly on a GroceryItem pointer.
	virtual ~GroceryItem() {}

	// ---- get functions ----
	int getId() const { return id; }
	std::string getName() const { return name; }
	double getPrice() const { return price; }
	int getQuantity() const { return quantity; }

	// ---- set functions (with validation) ----
	void setId(int newId) { id = newId; }

	void setName(const std::string& newName)
	{
		if (newName.find_first_not_of(" \t") == std::string::npos)
			throw std::invalid_argument("Item name cannot be empty.");
		name = newName;
	}

	void setPrice(double newPrice)
	{
		if (newPrice < 0)
			throw std::invalid_argument("Price cannot be negative.");
		price = newPrice;
	}

	void setQuantity(int newQuantity)
	{
		if (newQuantity < 0)
			throw std::invalid_argument("Quantity cannot be negative.");
		quantity = newQuantity;
	}

	// Pure virtual functions: every child class MUST write its own version.
	virtual std::string getTypeName() const = 0;
	virtual double getFinalPrice() const = 0;

	// Normal virtual function: child classes MAY replace it.
	virtual bool isLowStock() const { return quantity <= 10; }

	virtual std::string getInfo() const
	{
		return name + " (" + getTypeName() + ") - Rs. " + std::to_string(getFinalPrice());
	}

	double getStockValue() const { return getFinalPrice() * quantity; }
};