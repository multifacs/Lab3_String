#include<iostream>
#pragma warning(disable:4996)
using namespace std;

class MuString
{
public:

	//конструктор без параметров
	MuString();
	MuString(const char* str);
	~MuString();
	MuString(const MuString& other);

	MuString& operator =(const MuString& other);
	MuString operator +(const MuString& other);

	int Length();
	char* Str();

	bool operator ==(const MuString& other);
	bool operator !=(const MuString& other);
	char& operator [](int index);

	friend bool operator <(MuString& a, MuString& b);
	friend bool operator >(MuString& a, MuString& b);

	friend ostream& operator <<(ostream& out, MuString& a);
	friend istream& operator >>(istream& in, MuString& b);

	MuString(MuString&& other) noexcept;

	int find(const char* e);
	MuString* Tstrtok(const char* c);

private:
	// ”казатель на массив char, хранит символы, которые мы передали в наш объект.
	char* str;
	int length;
};