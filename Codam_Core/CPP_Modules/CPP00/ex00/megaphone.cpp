/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ted: 2025/08/29                              +#+                     */
/*                                                   +#+                      */
/*   Created: Invalid date        by               #+#    #+#                 */
/*   Updated: 2025/08/29 16:33:39 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

char    **convert_to_upper(char **argv);
void    display_megaphone(char **argv);

int	main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    argv = argv + 1;
	convert_to_upper(argv);
    display_megaphone(argv);
	return (0);
}

char    **convert_to_upper(char **argv)
{
    int i = 0;
    int j;

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
    return (argv);
}

void    display_megaphone(char **argv)
{
    int  i = 0;

    while (argv[i])
    {
        std::cout << argv[i];
        i++;
    }
    std::cout << std::endl;
}
