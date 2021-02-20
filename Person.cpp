#include "Person.h"

Person::Person(std::string newFirstName, std::vector<std::string> newOtherNames, std::string newEmailAddress, std::string newTelephoneNumber, Address newAddress) :
	firstName{ newFirstName }, otherNames{ newOtherNames }, emailAddress{ newEmailAddress }, telephoneNumber{ newTelephoneNumber }, address{ newAddress }{}

Person::Person(const Person& person) : firstName{ person.firstName }, otherNames{ person.otherNames },
emailAddress{ person.emailAddress }, telephoneNumber{ person.telephoneNumber }, address{ person.address }{}

bool Person::checkFirstName(std::string nameToCheck)
{
	return nameToCheck == firstName;
}

bool Person::checkOtherNames(std::vector<std::string> namesToCheck)
{
	return namesToCheck == otherNames;
}

bool Person::checkEmailAddress(std::string emailToCheck)
{
	return emailToCheck == emailAddress;
}

bool Person::checkPhoneNumber(std::string numberToCheck)
{
	return numberToCheck == telephoneNumber;
}

bool Person::checkAddress(Address addressToCheck)
{
	return address.checkAddress(addressToCheck);
}

bool Person::checkAddressByTown(std::string addressToCheck)
{
	return address.checkAddressByTown(addressToCheck);
}

bool Person::checkAddressByCountry(std::string addressToCheck)
{
	return address.checkAddressByCountry(addressToCheck);
}

bool Person::operator ==(const Person& person)
{
	return (checkFirstName(person.firstName) && checkOtherNames(person.otherNames) && checkEmailAddress(person.emailAddress) && checkPhoneNumber(person.telephoneNumber) && checkAddress(person.address));
}


