#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;


class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency & Currency)
	{
		cout << "\nCurrency Card: " << endl << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Country        : " << Currency.Country() << endl;
		cout << "Code           : " << Currency.CurrencyCode() << endl;
		cout << "Name           : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)       : " << Currency.Rate() << endl;
		cout << "----------------------------------------------------" << endl;
	}

	static void _UpdateRate(clsCurrency & Currency)
	{
		cout << "\nUpdate Currency Rate:" << endl;
		cout << "---------------------" << endl;

		cout << "Enter New Rate: ";
		float NewRate = 0;
		NewRate = clsInputValidate::ReadNumber<float>();

		cout << "\nCurrency Rate Updated Successfully :-)" << endl;

		Currency.UpdateRate(NewRate);

		_PrintCurrencyCard(Currency);
	}

public:

	static void ShowUpdateCurrencyScreen()
	{

		_DrawScreenHeader("    Update Currency Screen");

		string Code;
		cout << "pls enter Currency Code;";
		Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		if (!Currency.IsEmpty())
		{
			_PrintCurrencyCard(Currency);

			char Answer = 'n';
			cout << "Are you sure you want to update the rate of this country? y/n?" << endl;
			cin >> Answer;

			if (tolower(Answer) == 'y')
			{
				_UpdateRate(Currency);
			}
			else
			{
				cout << "Currency Rate was Not Updated.";
			}
		}
		else
		{
			cout << "Currency Code is not Found!\n";
		}
	}
};

