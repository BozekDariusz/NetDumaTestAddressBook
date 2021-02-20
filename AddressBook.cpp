#include "AddressBook.h"

void AddressBook::addPerson()
{
	Person person = getPerson();
	for (size_t i = 0; i < contacts.size(); i++) {//very slow but will work for now 
		if (contacts[i] == person) {
			return;
		}
	}
	contacts.push_back(person);
	work();
}

void AddressBook::removePerson()
{
	Person person = getPerson();
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i] == person) {
			contacts.erase(contacts.begin() + i);
			return;
		}
	}
	work();
}

void AddressBook::search()
{
	switch (UI::typeOfSearch()) {
	case UI::searchBy::FirstName:searchByFirstName();
		break;

	case UI::searchBy::OtherNames: searchByOtherNames();
		break;

	case UI::searchBy::EmailAddress: searchByEmailAddress();
		break;

	case UI::searchBy::TelephoneNumber: searchByTelephoneNumber();
		break;

	case UI::searchBy::Town: searchByTown();
		break;

	case UI::searchBy::Country: searchByCountry();
		break;

	case UI::searchBy::wrongType:UI::wrongTypeOfSearch();
		break;
	}
	work();

}

void AddressBook::wrongTypeOfInput()
{
	UI::wrongTypeOfInput();
	work();
}

Person AddressBook::getPerson()//needs logic for checking all info 
{/*
 std::string getFirstName();
	std::vector<std::string> getOtherNames();
	std::string getEmailAddress();
	std::string getTelephoneNumber();
	std::string getTown();
	std::string getCountry();
	std::string getStreet();

	std::string name = getFirstName();
	if(name != rightName ){//check logic for name //do the same for all attributes
	UI::wrongName();
	work();
	}
	...
	return person(name...);

 */
	return Person("name", { "othername","lastName" }, "emailAddres", "phoneNumber", Address("Steeet", "town", "Country"));//placeholder
}

void AddressBook::searchByFirstName()
{
	std::string nameToFind = UI::getFirstName();
	int numberOfContactsFound = 0;
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i].checkFirstName(nameToFind)) {
			if (numberOfContactsFound == 0) UI::personFound();
			UI::printPerson(contacts[i]);
			numberOfContactsFound++;
		}

	}
	if (numberOfContactsFound == 0) UI::personNotFound();

}

void AddressBook::searchByOtherNames()
{
	std::vector<std::string> otherNamesToFind = UI::getOtherNames();
	int numberOfContactsFound = 0;
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i].checkOtherNames(otherNamesToFind)) {
			if (numberOfContactsFound == 0) UI::personFound();
			UI::printPerson(contacts[i]);
			numberOfContactsFound++;
		}

	}
	if (numberOfContactsFound == 0) UI::personNotFound();
}

void AddressBook::searchByEmailAddress()
{
	std::string emailToFind = UI::getEmailAddress();
	int numberOfContactsFound = 0;
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i].checkEmailAddress(emailToFind)) {
			if (numberOfContactsFound == 0) UI::personFound();
			UI::printPerson(contacts[i]);
			numberOfContactsFound++;
		}

	}
	if (numberOfContactsFound == 0) UI::personNotFound();
}

void AddressBook::searchByTelephoneNumber()
{
	std::string telephoneNumberToFind = UI::getTelephoneNumber();
	int numberOfContactsFound = 0;
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i].checkPhoneNumber(telephoneNumberToFind)) {
			if (numberOfContactsFound == 0) UI::personFound();
			UI::printPerson(contacts[i]);
			numberOfContactsFound++;
		}

	}
	if (numberOfContactsFound == 0) UI::personNotFound();
}

void AddressBook::searchByTown()
{
	std::string townToFind = UI::getTown();
	int numberOfContactsFound = 0;
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i].checkAddressByTown(townToFind)) {
			if (numberOfContactsFound == 0) UI::personFound();
			UI::printPerson(contacts[i]);
			numberOfContactsFound++;
		}

	}
	if (numberOfContactsFound == 0) UI::personNotFound();
}

void AddressBook::searchByCountry()
{
	std::string countryToFind = UI::getCountry();
	int numberOfContactsFound = 0;
	for (size_t i = 0; i < contacts.size(); i++) {
		if (contacts[i].checkAddressByCountry(countryToFind)) {
			if (numberOfContactsFound == 0) UI::personFound();
			UI::printPerson(contacts[i]);
			numberOfContactsFound++;
		}

	}
	if (numberOfContactsFound == 0) UI::personNotFound();

}

void AddressBook::exit()
{
	UI::savingInProgress();
	if (saveBook()) UI::savingFinished();

	else UI::savingError();

	UI::programTerminated();
}

bool AddressBook::saveBook()
{
	return false;
}

AddressBook::AddressBook()
{
}

AddressBook::AddressBook(std::vector<Person> newContacts)
{
	contacts = newContacts;
}

bool AddressBook::loadBook()
{
	return false;
}

void AddressBook::work()
{
	switch (UI::startingPoint()) {
	case UI::workInput::add: addPerson();
		break;

	case UI::workInput::remove: removePerson();
		break;

	case UI::workInput::search: search();
		break;

	case UI::workInput::exit: exit();
		break;

	case UI::workInput::wrongType: wrongTypeOfInput();
		break;

	}
}


