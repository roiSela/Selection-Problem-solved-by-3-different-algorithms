#pragma once
#include <iostream>
using namespace std;

class Name2
{
private:
	char* name;
	int name_len;
	bool Enter;
public:
	Name2();
	Name2(const Name2& other);
	//Name2(const char* str);
	~Name2();
	void operator=(const Name2& other);
	//void operator=(const char* str);
	void readName();

	friend ostream& operator<<(ostream& os, const Name2& c) {
		os << c.name;
		return os;
	}

	char* getName() const;
	void setName(char* name);

	int getNamelen() const;
	void setNamelen(int namelen);
	bool getEnter() { return Enter; }

};