#include "Person.h"
#include <iostream>


Person::Person(string newName, int newMonth, int newDay, int newYear)
{
	this->name = newName;
	this->birthMonth = newMonth;
	this->birthDay = newDay;
	this->birthYear = newYear;
}


string Person::getName(){
	return this->name;
}

void Person::setName(string newName) {
	this->name = newName;
}

string Person::getDOB(){
	string DOB =  to_string(birthMonth) +" "+ to_string(birthDay)+ " " + to_string(birthYear);
	return DOB;
}

void Person::setDOB(int month, int day, int year) {
	this->birthMonth = month;
	this->birthDay = day;
	this->birthYear = year;
}

int Person::getBirthMonth() {
	return birthMonth;
}