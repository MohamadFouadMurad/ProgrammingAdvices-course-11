#pragma once

#include <iostream>
#include "clsCurrency.h"
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;


class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency& Currency)
	{
		cout << "Currency Card: " << endl << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Country        : " << Currency.Country() << endl;
		cout << "Code           : " << Currency.CurrencyCode() << endl;
		cout << "Name           : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)       : " << Currency.Rate() << endl;
		cout << "----------------------------------------------------" << endl;
	}

	static string _ReadInputToFind(string Message)
	{
		cout << Message;

		string s = clsInputValidate::ReadString();
		
		return s;
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was NOT Found :-(\n\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("    Find Currency Screen");

		short Choice;
		cout << "Find By : [1] Code or [2] Country ? " << endl;
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2 , "pls Enter Number Between [1] Code and [2] Country?");


		switch (Choice)
		{

		case 1:
		{
			string Code = _ReadInputToFind("\nPlease Enter Currency Code: ");
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			_ShowResults(Currency);
			break;
		}

		case 2:
		{
			string Country = _ReadInputToFind("\nPlease Enter Country Name: ");
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
			break;
		}


		}
	}
};

