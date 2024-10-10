/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memmove_test.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:04:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/10/10 17:04:35 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	char source[] = "Hello, World!";
	char destination[20];

	printf("Source before memmove: %s\n", source);
	// Test case 1: Regular overlapping case
	ft_memmove(source + 7, source, 5);
	// Move "Hello," (6 characters)
	printf("Source after overlapping memmove: %s\n", source);
	// Expected: "Hello, Hello!"
	// Test case 2: Non-overlapping case
	ft_memmove(destination, source, strlen(source) + 1);
	// Copy whole string, including '\0'
	printf("Destination after non-overlapping memmove: %s\n", destination);
	// Expected: "Hello, Hello!"
	return (0);
}