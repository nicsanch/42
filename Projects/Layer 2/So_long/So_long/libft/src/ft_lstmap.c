/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:02:54 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/20 15:17:52 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*element;

	newlist = NULL;
	while (lst != NULL)
	{
		element = malloc (sizeof(struct s_list));
		if (!element)
		{
			free (element);
			ft_lstclear(&newlist, *del);
			return (NULL);
		}
		element->content = f(lst->content);
		element->next = NULL;
		ft_lstadd_back(&newlist, element);
		lst = lst->next;
	}
	return (newlist);
}
