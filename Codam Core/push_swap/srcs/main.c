/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/22 15:28:23 by root          #+#    #+#                 */
/*   Updated: 2024/12/22 15:49:13 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../printf/ft_printf.h"
// #include "../printf/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_isvalid_arg(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "No arguments found", 18);
		return (0);
	}
	
	return (1);
}

int	main(int argc, char *argv[])
{
	int	valid;

	valid = ft_isvalid_arg(argc, argv);
	if (valid == 0)
		exit ;
	else 

}
