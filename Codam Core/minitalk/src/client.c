/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:51:26 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 14:09:50 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Write a program (main) in which the client takes two parameters/arguments

The PID of the server to which it wants to send the message

	A message

Encrypt the message (I did the encryption via bits)

Send the message to the server (via its PID)

Create a stop condition so that the server knows when it has finished receiving the message
*/ 

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	if (input_errors(argc, argv))
	{
		ft_putendl_fd("Error\n", 2);
		exit (41);
	}

	return (2);
}
