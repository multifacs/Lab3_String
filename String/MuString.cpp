#include "MuString.h"

	MuString::MuString()
	{
		str = nullptr;
		length = 0;
	}

	MuString::MuString(const char* str)
	{

		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}
	MuString::~MuString()
	{
		if (str != NULL)
			delete[] this->str;
	}

	MuString::MuString(const MuString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	MuString& MuString::operator =(const MuString& other)
	{
		if (&other == this)
			return *this;

		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;

	}

	MuString MuString::operator+(const MuString& other)
	{
		MuString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;
	}

	int MuString::Length()
	{
		return length;
	}

	char* MuString::Str()
	{
		return str;
	}

	bool MuString::operator ==(const MuString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool MuString::operator !=(const MuString& other)
	{
		return !(this->operator==(other));
	}

	bool operator <(MuString& a, MuString& b) {
		return(strcmp(a.str, b.str) < 0);
	}

	bool operator >(MuString& a, MuString& b) {
		return(strcmp(a.str, b.str) > 0);
	}

	char& MuString::operator [](const int index) {
		if (index < 0 || index >= length)
			throw "yikes";
		else
			return str[index];
	}

	ostream& operator <<(ostream& out, MuString& a) {
		for (int i = 0; i < a.length; i++) {
			out << a.str[i];
		}

		return out;
	}

	istream& operator >> (istream& in, MuString& b) {
		char t[256];
		in.getline(t, 256);
		MuString e(t);
		b = e;
		return in;
	}

	MuString::MuString(MuString&& other) noexcept
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	int MuString::find(const char* e) {
		char* t = strstr(str, e);
		if (t != NULL)
			return t - str + 1;
		else
			return NULL;
	}

	MuString* MuString::Tstrtok(const char* c) {
		int count = 0;

		MuString tmp = str;

		char* istr = strtok(tmp.str, c);
		while (istr != NULL)
		{
			count += 1;
			istr = strtok(NULL, c);
		}

		tmp = str;

		MuString* result = new MuString[count];

		count = 0;

		istr = strtok(tmp.str, c);
		while (istr != NULL)
		{
			result[count] = istr;
			count += 1;
			istr = strtok(NULL, c);
		}

		return result;
	}
