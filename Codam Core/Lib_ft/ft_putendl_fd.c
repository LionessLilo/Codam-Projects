/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 17:58:23 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/21 18:33:10 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  
#include <stdio.h>
#include <string.h>

void	ft_putendl_fd(char *s, int fd)
{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
}
