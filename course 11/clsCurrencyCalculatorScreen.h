#pragma once

#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency & Currency)
	{
		cout << "----------------------------------------------------" << endl;
		cout << "Country        : " << Currency.Country() << endl;
		cout << "Code           : " << Currency.CurrencyCode() << endl;
		cout << "Name           : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)       : " << Currency.Rate() << endl;
		cout << "----------------------------------------------------" << endl;
	}

	static string _ReadCurrencyCode(string Type)
	{
		cout << "\n\npls enter Currency code you want to convert " << Type << " : \n";

		string Code = clsInputValidate::ReadString();

		return Code;
	}

	static clsCurrency _GetCurrency(string Type)
	{
		string CurrencyCode = _ReadCurrencyCode(Type);
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		while (Currency.IsEmpty())
		{
			cout << "Currency is not found ..\n";
			CurrencyCode = _ReadCurrencyCode(Type);
			Currency = clsCurrency::FindByCode(CurrencyCode);
		}

		return Currency;
	}

	static float _ReadAmount()
	{
		cout << "\npls enter Amount ?";
		float Amount =clsInputValidate::ReadNumber<float>();
		return Amount;
	}
	
	static void _PrintCalculationsResults(float Amount, clsCurrency & Currency1, clsCurrency & Currency2)
	{
		cout << "\nconvert From:\n\n";
		_PrintCurrencyCard(Currency1);

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting From Usd To:\n\n";
		_PrintCurrencyCard(Currency2);

		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';
		do
		{
			system("cls");
			_DrawScreenHeader("    Currency Calculator Screen");

			clsCurrency SrcCurrency = _GetCurrency("From");
			clsCurrency desCurrency = _GetCurrency("To");
			float Amount = _ReadAmount();
			float ConvertResult;

			_PrintCalculationsResults(Amount, SrcCurrency, desCurrency);

			cout << "\n\nDo you want to perform another calculation? y/n? ";
			cin >> Continue;
		} while (tolower(Continue) == 'y');

	}
};

