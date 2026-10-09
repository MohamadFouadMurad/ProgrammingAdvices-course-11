#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>

using namespace std;

class clsInputValidate
{

public:

	template <typename T> 
	static bool IsNumberBetween(T Number, T From, T To)
	{
		if (From > To)
		{
			return (Number >= To && Number <= From);
		}

		return (Number >= From && Number <= To);
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

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Error , pls enter a another number?\n")
	{
		T Number=0;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			cin >> Number;
		}

		return Number;
	}
	
	template <typename T> 
	static T ReadNumberBetween(T From,T To, string Message)
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message << endl;
			Number = ReadNumber<T>();
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