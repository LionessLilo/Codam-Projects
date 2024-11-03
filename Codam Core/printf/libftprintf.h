/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:44:18 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/03 20:18:09 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int		ft_print_char(int c);
int		ft_print_number(int nbr);
int		ft_printstr(char *str);
int		ft_print_hex(unsigned long nb, char specifier);
void	vp_to_hex(void *nb);
int		ft_putnbr(int n, int fd);

#endif