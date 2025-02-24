#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include <ios>
#include <limits>
#include <stdlib.h> 

namespace ContactList //namespace to reference 
{

	class Contact //class name
	{
		private:
			std::string	firstName;
			std::string	lastName;
			std::string	nickName;
			std::string	phoneNumber;
			std::string	darkestSecret;
		public:
			void setFirstName(std::string Name);
			void setLastName(std::string lastName);
			void setNickName(std::string nickName);
			void setPhoneNumber(std::string number);
			void setDarkestSecret(std::string secret);

			std::string getFirstName();
			std::string getLastName();
			std::string getNickName();
			std::string getPhoneNumber();
			std::string getDarkestSecret();
	};

	class Phonebook
	{
		public:
			ContactList::Contact contact[8];
	};
} //namespace contactList


ContactList::Contact AddContact(void);
void	SearchContacts(ContactList::Phonebook phoneBook);
std::string truncateText(std::string text);
std::string	SaveData(std::string message);
int isValidNumberInRange(ContactList::Phonebook phoneBook, const std::string& input);
void	displayContact(ContactList::Phonebook phoneBook);

#endif