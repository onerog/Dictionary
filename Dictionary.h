#pragma once
#include <iostream>
#include "Person.h"

#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary
{
private:
    const Person* AVAILABLE = new Person{" ", 0, 0, 0 }; //TO REPLACE REMOVED ITEMS;
	static const int DEFAULT_SIZE = 5;
	Person **personTable; //pointer to pointer array
	int itemCount;
	
public:
	int getPosition(string key);
	Dictionary();
	~Dictionary();
	bool addEntry(string name, Person* personToAdd);
	bool removeEntry(string name) ;
	string getBirthday(string name) ;
	void displayAllEntries() const;
	void getByBirthMonth(int month);
};


#endif // !DICTIONARY_H

