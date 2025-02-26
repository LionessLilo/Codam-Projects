/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 17:56:58 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/26 17:59:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/libft/libft.h"

void	free_variables(char **temp_path, char **path_join)
{
	ft_free(temp_path);
	ft_free(path_join);
}
