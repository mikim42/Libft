/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:54:30 by mikim             #+#    #+#             */
/*   Updated: 2017/10/10 00:10:25 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*tmp;

	if (!(head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		if (!(list = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		list = f(lst);
		if (!tmp)
			tmp->next = list;
		else
			head = list;
		tmp = list;
		lst = lst->next;
	}
	return (head);
}
