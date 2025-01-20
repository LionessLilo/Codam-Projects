/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:14:09 by root          #+#    #+#                 */
/*   Updated: 2025/01/20 14:17:07 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (0);
	while (lst->ptr_next)
		lst = lst->ptr_next;
	return (lst);
}
