/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:13:52 by mikim             #+#    #+#             */
/*   Updated: 2017/10/09 23:16:49 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = -1;
	j = -1;
	a = -1;
	while (dst[++i])
		;
	while (src[++j])
		;
	if (size > (i + 1))
	{
		while (++a < (size - i - 1))
			dst[i + a] = src[a];
		dst[i + a] = '\0';
	}
	if (i <= size)
		return (i + j);
	else
		return (size + j);
}
