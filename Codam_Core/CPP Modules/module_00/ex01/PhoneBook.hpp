/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 15:22:09 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/15 16:24:34 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
	Contact	contactsList[8];
	int		nbrEnteredContacts;
	int		nextEntry;

	public:
	PhoneBook();

};

#endif