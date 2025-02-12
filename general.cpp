#include "general.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Object::Object() {
	id=++count;
	cout << "Object just created!" << endl;
}

Object::~Object() {
	id=--count;
	cout << "Object to be destroyed!" << endl;
}

int Object::count =  0;

int Object::getId() const{
	return id;
}

bool Object::identical(Object& ob) {
	if (this == &ob)
		return true;
	return false;
}

String Object::toString() {
	String temp(" id " + to_string(this->id) + "\n");

	return temp;
}

void Object::setId(int idd){
	id = idd;
}

String::String(string inMyString):
	myString(inMyString){
		cout<<"String just created!"<<endl;
}

String::~String() {
	cout<<"String to be destroyed!"<<endl;
}

bool String::equal(Object *ob){
	if((this->getId() == ob->getId()) && (this->myString == dynamic_cast<String*>(ob)->getMyString()))
		return true;
	return false;
}

int String::length() {
	return myString.length();
}

void String::clear() {
	myString.clear();
}

void String::concat(const String &str){
	this->myString += str.myString;			//Operator +
}

char String::at(int i){
	if(i<0 || i>myString.length()-1){
		cout<<"Wrong input"<<endl;
		exit(0);
	}
	return myString.at(i);
}

void String::updateAt(int i,char ch){
	myString.replace(i,1,1,ch);
}

void String::print() {
	cout<<myString<<endl;
}

string String::getMyString()const{
	return myString;
}

Object *String::clone(){
	String *temp = new String();

	temp->setId(this->getId());
	temp->myString = this->myString;
	return temp;
}
