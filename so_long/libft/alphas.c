/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:12:13 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:12:25 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isupperalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (0);
	return (-1);
}

int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 'a')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isalpha(c) && c <= 'Z')
		return (c + 32);
	return (c);
}
