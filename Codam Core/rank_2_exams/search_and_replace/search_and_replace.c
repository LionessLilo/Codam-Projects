/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_and_replace.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 13:50:34 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/06 14:54:46 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


int	main(int argc, char **argv)
{
	int i = 0;

	while (argc == 4)
	{
		while(argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
			write(1, &argv[1][i], 1);
			i++;
		}
		write(1, "\n", 1);
		exit (0);
	}
	write(1, "\n", 1);
	return 0;
}
