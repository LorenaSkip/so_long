/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:18:36 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:19:38 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*auxstr;
	int				i;

	i = 0;
	auxstr = (unsigned char *)str;
	while (i < (int)n)
	{
		auxstr[i] = c;
		i++;
	}
	return (str);
}

void	ft_bzero(void *target, size_t n)
{
	ft_memset(target, '\0', n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*auxdest;
	char	*auxsrc;
	int		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	while (i < (int)n)
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, void *src, size_t len)
{
	void	*og;

	if (dest == NULL && src == NULL)
		return (NULL);
	og = dest;
	if (dest < src)
		ft_memcpy(dest, src, len);
	else
	{
		while (len--)
		{
			*((unsigned char *)dest + len) = *((unsigned char *)src + len);
		}
	}
	return (og);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*auxdst;
	unsigned char	*auxsrc;
	int				i;

	auxdst = (unsigned char *)dst;
	auxsrc = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		auxdst[i] = auxsrc[i];
		if (auxsrc[i] == (unsigned char)c)
			return (&auxdst[i + 1]);
		i++;
	}
	return (NULL);
}
