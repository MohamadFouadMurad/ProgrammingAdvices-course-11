#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsTransferScreen : protected clsScreen
{
    // My Way
    /*
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient is not Found, Choose Another one:";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

public:

	static void ShowTransferScreen()
	{

        _DrawScreenHeader("\t   Transfer Screen");

        string ClientNumber1;
        cout << "\nPlease enter Account Number to Transfer From: ";
        ClientNumber1 = _ReadAccountNumber();

        clsBankClient Client1 = clsBankClient::Find(ClientNumber1);
        _PrintClient(Client1);

        string ClientNumber2;
        cout << "\nPlease enter Account Number to Transfer To: ";
        ClientNumber2 = _ReadAccountNumber();

        while (ClientNumber1 == ClientNumber2)
        {
            cout << "\n you enter the same Account Number For two Accounts , pls enter a new Acc. Number:";
            ClientNumber2 = _ReadAccountNumber();
        }

        clsBankClient Client2 = clsBankClient::Find(ClientNumber2);
        _PrintClient(Client2);

        double Amount = 0;
        cout << "\nEnter Transfer amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > Client1.AccountBalance)
        {
            cout << "\nAmount exceeds the available Balance, Enter another Amount :";
            Amount = clsInputValidate::ReadDblNumber();
        }

        cout << "\nAre you sure you want to perform this transaction? Y/n?";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Client1.Withdraw(Amount);
            Client2.Deposit(Amount);

            cout << "\nTransfer done successfully\n\n";

            _PrintClient(Client1);
            _PrintClient(Client2);
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
	}
    */

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }


public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());


        while (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
        {
            cout << "\nYou cannot transfer to the same account!";
            clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
        }


        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);


    }

};

