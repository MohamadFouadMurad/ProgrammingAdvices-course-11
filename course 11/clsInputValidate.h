#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>

using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}

		return false;
	}

	static bool IsNumberBetween(short Number,short From,short To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}

		return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}

		return false;
	}

	static bool IsNumberBetween(double Number,double From,double To)
	{
		if (Number >= From && Number <= To)
		{
			return true;
		}

		return false;
	}

	static bool IsDateBetween(clsDate DateNow, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1AfterDate2(From,To))
		{
			clsDate::SwapTwoDates(From, To);
		}

		bool isAfterOrEqualFrom = clsDate::IsDate1AfterDate2(DateNow, From) || clsDate::IsDate1EqualDate2(DateNow, From);
		bool isBeforeOrEqualTo = clsDate::IsDate1BeforeDate2(DateNow, To) || clsDate::IsDate1EqualDate2(DateNow, To);

		return (isAfterOrEqualFrom && isBeforeOrEqualTo);
	}

	static int ReadIntNumber(string Message)
	{
		int Number=0;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Message)
	{
		int Number = ReadIntNumber("Invalid Number, Enter Again\n");

		while (!IsNumberBetween(Number,From,To))
		{
			cout << Message << endl;
			Number = ReadIntNumber("Invalid Number, Enter Again\n");
		}

		return Number;
	}

	static double ReadDblNumber(string Message)
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Message)
	{
		double Number = ReadDblNumber("Invalid Number, Enter Again\n");

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message << endl;
			Number = ReadDblNumber("Invalid Number, Enter Again\n");
		}

		return Number;
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValid(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};