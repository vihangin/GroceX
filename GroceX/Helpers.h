#pragma once
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>

// ---------------------------------------------------------------
// Small helper functions used by the forms and the database class.
// ---------------------------------------------------------------

// Deletes every object stored in a vector of pointers, then empties the vector.
template <class T>
void deleteAll(std::vector<T*>& list)
{
	for (size_t i = 0; i < list.size(); i++)
		delete list[i];
	list.clear();
}

// Converts a normal C++ string (std::string) into a Windows Forms string.
inline System::String^ toManaged(const std::string& text)
{
	return gcnew System::String(text.c_str());
}

// Converts a Windows Forms string into a normal C++ string (std::string).
inline std::string toNative(System::String^ text)
{
	return msclr::interop::marshal_as<std::string>(text);
}

// Simple password hashing (SHA-256). Passwords are never stored as plain text.
inline std::string hashPassword(const std::string& password)
{
	System::Security::Cryptography::SHA256^ sha = System::Security::Cryptography::SHA256::Create();
	array<System::Byte>^ bytes = sha->ComputeHash(System::Text::Encoding::UTF8->GetBytes(toManaged(password)));
	return toNative(System::BitConverter::ToString(bytes)->Replace("-", "")->ToLower());
}