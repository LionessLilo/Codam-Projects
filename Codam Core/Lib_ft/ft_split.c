/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 09:35:49 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/19 23:41:31 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

static char	*allocate_substring(char *changable_s, int where_comma)
{
	char	*substring;

	substring = (char *)malloc((where_comma + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	strncpy(substring, changable_s, where_comma);
	substring[where_comma] = '\0';
	return (substring);
}

static void	*free_mem(int i, char **list)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

static int	num_of_strings(char *changable_s, char c)
{
	int	number_of_commas;
	int	i;

	i = 0;
	number_of_commas = 0;
	while (changable_s[i] != '\0' )
	{
		if (changable_s[i] == c)
		{
			number_of_commas++;
		}
		i++;
	}
	return (number_of_commas);
}

static int	delimeter(char const *s, char c)
{
	int	d_i;

	d_i = 0;
	while (s[d_i] != '\0')
	{
		if (s[d_i] == c)
		{
			return (d_i);
		}
		d_i++;
	}
	return (d_i);
}

char	**ft_split(char const *s, char c)
{
	int		where_comma;
	char	*changable_s;
	char	**list;
	int		num_list_items;
	int		list_item_index;

	changable_s = (char *)s;
	list_item_index = 0;
	num_list_items = num_of_strings(changable_s, c) + 1;
	list = malloc(num_list_items * sizeof(char *));
	if (!list)
		return (NULL);
	while (*changable_s)
	{
		where_comma = delimeter(changable_s, c);
		list[list_item_index] = allocate_substring(changable_s, where_comma);
		if (!list[list_item_index])
			free_mem(list_item_index, list);
		changable_s = changable_s + where_comma + 1;
		list_item_index++;
	}
	list[num_list_items] = NULL;
	return (list);
}

int main()
{
	char str[] = "Bread,Milk,Eggs";
	char delimiter = ',';
	char	**splitted;

	// Test your ft_split function (Step 1)
	printf("Testing Step 1 with string: \"%s\" and delimiter: '%c'\n", str, delimiter);
	splitted = ft_split(str, delimiter);
	printf("first item: %s\n", splitted[0]);
	printf("2nd item: %s\n", splitted[1]);
	printf("3rd item: %s\n", splitted[2]);

	return 0;
}

