/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:38:17 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 10:19:53 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Checks if the character is a digit */

int	ft_isdigit(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	else
		return (0);
}
