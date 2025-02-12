#ifndef GENERAL_H
#define GENERAL_H

#include <string>
using namespace std;

class String;

class Object
{
public:
	Object();
	virtual ~Object();
	int getId() const;
	virtual bool equal(Object *ob) = 0;
	bool identical(Object& ob2);
	virtual Object *clone() = 0;
	virtual String toString();
	void setId(int idd);

private:
	int id;
	static int count;
};


class String:public Object{
public:
	String(){}
	String(string inMyString);
	~String();
	bool equal(Object *ob);
	int length();
	void clear();
	void print();
	void concat(const String &str);
	char at(int i);
	void updateAt(int i,char ch);
	string getMyString()const;
	Object *clone();
private:
	string myString;
};

#endif
