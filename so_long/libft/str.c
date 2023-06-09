/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:28:56 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:28:58 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_wordcount(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != c && *str != '\0')
				str++;
		}
		else if (*str)
			str++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (src == NULL)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	dst_i;
	size_t	src_i;

	dst_len = ft_strlen(dst);
	dst_i = dst_len;
	src_i = 0;
	if (dstsize < dst_len + 1)
		return (dstsize + ft_strlen(src));
	if (dstsize > dst_len + 1)
	{
		while (src[src_i] != '\0')
		{
			dst[dst_i] = src[src_i];
			dst_i++;
			src_i++;
			if (dst_i == dstsize - 1)
				break ;
		}
	}
	dst[dst_i] = '\0';
	return (dst_len + ft_strlen(src));
}
