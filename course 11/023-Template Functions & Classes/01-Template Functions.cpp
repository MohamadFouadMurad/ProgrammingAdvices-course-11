#include <iostream>
using namespace std;


template <typename T> T MyMax(T Number1, T Number2)
{
	return (Number1 > Number2) ? Number1 : Number2;
}

int main()
{
	cout << MyMax<int>(3, 7) << endl;

	cout << MyMax<double>(5.3, 4.2) << endl;

	cout << MyMax<char>('a', 'b') << endl;

	return 0;
}