/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:17:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/14 17:44:56 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_argc(int argc);
static int	argv_check(int argc, char **input_list);
static int	check_single_arg(int argc, char *input_str);

int	input_checks(int argc,
				char **input_list)
{
	int	return_check;
	//Check argv is only digits and positive(no zero), an int and has a max nbr of philosophers <1000. 
	return_check = 0;
	if (argc == 2)
	{
		return_check = check_single_arg(argc, input_list[1]);
		if (return_check != 0)
			return (return_check);
	}
	return_check = argc_check(argc, input_list);
	if (return_check != 0)
		return (return_check);
	return_check = argv_check(argc, input_list);
	if (return_check != 0)
		return (return_check);
	return (0);
}

static int	check_single_arg(int argc,
							  char *input_str)
{
	int	new_argc;
	int	result;

	new_argc = find_list_size(input_str, ' ');
	result = check_argc(new_argc);
	if (result != 0)
		return (result);
	while (input_str)
	{
		if (*input_str == '-' && (ft_isdigit(*(input_str + 1)) == 0))
			return (41);
		if ((*input_str != '-' || *input_str != ' ')
			&& (ft_isdigit(*input_str) == 0))
			return (41);
		input_str++;
	}
	return (0);
}

static int	check_argc(int argc)
{
	if (argc < 5)
		return (41);
	if (argc > 6)
		return (41);
	return (0);
}

static int	argv_check(int argc,
					   char **input_list)
{
	char	*item;

	input_list++;
	while (*input_list)
	{
		item = *input_list;
		while (*item)
		{
			if (ft_isdigit(*item) == 0)
				return (41);
		}
		
		input_list++;
	}
	return (0);
}
