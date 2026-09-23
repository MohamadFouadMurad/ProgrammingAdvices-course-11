#include <iostream>
#include "../clsBankClient.h"
#include "../clsInputValidate.h"
using namespace std;


void DeleteClient()
{
    string AccountNumber = "";

    cout << "\npls enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\n Account Number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n Are you sure you want to delete this client y/n? ";
    char answer = 'n';
    cin >> answer;

    if (answer == tolower('y'))
    {
        if (Client1.Delete())
        {
            cout << "\n Client Deleted successfully :-)\n";

            Client1.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }
}

int main()
{
    DeleteClient();
    system("pause>0");
    return 0;
}