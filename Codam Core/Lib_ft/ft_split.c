/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 09:35:49 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/18 11:06:46 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

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
	int		i;
	int		where_comma;
	int		whole_str_len;
	char	*changable_s;
	char	**list;

	changable_s = (char *)s;
	i = 0;
	while (i < 100000)
	{
		whole_str_len = ft_strlen(changable_s);
		where_comma = delimeter(changable_s, c);
		i = 0;
		while (i < where_comma)
		{
			write(1, &changable_s[i], 1);
			write(1, "\n", 1);
			i++;
		}
		i = where_comma + 1;
		while (i < whole_str_len)
		{
			changable_s[i - (where_comma + 1)] = changable_s[i];
			i++;
		}
		if (ft_strlen(changable_s) == 0)
		{
			break ;
		}
	}
	return (list);
}

// String array
	// char aray_name[max num of strings in the array][maximum numbers of characters that can be stored in each string] = {list of string};

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

// Step 1:
// for a given string (char pointer)
// loop forever (will sort this out later)
// get the length of the string
// Find the deliminator
// write to console the item (from 0 to index of deliminator)
// set the given string to be index + 1 till the end of the given string 
// (e.g. original string was "b,a,c,d" new string will ne "a,c,d")
// if the new length of given string is 0, then break the while loop

// Step 2: 
// figure out how to initialize a list of char **
// Allocate the memory for the array(there are going to be x number of items)

// Step 3:
// for every item extracted, add it to the list


// NB!
// End with a null pointer, so last item in the list should be a NULL pointer
// Handle malloc errors
void	main(void)
{
	char	*test_string = "Hello,world,this,is,a,test";
	char	delimitor = ",";

	int t = delimeter(test_string, delimitor);

	printf("%d", t);
}