/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:26:55 by root          #+#    #+#                 */
/*   Updated: 2025/01/02 17:41:24 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./includes/push_swap.h"

int	main(void)
{
	int valid = is_it_a_digit('2');
	
	if (valid == 1)
		printf("is a digit");
	return (0);
}
