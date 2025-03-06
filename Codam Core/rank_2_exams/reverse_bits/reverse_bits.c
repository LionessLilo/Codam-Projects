/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_bits.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 12:44:05 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/06 13:04:06 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 0;
	unsigned char result = 0;

	while (i < 8)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
		i++;	
	}
	return result;
}
