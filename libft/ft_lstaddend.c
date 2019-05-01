/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atafah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 02:24:56 by atafah            #+#    #+#             */
/*   Updated: 2018/10/21 03:13:57 by atafah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	while ((**alst).next != NULL)
	{
		(*alst) = (**alst).next;
	}
	(**alst).next = malloc(sizeof(t_list));
	(**alst).next = new;
}
