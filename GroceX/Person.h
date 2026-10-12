#pragma once
#include <string>
#include <stdexcept>

// ABSTRACTION: Person is an abstract class (getRole is a pure virtual function).
class Person
{
private:
	// ENCAPSULATION: private data, changed only through set functions.
	int id;
	std::string name;
	std::string phone;

public:
	Person(int id, const std::string& name, const std::string& phone)
	{
		setId(id);
		setName(name);
		setPhone(phone);
	}

	virtual ~Person() {}

	int getId() const { return id; }
	std::string getName() const { return name; }
	std::string getPhone() const { return phone; }

	void setId(int newId) { id = newId; }

	void setName(const std::string& newName)
	{
		if (newName.find_first_not_of(" \t") == std::string::npos)
			throw std::invalid_argument("Name cannot be empty.");
		name = newName;
	}

	void setPhone(const std::string& newPhone)
	{
		bool ok = newPhone.size() >= 7;
		for (size_t i = 0; i < newPhone.size(); i++)
		{
			if ((newPhone[i] < '0' || newPhone[i] > '9') && newPhone[i] != '+')
				ok = false;
		}
		if (!ok)
			throw std::invalid_argument("Enter a valid phone number (digits only, min 7).");
		phone = newPhone;
	}

	// Pure virtual function: child classes must write it.
	virtual std::string getRole() const = 0;
};