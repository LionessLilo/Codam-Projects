/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:51:26 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 15:14:46 by llourens      ########   odam.nl         */
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
	int	pid;

	pid = 0;
	if (input_errors(argc, argv) == 1)
		error_and_exit(41);
	pid = ft_atol(argv[1]);
	if (kill(pid, 0) == -1)
		error_and_exit(136);
	// Proceed with rest of the message sending
	return (2);
}
