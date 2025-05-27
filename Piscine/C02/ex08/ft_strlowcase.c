/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlowcase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/16 16:04:02 by root          #+#    #+#                 */
/*   Updated: 2025/05/27 13:59:53 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


static int	ft_chr_is_uppercase(int chr)
{
	if (chr >= 'A' && chr <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_chr_is_uppercase(str[i]) == 1)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
