#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClinetDate;
		vClinetDate = clsString::Split(Line, Seperator);

		return clsBankClient(vClinetDate[0], vClinetDate[1], vClinetDate[2],
			vClinetDate[3], enMode::UpdateMode, vClinetDate[4], vClinetDate[5], stoi(vClinetDate[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient("", "", "", "", enMode::EmptyMode, "", "", 0);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient & C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;

				}
			}

			MyFile.close();

		}

	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient & C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

public:

	clsBankClient(string FirstName ,string LastName , string Email,
		string Phone , enMode Mode,string AccountNumber,string PinCode,
		float AccountBalance) :
		clsPerson(FirstName , LastName , Email , Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClinet Card:";
		cout << "\n-------------------------";
		cout << "\nFirstName    : " << FirstName;
		cout << "\nLastName     : " << LastName;
		cout << "\nFullName     : " << FullName();
		cout << "\nEmail        : " << Email;
		cout << "\nPhone        : " << Phone;
		cout << "\nAcc. Number  : " << _AccountNumber;
		cout << "\nPassword     : " << _PinCode;
		cout << "\nBalance      : " << _AccountBalance;
		cout << "\n-------------------------";
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsBankClient Client = _ConvertLineToClientObject(Line);

					if (Client.AccountNumber() == AccountNumber)
					{
						MyFile.close();
						return Client;
					}
					vClients.push_back(Client);
				}

				MyFile.close();
			}

			return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists =2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return	enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();

			return	enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}

		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient("", "", "", "", enMode::AddNewMode, AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClient);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double Totalbalances = 0;

		for (clsBankClient Clients : vClients)
		{
			Totalbalances += Clients.AccountBalance;
		}

		return Totalbalances;
	}
};

