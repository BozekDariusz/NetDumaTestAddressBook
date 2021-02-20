#pragma once
#include<string>
#include<vector>
#include"Address.h"


class Person
{
	std::string firstName;
	std::vector< std::string> otherNames;
	std::string emailAddress;
	std::string telephoneNumber;
	Address address;


public:
	Person(std::string newFirstName, std::vector<std::string> newOtherNames, std::string newEmailAddress,
		std::string newTelephoneNumber, Address newAddress);
	Person(const Person& person);
	bool checkFirstName(std::string nameToCheck);
	bool checkOtherNames(std::vector<std::string> namesToCheck);
	bool checkEmailAddress(std::string emailToCheck);
	bool checkPhoneNumber(std::string numberToCheck);
	bool checkAddress(Address addressToCheck);
	bool checkAddressByTown(std::string addressToCheck);
	bool checkAddressByCountry(std::string addressToCheck);
	bool operator == (const Person& person);

};

