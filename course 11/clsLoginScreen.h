#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short counter = 3;

		string UserName, Password;

		do
		{
			cout << "Enter UserName?";
			cin >> UserName;

			cout << "Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

				if (LoginFaild)
				{
					counter--;
					cout << "\nInvalid UserName/Password\n";
					cout << "You have " << counter << " Trails to login.\n\n";

					if (counter == 0)
					{
						cout << "you are locked after 3 faild trails." << endl;
						return false;
					}
				}

		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};