/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:29:40 by mikim             #+#    #+#             */
/*   Updated: 2017/10/10 00:12:29 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;

	if (!s || !f)
		return (NULL);
	i = -1;
	while (s[++i])
		;
	if (!(r = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		r[i] = f(i, s[i]);
	r[i] = '\0';
	return (r);
}
