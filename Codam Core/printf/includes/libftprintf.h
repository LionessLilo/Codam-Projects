/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/30 17:58:30 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/31 14:39:15 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	    ft_printf(const char *str, ...);
int	    ft_print_char(int c);
int	    ft_printstr(char *str);
int     ft_print_number(int nbr);

#endif