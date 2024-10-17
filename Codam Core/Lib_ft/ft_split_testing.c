/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/17 13:42:56 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/17 14:12:41 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
	int i;
	char arr[3][7] = {"Bread", "Butter", "Oranges"};
	printf("String array Elements are:\n");
  
	strcpy(arr[0],"Milk");
	i = 0; 
	while (i < 3)
	{
		printf("%s\n", arr[i]);
		i++;
	}


	return 0;
}
