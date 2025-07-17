/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:17:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/17 11:07:52 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_argc(int argc);
int	argv_check(char **input_list);
int	check_digits(char **input_list);
int	check_int(char **input_list);

int	input_checks(int argc,
				char **argv)
{
	int		return_check;
	char	**input_list;
	return_check = 0;
	if (argc == 2)
		input_list = ft_split(argv[1], ' ');
	input_list = argv;
	return_check = check_argc(argc);
	if (return_check != 0)
		return (return_check);
	return_check = argv_check(input_list);
	if (return_check != 0)
		return (return_check);
	return (0);
}

int	check_argc(int argc)
{
	if (argc < 5)
		return (41);
	if (argc > 6)
		return (41);
	return (0);
}

int	argv_check(char **input_list)
{
	int	result;

	if (!input_list)
		return (41);
	input_list++;
	result = check_digits(input_list);
	if (result != 0)
		return (41);
	result = check_int(input_list);
	if (result != 0)
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
			return (41);
		while (*item)
		{
			if (ft_isdigit(*item) == 0)
				return (41);
			item++;
		}
		input_list++;
	}
	return (0);
}

int	check_int(char **input_list)
{
	char 		*item;
	long int	str_to_nbr;

	while (*input_list)
	{
		item = *input_list;
		str_to_nbr = ft_atol(item);
		if (input_list[0] && str_to_nbr > 500)
			return (41);
		if (str_to_nbr > INT_MAX)
			return (41);
		input_list++;
	}
	return (0);
}
