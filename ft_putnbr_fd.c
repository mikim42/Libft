/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:34:20 by mikim             #+#    #+#             */
/*   Updated: 2017/10/09 22:57:02 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nb;
	long cmp;
	char c;

	nb = (long)n;
	nb < 0 ? write(1, "-", 1) : 0;
	nb < 0 ? nb *= -1 : 0;
	cmp = 1000000000;
	while (cmp > 9 && nb / cmp == 0)
		cmp /= 10;
	while (cmp > 9)
	{
		c = nb / cmp + '0';
		write(fd, &c, 1);
		nb -= (c - '0') * cmp;
		cmp /= 10;
	}
	c = nb / cmp + '0';
	write(fd, &c, 1);
}
