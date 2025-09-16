/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 16:28:32 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/16 17:41:43 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"

void	instructions(void);
int		check_input(std::string user_input);

/*
	- Starts the program with instructions for the program
*/
int	main(void)
{
	PhoneBook	phonebook_1;
	bool		exit_flag;
	std::string	input;

	std::cout << "Welcome to your PhoneBook!\n" << std::endl;
	instructions();
	while (!exit)
	{
		std::getline(std::cin, input);
		if (check_input(input) == -1)
		{
			input.clear();
			instructions();
		}
		if (input.compare("ADD") == 0)
			
		else if (input.compare("SEARCH") == 0)
			//To do: search for a contact
		else if (input.compare("EXIT") == 0)
		{
			exit = true;
		}
	}

	return 0;
}

void	instructions(void)
{
	std::cout << "Please give me one of the following commands:" << std::endl;
	std::cout << "\tADD to add a contact" << std::endl;
	std::cout << "\tSEARCH to find a contact" << std::endl;
	std::cout << "\tEXIT to exit the program" << std::endl;
}

int	check_input(std::string user_input)
{
	if (user_input.compare("ADD") == 0
	 || user_input.compare("SEARCH") == 0
	 || user_input.compare("EXIT") == 0)
	 	return 0;
	else
		std::cout << "You did not enter a valid argument. Please try again." << std::endl;
	return -1;
}