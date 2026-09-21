#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static short CountWord(string S1)
	{
		string delim = " ";
		short counter = 0;
		short pos = 0;
		string word = "";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			word = S1.substr(0, pos);

			if (word != "")
			{
				counter++;
			}

			S1.erase(0, pos + delim.length());

		}

		if (S1 != "")
		{
			counter++;
		}

		return counter;
	}

	short CountWord()
	{
		return CountWord(_Value);
	}

	static bool IsVowel(char Letter)
	{

		Letter = tolower(Letter);

		return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
	}

	static char InvertLetterCase(char Charcter)
	{

		return (islower(Charcter) ? toupper(Charcter) : tolower(Charcter));
	}

	static string InvertTextCase(string text)
	{

		for (short i = 0; i < text.length(); i++)
		{
			text[i] = InvertLetterCase(text[i]);
		}

		return text;
	}

	void InvertTextCase()
	{
		_Value = InvertTextCase(_Value);
	}

	static string UpperFirstLetterFromEachWord(string text)
	{

		bool FirstLetter = true;

		for (short i = 0; i < text.length(); i++)
		{

			if (text[i] != ' ' && FirstLetter)
			{

				text[i] = toupper(text[i]);
			}

			FirstLetter = (text[i] == ' ' ? true : false);
		}

		return text;
	}

	void UpperFirstLetterFromEachWord()
	{
		_Value = UpperFirstLetterFromEachWord(_Value);
	}

	static string LowerFirstLetterFromEachWord(string text)
	{

		bool FirstLetter = true;

		for (short i = 0; i < text.length(); i++)
		{

			if (text[i] != ' ' && FirstLetter)
			{

				text[i] = tolower(text[i]);
			}

			FirstLetter = (text[i] == ' ' ? true : false);
		}

		return text;
	}

	void LowerFirstLetterFromEachWord()
	{
		_Value = LowerFirstLetterFromEachWord(_Value);
	}

	static string LowerAllString(string text)
	{

		for (short i = 0; i < text.length(); i++)
		{

			text[i] = tolower(text[i]);
		}

		return text;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static string UpperAllString(string text)
	{

		for (short i = 0; i < text.length(); i++)
		{

			text[i] = toupper(text[i]);
		}

		return text;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static short CountSmallLetters(string text)
	{

		short Counter = 0;

		for (short i = 0; i < text.length(); i++)
		{

			if (islower(text[i]))
			{

				Counter++;
			}
		}

		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountCaptialLetters(string text)
	{

		short Counter = 0;

		for (short i = 0; i < text.length(); i++)
		{

			if (isupper(text[i]))
			{

				Counter++;
			}
		}

		return Counter;
	}

	short CountCaptialLetters()
	{
		return CountCaptialLetters(_Value);
	}

	enum enWhatToCount
	{
		SmallLetters = 0, CaptialLetters = 1, Comma = 2, AllLetters = 3
	};

	static short CountLetters(string text, enWhatToCount WhatToCount = enWhatToCount::AllLetters)
	{

		if (WhatToCount == enWhatToCount::AllLetters)
			return text.length();

		short Counter = 0;

		for (short i = 0; i < text.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CaptialLetters && isupper(text[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(text[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::Comma && text[i] == ',')  // added by me
				Counter++;
		}

		return Counter;
	}

	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::AllLetters)
	{
		return CountLetters(_Value, WhatToCount);
	}

	static short CountLetter(string text, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < text.length(); i++)
		{

			if (MatchCase) {

				if (text[i] == Letter)
					Counter++;
			}
			else
			{

				if (tolower(Letter) == tolower(text[i]))
					Counter++;
			}
		}

		return Counter;
	}

	short CountLetter(char Letter, bool MatchCase = true)
	{
		return CountLetter(_Value, Letter, MatchCase);
	}

	short CountLetterAllCases(char Letter)
	{
		return CountLetter(_Value, Letter, false);
	}

	static short CountVowels(string text)
	{

		short Counter = 0;

		for (short i = 0; i < text.length(); i++)
		{

			if (IsVowel(text[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static string RemoveAllPunctations(string text)
	{

		string Result = "";

		for (short i = 0; i < text.length(); i++)
		{

			if (!ispunct(text[i]))
			{

				Result += text[i];
			}
		}

		return Result;
	}

	void RemoveAllPunctations()
	{
		_Value = RemoveAllPunctations(_Value);
	}

	static string TrimLeft(string text)
	{

		for (short i = 0; i < text.length(); i++)
		{

			if (text[i] != ' ')
			{

				return text.substr(i, text.length() - 1);
			}
		}

		return text;
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string text)
	{

		for (short i = text.length() - 1; i >= 0; i--)
		{

			if (text[i] != ' ')
			{

				return text.substr(0, i + 1);
			}
		}

		return text;
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string text)
	{

		return TrimLeft(TrimRight(text));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}

	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string JoinString(vector <string>& Words, string delim = " ")
	{

		string text = "";

		for (string& word : Words)
		{

			text += word + delim;
		}

		return text.substr(0, text.length() - delim.length());
	}

	static string JoinString(string arr[], short Length, string delim = " ")
	{

		string text = "";

		for (short i = 0; i < Length; i++)
		{

			text += arr[i] + delim;
		}

		return text.substr(0, text.length() - delim.length());
	}

	static string ReplaceWordsInStringUsingBuiltInFunctions(string text, string WordToReplace, string Word)
	{

		short pos = text.find(WordToReplace);

		while (pos != std::string::npos)
		{

			text.replace(pos, WordToReplace.length(), Word);

			pos = text.find(WordToReplace);
		}

		return text;
	}

	void ReplaceWordsInStringUsingBuiltInFunctions(string WordToReplace, string Word)
	{
		_Value = ReplaceWordsInString(_Value, WordToReplace, Word);
	}

	static string ReplaceWordsInString(string text, string WordToReplace, string Word, bool MatchCase = true)
	{

		string text2 = text;

		if (!MatchCase)
		{

			text = LowerAllString(text);
			WordToReplace = LowerAllString(WordToReplace);
		}

		short Pos = text.find(WordToReplace);

		while (Pos != std::string::npos)
		{

			text2.erase(Pos, WordToReplace.length());
			text2.insert(Pos, Word);
			text.erase(Pos, WordToReplace.length());
			text.insert(Pos, Word);
			Pos = text.find(WordToReplace);

		}

		return text2;
	}

	void ReplaceWordsInString(string WordToReplace, string Word, bool MatchCase = true)
	{
		_Value = ReplaceWordsInString(_Value, WordToReplace, Word, MatchCase);
	}

	string ReplaceWord(string WordToReplace, string Word, bool MatchCase = true)
	{
		_Value = ReplaceWordsInString(_Value, WordToReplace, Word, MatchCase);
		return _Value;
	}

	static string ReplaceWordsInStringUsingSplitFunction(string text, string WordToReplace, string Word, bool MatchCase = true)
	{

		vector <string> Words = Split(text, " ");

		for (string& s : Words)
		{

			if (MatchCase)
			{

				if (s == WordToReplace)
				{

					s = Word;
				}
			}
			else
			{

				if (LowerAllString(s) == LowerAllString(WordToReplace))
				{

					s = Word;
				}
			}
		}

		return JoinString(Words, " ");
	}

	void ReplaceWordsInStringUsingSplitFunction(string WordToReplace, string Word, bool MatchCase = true)
	{
		_Value = ReplaceWordsInStringUsingSplitFunction(_Value, WordToReplace, Word, MatchCase);
	}

	static void PrintFirstLetterOfEachWord(string text)
	{

		bool FirstLetter = true;

		for (short i = 0; i < text.length(); i++)
		{

			if (text[i] != ' ' && FirstLetter)
			{

				cout << text[i] << endl;
			}

			FirstLetter = (text[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static void PrintAllVowelsInText(string text)
	{

		cout << "Vowels in text are : \n";
		for (short i = 0; i < text.length(); i++)
		{

			if (IsVowel(text[i]))
				cout << text[i] << "       ";

		}

		cout << endl;
	}

	void PrintAllVowelsInText()
	{
		PrintAllVowelsInText(_Value);
	}

	static void PrintWordsSInString(string text)
	{

		string delim = " ";
		short pos = 0;
		string word;

		while ((pos = text.find(delim)) != std::string::npos)
		{

			word = text.substr(0, pos);

			if (word != "")
			{

				cout << word << endl;
			}

			text.erase(0, pos + delim.length());
		}

		if (text != "")
			cout << word << endl;
	}

	void PrintWordsSInString()
	{
		PrintWordsSInString(_Value);
	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}



};


