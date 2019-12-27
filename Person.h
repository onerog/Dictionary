#pragma once
#include<iostream>
#include<string>

using namespace std;

#ifndef PERSON_H
#define PERSON_H



class Person
{
private:
	string name;
	int birthYear;
	int birthDay;
	int birthMonth;

public:
	
	Person(string newName, int newMonth, int newDay, int newYear);
	void setName(string newName);
	string getName();
	void setDOB(int month, int day, int year);
	string getDOB();
	int getBirthMonth();

};


#endif // !PERSON_H
