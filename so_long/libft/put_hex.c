/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:34 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:25:37 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}

void	ft_putlonghex_fd(unsigned long nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putlonghex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), fd);
	}
	else
		ft_putchar_fd(*(base + nbr), fd);
}

void	ft_putupperhex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putupperhex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}
