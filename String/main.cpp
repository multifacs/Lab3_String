#include<iostream>
#include "MuString.h"
#pragma warning(disable:4996)


int main()
{
	setlocale(LC_ALL, "ru");

	MuString str("Hello");
	MuString str2("World");

	cout << "The lenght of " << "'" << str << "'" << " is: " << str.Length() << endl;
	cout << "The char array of " << "'" << str2 << "'" << " is: " << str.Str() << endl << endl;

	MuString result;
	result = str + str2;

	cout << result << endl;

	if (str == str2)
		cout << "'" << str << "'" << " is equal to " << "'" << str2 << "'" << endl;
	else
		cout << str << " isn't equal to " << "'" << str2 << "'" << endl << endl;

	cout << "Type in a string: " << endl;

	MuString x;
	cin >> x; //default: a_b_c

	if (x.find("b") != NULL)
		cout << "The character 'b' is at position " << x.find("b") << endl;
	else
		cout << "The character 'b' is absent" << endl;

	if (x.find("_c") != NULL)
		cout << "The substring '_c' is at position " << x.find("b") << endl;
	else
		cout << "The substring '_c' is absent" << endl;

	MuString* arr;
	arr = x.Tstrtok("_");

	cout << "Division of " << "'" << x << "'" << " by '_':" << endl;

	for (int i = 0; i < sizeof(arr) - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}