#pragma once
#include<iostream>
#include"Person.h"


namespace UI {


	enum class workInput { add, remove, search, save, exit, wrongType };
	enum class searchBy { FirstName, OtherNames, EmailAddress, TelephoneNumber, Town, Country, wrongType };


	workInput startingPoint();
	void wrongTypeOfInput();


	std::string getFirstName();
	std::vector<std::string> getOtherNames();
	std::string getEmailAddress();
	std::string getTelephoneNumber();
	std::string getTown();
	std::string getCountry();
	std::string getStreet();

	void addPersonPrompt();

	void wrongFirstName();
	void wrongOthernames();
	void wrongEmail();
	void wrongTelephoneNumber();
	void wrongTown();
	void wrongCountry();
	void wrongSteet();
	void wrongTypeOfSearch();

	void removePersonPrompt();

	searchBy typeOfSearch();
	void personFound();
	void personNotFound();

	void printPerson(Person person);

	void savingInProgress();
	void savingFinished();
	void savingError();

	void programTerminated();

};

