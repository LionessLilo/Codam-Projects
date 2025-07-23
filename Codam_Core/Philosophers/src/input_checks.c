/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:17:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 15:18:58 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	check_argc(int argc);
t_error	argv_check(char **input_list);
t_error	check_digits(char **input_list);
t_error	check_int(char **input_list);

/*
	- Checks argc
	- Checks argv
	- Cleans up list after ft_split if it was used.
*/

t_error	input_checks(int argc,
				char **argv)
{
	int		argc_working;
	char	**input_list;
	t_error	error_check;
	
	argc_working = argc;
	if (argc == 2)
		argc_working = ((int)find_list_size(argv[1], ' ')) + 1;
	error_check = check_argc(argc_working);
	if (error_check != SUCCESS)
		return (error_check);
	if (argc == 2)
	{
		input_list = ft_split(argv[1], ' ');
		if (!input_list)
			return (FUNCT_ERROR);
	}
	else
		input_list = argv + 1;
	error_check = argv_check(input_list);
	if (argc == 2)
		cleanup_list(input_list);
	if (error_check != SUCCESS)
		return (error_check);
	return (SUCCESS);
}

t_error	check_argc(int argc)
{
	if (argc < 5)
		return (USER_INPUT_ERROR);
	if (argc > 6)
		return (USER_INPUT_ERROR);
	return (SUCCESS);
}

t_error	argv_check(char **input_list)
{
	t_error	error_check;

	if (!input_list)
		return (USER_INPUT_ERROR);
	error_check = check_digits(input_list);
	if (error_check != SUCCESS)
		return (USER_INPUT_ERROR);
	error_check = check_int(input_list);
	if (error_check != SUCCESS)
		return (USER_INPUT_ERROR);
	return (SUCCESS);
}

t_error	check_digits(char **input_list)
{
	char	*item;
	
	while (*input_list)
	{
		item = *input_list;
		if (!item || *item == '\0')
			return (USER_INPUT_ERROR);
		while (*item)
		{
			if (ft_isdigit(*item) == 0)
				return (USER_INPUT_ERROR);
			item++;
		}
		input_list++;
	}
	return (SUCCESS);
}

t_error	check_int(char **input_list)
{
	char 		*item;
	long int	str_to_nbr;
	// t_error		error_check;

	while (*input_list)
	{
		item = *input_list;
		str_to_nbr = ft_atol(item);
		if (input_list[0] && str_to_nbr > 200)
			return (USER_INPUT_ERROR);
		if (str_to_nbr > INT_MAX)
			return (USER_INPUT_ERROR);
		input_list++;
	}
	return (SUCCESS);
}
