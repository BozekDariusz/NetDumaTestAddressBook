#pragma once
#include <vector>
#include"UI.h"


class AddressBook
{

	std::vector<Person> contacts;

	void addPerson();
	void removePerson();
	void searchByFirstName();
	void searchByOtherNames();
	void searchByEmailAddress();
	void searchByTelephoneNumber();
	void searchByTown();
	void searchByCountry();
	void search();
	void wrongTypeOfInput();
	void exit();
	bool saveBook();
	Person getPerson();

public:

	AddressBook();
	AddressBook(std::vector<Person> newContacts );
	bool loadBook();
	void work();
};

