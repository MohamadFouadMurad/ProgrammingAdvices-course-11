#include <iostream>
using namespace std;


template <class T> class Calculator
{
private:
	T Number1, Number2;

	public:

		Calculator(T n1, T n2)
		{
			Number1 = n1;
			Number2 = n2;
		}

		void PrintResults()
		{
			cout << "Numbers: " << Number1 << " and " << Number2 << "." << endl;

			cout << Number1 << " + " << Number2 << " = " << Add() << endl;

			cout << Number1 << " - " << Number2 << " = " << Subtract() << endl;

			cout << Number1 << " * " << Number2 << " = " << Multiply() << endl;

			cout << Number1 << " / " << Number2 << " = " << Divide() << endl;
		}

		T Add()
		{
			return Number1 + Number2;
		}

		T Subtract()
		{
			return Number1 - Number2;
		}

		T Multiply()
		{
			return Number1 * Number2;
		}

		T Divide()
		{
			return Number1 / Number2;
		}
	
};


int main()
{
	Calculator<int> intCalc(2, 1);
	Calculator<float> floatCalc(2.4, 1.2);

	cout << "int Results:" << endl;
	intCalc.PrintResults();

	cout << endl;

	cout << "float Results:" << endl;
	floatCalc.PrintResults();
}