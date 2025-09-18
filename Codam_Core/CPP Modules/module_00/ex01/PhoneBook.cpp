/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 15:23:17 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/17 18:30:15 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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

	std::cout << "First name:";
	std::getline(std::cin, input);
	std::cout << std::endl;
	newContact.set_first_name(input);
	input.clear();

	std::cout << "Last name:";
	std::getline(std::cin, input);
	std::cout << std::endl;
	newContact.set_last_name(input);
	input.clear();

	std::cout << "Nickname:";
	std::getline(std::cin, input);
	std::cout << std::endl;
	newContact.set_nickname(input);
	input.clear();

	std::cout << "Phone number:";
	std::getline(std::cin, input);
	std::cout << std::endl;
	newContact.set_phone_nbr(input);
	input.clear();

	std::cout << "Your darkest secret:";
	std::getline(std::cin, input);
	std::cout << std::endl;
	newContact.set_secret(input);
	input.clear();


	contactsList[nextEntry] = newContact;
	nextEntry = (nextEntry + 1) % 8;
	return 0;
}

int	PhoneBook::search(void)
{
	
}