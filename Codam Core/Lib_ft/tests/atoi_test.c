/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 09:11:41 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/15 09:13:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>  // For the original atoi function
#include "libft.h"   // For your ft_atoi function

// A helper function to test ft_atoi against the original atoi
void	test_atoi(const char *str)
{
	int	original_atoi = atoi(str);    // Using the standard library function
	int	your_atoi = ft_atoi(str);     // Using your custom ft_atoi function

	printf("Input string: \"%s\"\n", str);
	printf("Original atoi: %d\n", original_atoi);
	printf("Your ft_atoi:  %d\n", your_atoi);
	if (original_atoi == your_atoi)
		printf("✅ Passed\n\n");
	else
		printf("❌ Failed\n\n");
}

int	main(void)
{
	// Basic number tests
	test_atoi("12345");             // positive number
	test_atoi("-12345");            // negative number
	test_atoi("0");                 // zero
	test_atoi("   12345");          // leading whitespace
	test_atoi("   -12345");         // negative with leading whitespace

	// Handling non-numeric characters after number
	test_atoi("42abc");             // numbers followed by characters
	test_atoi("  123abc");          // leading whitespace and trailing characters
	test_atoi("abc");               // no valid conversion
	test_atoi("12345+6789");        // number followed by invalid '+' sign

	// Testing positive and negative signs
	test_atoi("+42");               // valid plus sign
	test_atoi("-42");               // valid minus sign
	test_atoi("+-42");              // invalid combination of signs

	// Whitespace handling (including special whitespace characters)
	test_atoi("   123");            // multiple spaces
	test_atoi("\t\n\v\f\r 456");    // various whitespace characters

	// INT_MAX and INT_MIN boundaries
	test_atoi("2147483647");        // INT_MAX
	test_atoi("-2147483648");       // INT_MIN

	return (0);
}
