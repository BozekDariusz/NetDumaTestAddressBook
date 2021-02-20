#include "Address.h"

Address::Address(std::string newStreet, std::string newTown, std::string newCountry) :street{ newStreet }, town{ newTown }, country{ newCountry }{}


bool Address::checkAddressByTown(std::string addressToCheck)
{
	return addressToCheck == town;
}

bool Address::checkAddressByCountry(std::string addressToCheck)
{
	return addressToCheck == country;
}

bool Address::checkAddressByStreet(std::string addressToCheck)
{
	return addressToCheck == street;
}

bool Address::checkAddress(const Address& address)
{
	return (checkAddressByTown(address.town) && checkAddressByStreet(address.street)&& checkAddressByCountry(address.country));
}
