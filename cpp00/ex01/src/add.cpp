#include "../includes/phonebook.hpp"

std::string	SaveData(std::string message)
{
	std::cout << message;
	std::string ret;
	getline(std::cin, ret);
	if (ret.size() == 0)
	{
		SaveData(message);
	}
	return ret;
}

ContactList::Contact AddContact(void)
{
	ContactList::Contact contact;
	
	std::cout << "===== Adding a new contact: =====" << std::endl;
	contact.setFirstName(SaveData("First Name: "));
	contact.setLastName(SaveData("Last Name: "));
	contact.setNickName(SaveData("Nickname: "));
	contact.setPhoneNumber(SaveData("Phone Number: "));
	contact.setDarkestSecret(SaveData("Darkest Secret: "));
	std::cout << "===== Contact created! =====" << std::endl;

	return (contact);
}

std::string truncateText(std::string text) {
	std::string ret = text;
    if (ret.length() > 10) {
        return ret.substr(0, 10 - 1) + '.';
    }
    return ret;
}

int isValidNumberInRange(ContactList::Phonebook phoneBook, const std::string& input) {
    int number;

    // Check if the string contains only digits
    if (input.empty() || input.find_first_not_of("01234567") != std::string::npos || input.length() > 1) {
        return -1;
    }

	number = atoi(input.c_str());

    // Check if the number is in the desired range
    if (phoneBook.contact[number].getFirstName().empty())
		return -1;
	else
		return number;
}

void	displayContact(ContactList::Phonebook phoneBook){
	std::string str;
	int i = -1;
	do
	{
		std::cout << "Please select a contact: ";
		getline(std::cin, str);
		i = isValidNumberInRange(phoneBook, str);
		if(i == -1){
			std::cout << "Incorrect input\n";
		}
	} while (i == -1);
	std::cout << "Index: " << i << std::endl;
	std::cout << "First Name: " << phoneBook.contact[i].getFirstName() << std::endl;
	std::cout << "Last Name: " << phoneBook.contact[i].getLastName() << std::endl;
	std::cout << "Nickname: " << phoneBook.contact[i].getNickName() << std::endl;
	std::cout << "Phone number: " << phoneBook.contact[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << phoneBook.contact[i].getDarkestSecret() << std::endl;
}

void	SearchContacts(ContactList::Phonebook phoneBook){
	if(phoneBook.contact[0].getFirstName().empty())
		return;
	int i = 0;
	std::cout << std::setfill(' ') 
         << std::setw(10) << std::right << "Index" << "|"
         << std::setw(10) << std::right << "First Name" << "|"
         << std::setw(10) << std::right << "Last Name" << "|"
         << std::setw(10) << std::right << "Nickname" << std::endl;
	while (i < 8 && phoneBook.contact[i].getFirstName().empty() == false)
	{
		std::cout << std::setw(10) << std::right << i << "|"
             << std::setw(10) << std::right << truncateText(phoneBook.contact[i].getFirstName()) << "|"
             << std::setw(10) << std::right << truncateText(phoneBook.contact[i].getLastName()) << "|"
             << std::setw(10) << std::right << truncateText(phoneBook.contact[i].getNickName()) << std::endl;
		i++;
	}
	displayContact(phoneBook);
}