/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:49:39 by atafah            #+#    #+#             */
/*   Updated: 2018/10/20 15:57:12 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*iter;

	head = (*f)(lst);
	if (!lst)
		return (NULL);
	lst = lst->next;
	iter = head;
	if (head)
	{
		while (lst != NULL)
		{
			iter->next = (*f)(lst);
			lst = lst->next;
			iter = iter->next;
		}
		iter->next = NULL;
		return (head);
	}
	return (NULL);
}
