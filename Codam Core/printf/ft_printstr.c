/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 09:24:29 by lilo          #+#    #+#                 */
/*   Updated: 2024/10/31 09:30:38 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
