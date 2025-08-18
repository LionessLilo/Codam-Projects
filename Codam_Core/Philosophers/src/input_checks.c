/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:17:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/18 11:27:11 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_argc(int argc);
int	argv_check(char **input_list);
int	check_digits(char **input_list);
int	check_int(char **input_list);

/*
	- Checks argc
	- Checks argv
	- Cleans up list after ft_split if it was used.
*/

int	input_checks(int argc,
				char **argv)
{
	int		argc_working;
	char	**input_list;
	int		error_check;

	argc_working = argc;
	if (argc == 2)
		argc_working = ((int)find_list_size(argv[1], ' ')) + 1;
	if (check_argc(argc_working) == 41)
		return (-1);
	if (argc == 2)
	{
		input_list = ft_split(argv[1], ' ');
		if (!input_list)
			return (write_error("Input split failed", -1), -1);
	}
	else
		input_list = argv + 1;
	error_check = argv_check(input_list);
	if (argc == 2)
		cleanup_list(input_list);
	if (error_check != 0)
		return (-1);
	return (0);
}

int	check_argc(int argc)
{
	if (argc < 5)
		return (write_error("Invalid user input", 41), 41);
	if (argc > 6)
		return (write_error("Invalid user input", 41), 41);
	return (0);
}

int	argv_check(char **input_list)
{
	if (!input_list)
		return (write_error("Invalid user input", 41), 41);
	if (check_digits(input_list) == 41)
		return (41);
	if (check_int(input_list) == 41)
		return (41);
	return (0);
}

int	check_digits(char **input_list)
{
	char	*item;

	while (*input_list)
	{
		item = *input_list;
		if (!item || *item == '\0')
			return (write_error("Invalid user input", 41), 41);
		while (*item)
		{
			if (ft_isdigit(*item) == 0)
				return (write_error("Invalid user input", 41), 41);
			item++;
		}
		input_list++;
	}
	return (0);
}

int	check_int(char **input_list)
{
	char		*item;
	long int	str_to_nbr;

	while (*input_list)
	{
		item = *input_list;
		str_to_nbr = ft_atol(item);
		if (input_list[0] && str_to_nbr > 200)
			return (write_error("Invalid user input", 41), 41);
		if (str_to_nbr > INT_MAX)
			return (write_error("Invalid user input", 41), 41);
		input_list++;
	}
	return (0);
}
