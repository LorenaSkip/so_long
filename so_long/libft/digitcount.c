/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digitcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:12:47 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:12:53 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_digitcount(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_hexlen(unsigned int num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	ft_hexlen_long(unsigned long num)
{
	int	count;

	count = 1;
	while (num >= 16)
	{
		num /= 16;
		count++;
	}
	return (count);
}
