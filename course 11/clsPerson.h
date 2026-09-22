#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _lastName;
	string _Email;
	string _phone;

public:

	clsPerson(string FirstName,string LastName,string Email,string Phone)
	{
		_FirstName = FirstName;
		_lastName = LastName;
		_Email = Email;
		_phone = Phone;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName)
	{
		_lastName = LastName;
	}

	string GetLastName()
	{
		return _lastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SetPhone(string Phone)
	{
		_phone = Phone;
	}

	string GetPhone()
	{
		return	_phone;
	}
	
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _lastName;
	}

};

