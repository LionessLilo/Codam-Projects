/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:19:24 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/16 14:24:25 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./tests.h"

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
	printf(RED "\n✗ %s" RESET, message);
}