#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>


using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{

private:

	static void _PrintCurrenciesRecordLine(clsCurrency Currencies)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currencies.Country();
		cout << "| " << setw(8) << left << Currencies.CurrencyCode();
		cout << "| " << setw(45) << left << Currencies.CurrencyName();
		cout << "| " << setw(10) << left << Currencies.Rate();
	}

public:

	static void ShowCurrenciesListScreen()
	{
		system("cls");

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "    Currencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else

			for (clsCurrency & Currency : vCurrencies)
			{

				_PrintCurrenciesRecordLine(Currency);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

