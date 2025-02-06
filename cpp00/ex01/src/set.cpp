#include "../includes/phonebook.hpp"

void ContactList::Contact::setFirstName(std::string Name) {
	this->firstName = Name;
	}

void ContactList::Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
	}
		
void ContactList::Contact::setNickName(std::string nickName) {
	this->nickName = nickName;
	}

void ContactList::Contact::setPhoneNumber(std::string number) {
	this->phoneNumber = number;
	}

void ContactList::Contact::setDarkestSecret(std::string secret) {
	this->darkestSecret = secret;
	}


std::string ContactList::Contact::getFirstName() {
	return (this->firstName);
	}

std::string ContactList::Contact::getLastName() {
	return (this->lastName);
	}

std::string ContactList::Contact::getNickName() {
	return (this->nickName);
	}

std::string ContactList::Contact::getPhoneNumber() {
	return (this->phoneNumber);
	}

std::string ContactList::Contact::getDarkestSecret() {
	return (this->darkestSecret);
	}