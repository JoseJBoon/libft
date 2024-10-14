/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:47:36 by jboon             #+#    #+#             */
/*   Updated: 2024/10/14 15:37:38 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*curr;

	if (lst == NULL || del == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
