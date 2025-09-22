/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 15:23:17 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/22 12:47:57 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "main.hpp"

PhoneBook::PhoneBook()
{
	nbrEnteredContacts = 0;
	nextEntry = 0;
}

int	PhoneBook::addContact(void)
{
	Contact		newContact;
	std::string	input;

	std::cout << "Please fill in the following information\n" <<std::endl;

	ask_and_set("First name: ", newContact, &Contact::set_first_name);
	ask_and_set("Last name: ", newContact, &Contact::set_last_name);
	ask_and_set("Nickname: ", newContact, &Contact::set_nickname);
	ask_and_set("Phone number: ", newContact, &Contact::set_phone_nbr);
	ask_and_set("Their darkest secret: ", newContact, &Contact::set_secret);

	contactsList[nextEntry] = newContact;
	nextEntry = (nextEntry + 1) % 8;
	return 0;
}

int	PhoneBook::search(void)
{
	// bool	return_flag = false;
	// int		i = 0;

	// while (!return_flag)
	// {
		std::cout << "PhoneBook\n" << std::endl;

		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	// }
	return 0;
}