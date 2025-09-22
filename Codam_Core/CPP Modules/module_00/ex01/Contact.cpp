/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 13:27:57 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/22 12:07:42 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* Setters*/
void		Contact::set_first_name(std::string first_name)
{firstName = first_name;}

void		Contact::set_last_name(std::string last_name)
{lastName = last_name;}

void		Contact::set_nickname(std::string nickname)
{nickName = nickname;}

void		Contact::set_phone_nbr(std::string phone_nbr)
{phoneNumber = phone_nbr;}

void		Contact::set_secret(std::string secret)
{darkestSecret = secret;}

/*Getters*/
std::string	Contact::get_first_name(void)
{return firstName;}

std::string	Contact::get_last_name(void)
{return lastName;}

std::string	Contact::get_nickname(void)
{return nickName;}

std::string	Contact::get_phone_nbr(void)
{return phoneNumber;}

std::string	Contact::get_secret(void)
{return darkestSecret;}
