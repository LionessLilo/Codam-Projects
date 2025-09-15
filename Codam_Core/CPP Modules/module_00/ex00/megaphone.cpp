/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/15 11:39:34 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/15 13:02:02 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] = std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	
	i = 1;
	while (argv[i])
	{
		std::cout << argv[i];
		if (argv[i + 1])
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	
	return 0;
}

