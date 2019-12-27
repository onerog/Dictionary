
#include "Dictionary.h"
#include <string>

int main() {
	Person* per1 = new Person("Sarah", 1,4,1990);
	Person* per2 = new Person("Michael", 3, 6, 1980);
	Person* per3 = new Person("Johnny", 1, 1, 2008);
	Person* per4 = new Person("Alev", 3, 4, 1970);
	Person* per5 = new Person("Alex", 8, 6, 1985);
	Person* per6 = new Person("Fiona", 3, 1, 2004);

	Dictionary* dict = new Dictionary();
	cout << "Testing empty dictionary remove method: " << endl;
	dict->removeEntry("Sarah");	//empty dictionary
	cout << "Testing remove in dictionary that doesn't contain the element: " << endl;
	dict->addEntry(per1->getName(), per1); 
	dict->removeEntry("Michael"); //remove entry that's not in the dictionary
	cout << endl;
	cout << "Filling list and trying to add more than capacity" << endl;
	dict->addEntry(per2->getName(), per2);
	dict->addEntry(per6->getName(), per6);
	dict->addEntry(per5->getName(), per5);
	dict->addEntry(per4->getName(), per4);
	dict->addEntry(per6->getName(), per6);
	cout << endl;
	cout << "Testing get birthday by name: " << endl;
	dict->removeEntry("Alev");
	cout << "Birthday for key \"Fiona\" " << dict->getBirthday("Fiona") << endl;
	cout << "Birthday for key \"Sarah\" " << dict->getBirthday("Sarah") << endl;
	cout << "Birthday for key \"JACK\" " << dict->getBirthday("JACK") << endl; //element doesn't exist
	cout << endl;
	cout << "Testing display all entries " << endl ;
	dict->displayAllEntries();
	cout << endl;
	cout << "Testing get by birth month " << endl;
	dict->getByBirthMonth(3);
	dict->getByBirthMonth(1);
	dict->getByBirthMonth(12);



	return 0;
}