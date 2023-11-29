/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicsanch <nico_sp_92@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:35:56 by nicsanch          #+#    #+#             */
/*   Updated: 2023/05/17 18:20:59 by nicsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*container;

	container = *lst;
	while (container != NULL)
	{
		container = container-> next;
		ft_lstdelone(*lst, *del);
		*lst = container;
	}
	*lst = NULL;
}
