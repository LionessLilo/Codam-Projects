/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 14:24:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/17 13:02:39 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <philo.h>

void	error_message(char *message)
{
	write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

void	report_error(int code)
{
	if (code == 41)
		error_message("User input not correct. Please consult project pdf.");
	else if (code == -1)
		error_message("Utility or standard function failure");
}
