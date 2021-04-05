#include "Name2.h"

Name2::Name2() {
	this->name = nullptr;
	this->name_len = 0;
	Enter = false;
}

Name2::Name2(const Name2& other) {
	this->name_len = other.name_len;
	this->name = new char[this->name_len + 1];
	for (int i = 0; i <= this->name_len; i++) {
		this->name[i] = other.name[i];
	}
	Enter = false;
}


Name2::~Name2() {
	delete[] this->name;
}

void Name2::operator=(const Name2& other) {
	this->name_len = other.name_len;
	this->name = new char[this->name_len + 1];
	for (int i = 0; i <= this->name_len; i++) {
		this->name[i] = other.name[i];
	}
}


void Name2::readName() {

	delete[] name;//free memory if we used this variable before for another string 

	char* str, * temp, c;
	int phs = 2;
	int log = 0;
	str = new char[phs];

	c = getchar();
	while ( (c != '\n') && (c != ' ') && (c != '\t'))
	{
		str[log] = c;
		log++;

		if (log == phs)
		{
			phs *= 2;
			temp = new char[log];
			for (int i = 0; i < log; i++)
			{
				temp[i] = str[i];
			}
			delete[] str;
			str = new char[phs];
			for (int i = 0; i < log; i++)
			{
				str[i] = temp[i];
			}
			delete[]temp;
		}

		c = getchar();
		if (c =='\n')
		{
			Enter = true;
		}
	}

	temp = new char[log + 1];
	for (int i = 0; i < log; i++)
	{
		temp[i] = str[i];
	}
	delete[]str;
	temp[log] = 0;
	this->name_len = log;
	this->name = temp;
}
char* Name2::getName() const
{
	return name;
}

void Name2::setName(char* name)
{
	this->name = name;
}

int Name2::getNamelen() const
{
	return name_len;
}

void Name2::setNamelen(int namelen)
{
	name_len = namelen;
}

