/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/28 11:14:09 by lilo          #+#    #+#                 */
/*   Updated: 2025/05/28 11:52:26 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(const char *str)
{
	unsigned int	i;

	while (str[i])
		i++;
	return (i);
}

static unsigned int	strlcat_dest_len(char *dst, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && dst[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	return_value;
	unsigned int	dest_len;
	unsigned int	i;

	i = 0;
	dest_len = strlcat_dest_len(dst, size);
	return_value = ft_strlen(src) + dest_len;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[i] && (dest_len + i < size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (return_value);
}

// #include <stdio.h>
// #include <bsd/string.h>
// #include <string.h>

// int main(void)
// {
// 	char cust_dst[20] = "Hello";
// 	char cust_src[] = " World!";
// 	char stand_dest[20] = "Hello";
// 	char stand_src[] = " World!";
// 	unsigned int size = 20;
// 	unsigned int result_custom = ft_strlcat(cust_dst, cust_src, size);
// 	unsigned int result_standard = strlcat(stand_dest, stand_src, size);

// 	printf("Custom ft_strlcat result: %u\n", result_custom);
// 	printf("Standard strlcat result: %u\n", result_standard);
// 	if (strcmp(cust_dst, stand_dest) == 0)
// 		printf("It matches\n");
// 	else
// 		printf("It does not match\n");

// 	return 0;
// }
