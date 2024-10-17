/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 09:35:49 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/17 17:48:04 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	find_word(char const *s, char c)
{
	int	bread_length;
	int	total_bread_length;

	bread_length = 0;
	while (s[bread_length] != c)
	{
		bread_length++;
	}
	if (s[bread_length] == c)
	{
		total_bread_length = bread_length - 1;
	}
	return ();
}

static num_delimeter(char const *s, char c)
{
	int	number_of_commas;
	int	i;

	i = 0;
	number_of_commas = 0;
	while (s[i] != '\0' )
	{
		if (s[i] == c)
		{
			number_of_commas++;
		}
		i++;
	}
	return (number_of_commas);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_of_commas;
	char	*list;
	int		whole_str_len;

	num_of_commas = num_delimeter(*s, c);
	whole_str_len = ft_strlen(s);
	list = malloc (sizeof(char) * (whole_str_len - num_of_commas));
	while (s != '\0')
	{
		find_word(s, c);
	}
}


// String array
	// char aray_name[max number of strings in the array][maximum numbers of characters that can be stored in each string] = {list of string};

// How to copy into the array:

//strcpy(arr[0],"Milk");
	// i = 0; 
	// while (i < 3)
	// {
	// 	printf("%s\n", arr[i]);
	// 	i++;
	// }

//Bread,Milk,Eggs -----> Split on the ,
// Output =
// Bread 
// Milk 
// Eggs

// Step 2: DONE
// Allocate the memory for the array(there are going to be x number of items)

// Step 3:
// Count how long each word is and allocate the memory for each word

// Step 4:
// Split the string, each substring needs to go into its aown array within the array

// NB!
// End with a null pointer, so last item in the list should be a NULL pointer
// Handle malloc errors
