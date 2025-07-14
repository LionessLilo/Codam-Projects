/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/14 17:40:35 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	int	result_input_check;

	result_input_check = input_checks(argc, argv);
	if (result_input_check != 0)
	{
		write(2, "Error: Invalid user input. Please consult project pdf.", 55);
		return (result_input_check);
	}
	//If it is valid, assign input values to where they need to go.
	//Start logic
	//Handle bubbled up errors. 
	return (0);
}
