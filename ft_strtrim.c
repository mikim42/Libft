/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 23:48:16 by mikim             #+#    #+#             */
/*   Updated: 2017/10/10 00:07:20 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strlen_nospaces(char *s, int *len, int *start, int *end)
{
	int	i;
	int	j;
	int	k;
	int	res;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	while (s[j])
		++j;
	*len = j;
	res = j;
	k = 0;
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
	{
		--j;
		++k;
	}
	res = res - i - k;
	*start = (res > 0 ? res : 1);
	*end = k;
}

char		*ft_strtrim(char const *s)
{
	char	*r;
	int		len;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	ft_strlen_nospaces((char*)s, &len, &i, &j);
	if (!(r = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	k = -1;
	while (i < j)
		r[++k] = s[i++];
	r[k] = '\0';
	return (r);
}
