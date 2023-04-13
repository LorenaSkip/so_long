/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:25:52 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:25:54 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writenbr(long long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		writenbr(nbr * -1, fd);
	}
	else if (nbr > 0)
	{
		writenbr(nbr / 10, fd);
		ft_putchar_fd('0' + (nbr % 10), fd);
	}
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}

void	ft_putlong_fd(long nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}
