/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:37:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 15:00:32 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./test_utils.h"
#include "../libft.h"

void	log_tick(void);
void	log_error(const char *message);

void	log_test(int condition, const char *message)
{
	if (condition)
		log_tick();
	else
		log_error(message);
}

void	log_tick(void)
{
	printf(GREEN "✓" RESET);
}

void	log_error(const char *message)
{
	printf(RED "✗ %s" RESET, message);
}
