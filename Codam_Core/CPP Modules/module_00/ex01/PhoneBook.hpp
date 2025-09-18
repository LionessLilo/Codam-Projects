/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 15:22:09 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/17 18:25:00 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class	PhoneBook
{
	private:
	Contact	contactsList[8];
	int		nbrEnteredContacts;
	int		nextEntry;

	public:
	PhoneBook();
	int	addContact();
	int	search();

};

#endif