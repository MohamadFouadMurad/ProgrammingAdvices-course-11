#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
	short _Day = 0;
	short _Month = 0;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	clsDate(string Date)
	{
		vector <string> vDate = clsString::Split(Date, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(int Day, int Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	static bool IsLeapYear(short year)
	{
		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short GetTotalDaysInMonth(short year, short month)
	{
		short DaysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (month == 2 && IsLeapYear(year)) ? 29 : DaysInMonths[month];
	}

	short GetTotalDaysInMonth()
	{
		return GetTotalDaysInMonth(_Year, _Month);
	}

	static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short year)
	{
		short DaysInCurrentMonth = 0;
		for (short Month = 1; Month <= 12; Month++)
		{
			DaysInCurrentMonth = GetTotalDaysInMonth(year, Month);

			if (DayOrderInYear <= DaysInCurrentMonth)
			{
				return { DayOrderInYear, Month, year };
			}

			DayOrderInYear -= DaysInCurrentMonth;
		}
		return { 0, 0, year };
	}

	clsDate GetDateFromDayOrderInYear(short DayOrderInYear)
	{
		return GetDateFromDayOrderInYear(DayOrderInYear, _Year);
	}

	clsDate(short DateOrderInYear, short Year)
	{
		*this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short getDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
		cout << endl;
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	void Print()
	{
		cout << DateToString() << endl;
	}

	static short GetTotalDaysInYear(short year)
	{
		return IsLeapYear(year) ? 366 : 365;
	}

	short GetTotalDaysInYear()
	{
		return	GetTotalDaysInYear(_Year);
	}

	static int GetTotalHoursInYear(short year)
	{
		return GetTotalDaysInYear(year) * 24;
	}

	int GetTotalHoursInYear()
	{
		return	GetTotalHoursInYear(_Year);
	}

	static long GetTotalMinutesInYear(short year)
	{
		return GetTotalHoursInYear(year) * 60;
	}

	long GetTotalMinutesInYear()
	{
		return	GetTotalMinutesInYear(_Year);
	}

	static long long GetTotalSecondsInYear(short year)
	{
		return GetTotalMinutesInYear(year) * 60;
	}

	long long GetTotalSecondsInYear()
	{
		return	GetTotalSecondsInYear(_Year);
	}

	static int GetTotalHoursInMonth(short year, short month)
	{
		return GetTotalDaysInMonth(year, month) * 24;
	}

	int GetTotalHoursInMonth()
	{
		return GetTotalHoursInMonth(_Year, _Month);
	}

	static int GetTotalMinutesInMonth(short year, short month)
	{
		return GetTotalHoursInMonth(year, month) * 60;
	}

	int GetTotalMinutesInMonth()
	{
		return GetTotalMinutesInMonth(_Year, _Month);
	}

	static int GetTotalSecondsInMonth(short year, short month)
	{
		return GetTotalMinutesInMonth(year, month) * 60;
	}

	int GetTotalSecondsInMonth()
	{
		return GetTotalSecondsInMonth(_Year, _Month);
	}

	static short GetDayOfWeekOrder(short year, short month, short day = 1)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short GetDayOfWeekOrder()
	{
		return GetDayOfWeekOrder(_Year, _Month, _Day);
	}

	static string GetWeekDayName(short DayOfWeekOrder)
	{
		string arrWeekDaysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrWeekDaysName[DayOfWeekOrder];
	}

	string GetWeekDayName()
	{
		return GetWeekDayName(GetDayOfWeekOrder());
	}

	static string GetMonthShortName(short Month)
	{
		string Months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return Months[Month];
	}

	string GetMonthShortName()
	{
		return GetMonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays = GetTotalDaysInMonth(Year, Month);
		int current = GetDayOfWeekOrder(Year, Month, 1);

		printf("\n  _______________%s_______________\n\n", GetMonthShortName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(int Year)
	{
		printf("\n  ---------------------------------\n");
		printf("           Calendar - %d           \n", Year);
		printf("  ---------------------------------\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short GetNumberOfDaysFromTheBeginingOfTheYear(clsDate Date)
	{
		short TotalDays = 0;
		for (short i = 1; i < Date._Month; i++)
		{
			TotalDays += GetTotalDaysInMonth(Date._Year, i);
		}
		return TotalDays + Date._Day;
	}

	short GetNumberOfDaysFromTheBeginingOfTheYear()
	{
		return GetNumberOfDaysFromTheBeginingOfTheYear(*this);
	}

	static bool IsValid(clsDate Date)
	{
		if (Date._Month < 1 || Date._Month > 12)
			return false;

		short DaysInMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day < 1 || Date._Day > DaysInMonth)
			return false;

		return true;
	}

	bool IsValid()
	{
		return	IsValid(*this);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == GetTotalDaysInMonth(Date._Year, Date._Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true :
			(Date1._Year == Date2._Year) ? ((Date1._Month < Date2._Month) ? true :
				(Date1._Month == Date2._Month) ? (Date1._Day < Date2._Day) : false)
			: false;
	}

	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return ((Date1._Year == Date2._Year) && (Date1._Month == Date2._Month) && (Date1._Day == Date2._Day));
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static clsDate IncreaseDateByOneDay(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			Date._Day = 1;
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}

	void IncreaseDateByOneDay()
	{
		IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseDateByXDays(clsDate& Date, short DaysToAdd)
	{
		for (short i = 1; i <= DaysToAdd; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short DaysToAdd)
	{
		IncreaseDateByXDays(*this, DaysToAdd);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate& Date, short WeeksToAdd)
	{
		for (short i = 1; i <= WeeksToAdd; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short WeeksToAdd)
	{
		IncreaseDateByXWeeks(*this, WeeksToAdd);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate& Date, short MonthsToAdd)
	{
		for (short i = 1; i <= MonthsToAdd; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short MonthsToAdd)
	{
		IncreaseDateByXMonths(*this, MonthsToAdd);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate& Date, short YearsToAdd)
	{
		for (short i = 1; i <= YearsToAdd; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	void IncreaseDateByXYears(short YearsToAdd)
	{
		IncreaseDateByXYears(*this, YearsToAdd);
	}

	static clsDate IncreaseDateByXYearsFaster(clsDate& Date, short YearsToAdd)
	{
		Date._Year += YearsToAdd;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void IncreaseDateByXYearsFaster(short YearsToAdd)
	{
		IncreaseDateByXYearsFaster(*this, YearsToAdd);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		return IncreaseDateByXYearsFaster(Date, 10);
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate& Date, short DecadesToAdd)
	{
		for (short i = 1; i <= DecadesToAdd; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}
		return Date;
	}

	void IncreaseDateByXDecades(short DecadesToAdd)
	{
		IncreaseDateByXDecades(*this, DecadesToAdd);
	}

	static  clsDate IncreaseDateByXDecadesFaster(clsDate& Date, short DecadesToAdd)
	{
		Date._Year += DecadesToAdd * 10;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void IncreaseDateByXDecadesFaster(short DecadesToAdd)
	{
		IncreaseDateByXDecadesFaster(*this, DecadesToAdd);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		return IncreaseDateByXDecadesFaster(Date, 10);
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByXCenturiesFaster(clsDate& Date, short CenturiesToAdd)
	{
		Date._Year += CenturiesToAdd * 100;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void IncreaseDateByXCenturiesFaster(short CenturiesToAdd)
	{
		IncreaseDateByXCenturiesFaster(*this, CenturiesToAdd);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		return IncreaseDateByXCenturiesFaster(Date, 10);
	}

	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}


	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
			}
			Date._Day = GetTotalDaysInMonth(Date._Year, Date._Month);
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, short DaysToRemove)
	{
		for (short i = 1; i <= DaysToRemove; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short DaysToRemove)
	{
		DecreaseDateByXDays(*this, DaysToRemove);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, short WeeksToRemove)
	{
		for (short i = 1; i <= WeeksToRemove; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short WeeksToRemove)
	{
		DecreaseDateByXWeeks(*this, WeeksToRemove);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}

		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate& Date, short MonthsToRemove)
	{
		for (short i = 1; i <= MonthsToRemove; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short MonthsToRemove)
	{
		DecreaseDateByXMonths(*this, MonthsToRemove);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date._Year--;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate& Date, short YearsToRemove)
	{
		for (short i = 1; i <= YearsToRemove; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXYears(short YearsToRemove)
	{
		DecreaseDateByXYears(*this, YearsToRemove);
	}

	static clsDate DecreaseDateByXYearsFaster(clsDate& Date, short YearsToRemove)
	{
		Date._Year -= YearsToRemove;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void  DecreaseDateByXYearsFaster(short YearsToRemove)
	{
		DecreaseDateByXYearsFaster(*this, YearsToRemove);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		return DecreaseDateByXYearsFaster(Date, 10);
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate& Date, short DecadesToRemove)
	{
		for (short i = 1; i <= DecadesToRemove; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}

	void DecreaseDateByXDecades(short DecadesToRemove)
	{
		DecreaseDateByXDecades(*this, DecadesToRemove);
	}

	static clsDate DecreaseDateByXDecadesFaster(clsDate& Date, short DecadesToRemove)
	{
		Date._Year -= DecadesToRemove * 10;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByXDecadesFaster(short DecadesToRemove)
	{
		DecreaseDateByXDecadesFaster(*this, DecadesToRemove);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		return DecreaseDateByXDecadesFaster(Date, 10);
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByXCenturiesFaster(clsDate& Date, short CenturiesToRemove)
	{
		Date._Year -= CenturiesToRemove * 100;
		short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByXCenturiesFaster(short CenturiesToRemove)
	{
		DecreaseDateByXCenturiesFaster(*this, CenturiesToRemove);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		return DecreaseDateByXCenturiesFaster(Date, 10);
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static short GetDayOfWeekOrder(clsDate Date)
	{
		return GetDayOfWeekOrder(Date._Year, Date._Month, Date._Day);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return GetDayOfWeekOrder(Date) == 6;
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayOfWeekOrder = GetDayOfWeekOrder(Date);
		return (DayOfWeekOrder == 5 || DayOfWeekOrder == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short GetDaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - GetDayOfWeekOrder(Date);
	}

	short GetDaysUntilEndOfWeek()
	{
		return GetDaysUntilEndOfWeek(*this);
	}

	static void SwapTwoDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	void SwapTwoDates(clsDate& Date2)
	{
		SwapTwoDates(*this, Date2);
	}

	static int GetDiffInDaysBetWeenTwoDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		short SwapFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2))
		{
			SwapTwoDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		int DaysDiff = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DaysDiff++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? (DaysDiff + 1) * SwapFlagValue : DaysDiff * SwapFlagValue;
	}

	int GetDiffInDaysBetWeenTwoDates(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDiffInDaysBetWeenTwoDates(*this, Date2, IncludeEndDay);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDiffInDaysBetWeenTwoDates(DateOfBirth, clsDate(), true);
	}

	static short GetDaysUntilEndOfMonth(clsDate Date)
	{
		return GetTotalDaysInMonth(Date._Year, Date._Month) - Date._Day;
	}

	short GetDaysUntilEndOfMonth()
	{
		return GetDaysUntilEndOfMonth(*this);
	}

	static short GetDaysUntilEndOfYear(clsDate Date)
	{
		return GetTotalDaysInYear(Date._Year) - GetNumberOfDaysFromTheBeginingOfTheYear(Date);
	}

	short GetDaysUntilEndOfYear()
	{
		return GetDaysUntilEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return Days;
	}

	short CalculateBusinessDays(clsDate DateTo)
	{
		return CalculateBusinessDays(*this, DateTo);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (VacationDays > 0)
		{
			if (IsBusinessDay(DateFrom))
				VacationDays--;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}
};



