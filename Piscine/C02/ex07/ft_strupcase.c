/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupcase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 15:22:27 by root          #+#    #+#                 */
/*   Updated: 2025/02/16 16:02:15 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_chr_is_lowercase(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		return (1);
	else
		return (0);
	return (1);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_chr_is_lowercase(str[i]) == 1)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
