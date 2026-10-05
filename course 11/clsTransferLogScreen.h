#pragma once

#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsInputValidate.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{

private:

    static void _PrintTransferLogLine(clsBankClient::stTransferLog & TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.sAcc;
        cout << "| " << setw(8) << left << TransferLog.dAcc;
        cout << "| " << setw(8) << left << TransferLog.amount;
        cout << "| " << setw(10) << left << TransferLog.sBalance;
        cout << "| " << setw(10) << left << TransferLog.dBalance;
        cout << "| " << setw(8) << left << TransferLog.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLog> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acc";
        cout << "| " << left << setw(8) << "d.Acc";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Logs Available In the System!";
        else
            for (clsBankClient::stTransferLog & Record : vTransferLogRecord)
            {

                _PrintTransferLogLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

