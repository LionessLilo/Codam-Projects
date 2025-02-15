/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wdmatch.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 15:59:44 by root          #+#    #+#                 */
/*   Updated: 2025/02/15 17:42:45 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Go through s1
//Go through s2 looking for letter in s1
//If you find the letter keep track that it is printable
//increase s1[i], don't reset j
//check for s1[2] in the rest of s2, increasing j etc

#include <unistd.h>

int	strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] != s2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				s1_i;
	int				s2_i;
	int				pc_i;
	char			*print_chars;
	char			*s1;
	char			*s2;

	s1_i = 0;
	s2_i = 0;
	pc_i = 0;
	s1 = argv[1];
	s2 = argv[2];
	if (argc < 3)
		return (write(1, "\n", 1), 0);
	while (s1[s1_i])
	{
		while (s2[s2_i])
		{
			if (s1[s1_i] == s2[s2_i])
			{
				print_chars[pc_i] = s1[s1_i];
				pc_i++;
				break ;
			}
			s2_i++;
		}
		s1_i++;
	}
	print_chars[pc_i] = '\0';
	if (strcmp(s1, print_chars) == 0)
	{
		pc_i = 0;
		while (print_chars[pc_i])
		{
			write(1, &print_chars[pc_i], 1);
			pc_i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
