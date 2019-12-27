#include "Dictionary.h"
#include <string>
#include <unordered_map>


Dictionary::Dictionary() {
	personTable = new Person *[DEFAULT_SIZE];	
	for (int i = 0; i < DEFAULT_SIZE; i++) { //initialize all table to null
		personTable[i] = NULL;
	}
	itemCount = 0;
}

Dictionary::~Dictionary() {
	for (int i = 0; i < DEFAULT_SIZE; i++) { 
		delete[] personTable[i]; 
		personTable = nullptr;
	}
}

int Dictionary::getPosition(string key) {
	int numValue = 0;
	for (int i = 0; i < key.size(); i++) {
		numValue += ((int)key[i]); //get int values of chars
	}
	return numValue % DEFAULT_SIZE;		//calculate index to put in the table
}

bool Dictionary::addEntry(string name,Person* personToAdd) {
	bool ableToAdd = (itemCount <= DEFAULT_SIZE);

	if (ableToAdd) {
		int positionToAdd = getPosition(name);
		int begin = positionToAdd;
		bool added = false;
		while(!added) {
			if (personTable[positionToAdd] == NULL || personTable[positionToAdd] == const_cast <Person*> (AVAILABLE)) {
				personTable[positionToAdd] = personToAdd;
				itemCount++;
				cout << personToAdd->getName() <<  " added to index: " << positionToAdd <<endl;
				return true;
			}
			else {
				positionToAdd++;
				positionToAdd = positionToAdd % DEFAULT_SIZE;

				if (begin == positionToAdd) {
					cout << "No space is available!" << endl;
					return false;
				}
			}



		}

	}
	return false;
}

bool Dictionary::removeEntry(string name)  {

	if (itemCount > 0) {
		int positionToRemove = getPosition(name);
		int begin = positionToRemove;
		bool removed = false;
		while(!removed) {
			if (personTable[positionToRemove] == NULL) {
				cout << "Element doesn't exist!" << endl;
				return false;
			} else if (personTable[positionToRemove]->getName() == name) {
				delete personTable[positionToRemove]; //delete person object to avoid memory leak;
				personTable[positionToRemove] = const_cast <Person*> (AVAILABLE);	//mark removed pointers- necessary for open adressing-linear probing
				itemCount--;
				return true;
			}
			else {
				positionToRemove++;
				positionToRemove = positionToRemove % DEFAULT_SIZE;
				if (begin == positionToRemove) {
					cout << "Searched all dictionary and Element doesn't exist!" << endl;
					return false;
				}
			}


		}
	}
	cout << "Dictionary is empty!" << endl;
	return false;
}

string Dictionary::getBirthday(string name) {

	if (itemCount > 0) {
		int positionToGet = getPosition(name);
		int begin = positionToGet;
		bool gotIt = false;
		while (!gotIt) {
			if (personTable[positionToGet] == NULL) {
				return "Element doesn't exist!";
			}
			else if (personTable[positionToGet]->getName() == name) {
				return personTable[positionToGet]->getDOB();
			}
			else {
				positionToGet++;
				positionToGet = positionToGet % DEFAULT_SIZE;
			}

			if (begin == positionToGet) {
				return "Searched all list and Element doesn't exist!";
			}
		}
	}
	return "Dictionary is empty!";
}

void Dictionary::displayAllEntries() const{
	for (int i = 0; i < DEFAULT_SIZE; i++) {
		if (personTable[i] != NULL && personTable[i] != const_cast <Person*> (AVAILABLE)) {
			cout << "NAME: " << personTable[i]->getName() << ", Date of Birth: " << personTable[i]->getDOB() << endl;
		}
	}
}

void Dictionary::getByBirthMonth(int month) {
	for (int i = 0; i < DEFAULT_SIZE; i++) {
		if (personTable[i] != NULL ) {
			if (personTable[i]->getBirthMonth() == month) {
				cout << "NAME: " << personTable[i]->getName() << " Date of Birth: " << personTable[i]->getDOB() << endl;
			}
		}
	}
}
