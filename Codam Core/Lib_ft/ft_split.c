/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 09:35:49 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/19 18:12:40 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

static free_mem(int i, char **list)
{
	int j;

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
	while (changable_s[i] != '\0')
	{
		if (changable_s[i] == c)
			number_of_commas++;
		i++;
	}
	return (number_of_commas + 1);
}

static int	delimiter(char const *s, char c)
{
	int	d_i;

	d_i = 0;
	while (s[d_i] != '\0')
	{
		if (s[d_i] == c)
			return (d_i);
		d_i++;
	}
	return (d_i);
}

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

static char	**split_string(char *changable_s, char c)
{
	char	**list;
	int		i;
	int		where_comma;

	i = 0;
	list = (char **)malloc
		((num_of_strings(changable_s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	while (*changable_s)
	{
		where_comma = delimiter(changable_s, c);
		list[i] = allocate_substring(changable_s, where_comma);
		if (!list[i])
		{
			free_mem(i, list);
		}
		i++;
		changable_s = changable_s + where_comma;
		if (*changable_s == c)
			changable_s++;
	}
	list[i] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	*changable_s;

	changable_s = (char *)s;
	return (split_string(changable_s, c));
}

int	main(void)
{
	char	str[] = "Bread,Milk,Eggs";
	char	delimiter = ',';
	char	**result;

	printf("Testing ft_split with string: \"%s\" and delimiter: '%c'\n", str, delimiter);
	result = ft_split(str, delimiter);
	if (result)
	{
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("%s\n", result[i]);
			free(result[i]);
		}
		free(result);
	}
	return (0);
}
