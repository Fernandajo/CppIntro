#include "../includes/phonebook.hpp"

int	main(void)
{
	std::string str;

	ContactList::Phonebook phoneBook;
	int i = 0;
	std::cout << "===== Welcome to your personal PhoneBook!=====" << std::endl;
	do{
		std::cout << "Please choose [ ADD | SEARCH | EXIT ]" << std::endl;
		getline(std::cin, str);
		if(str.compare("ADD") == 0)
		{
			if(i > 7)
				i = 0;
			phoneBook.contact[i] = AddContact();
			i++;
		}
		if(str.compare("SEARCH") == 0)
			SearchContacts(phoneBook);
	} while (str != "EXIT");

}