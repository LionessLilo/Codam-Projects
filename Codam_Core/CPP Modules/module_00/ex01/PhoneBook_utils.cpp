/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook_utils.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/22 12:08:39 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/22 12:10:00 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void ask_and_set(const std::string& title, Contact& contact, void (Contact::*setter)(std::string))
{
    std::string input;

    std::cout << title << std::endl;
    std::getline(std::cin, input);
    std::cout << std::endl;
    (contact.*setter)(input);
    input.clear();
}
