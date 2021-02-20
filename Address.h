#pragma once
#include <string>


class Address
{

	std::string street;
	std::string town;
	std::string country;

public:
	Address(std::string newStreet, std::string newTown, std::string newCountry);
	bool checkAddressByTown(std::string addressToCheck);
	bool checkAddressByCountry(std::string addressToCheck);
	bool checkAddressByStreet(std::string addressToCheck);
	bool checkAddress(const Address& person);


};

