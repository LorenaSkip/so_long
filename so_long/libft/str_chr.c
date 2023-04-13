/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:26:57 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:26:59 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (*(str + len) == (char)c)
			return ((char *)str + len);
	}
	return (NULL);
}

char	*ft_strdiffc(const char *str, const char *set)
{
	if (str != NULL && set != NULL)
	{
		while (*str)
		{
			if (!ft_strchr(set, *str))
				return ((char *)str);
			str++;
		}
		if (!ft_strchr(set, *str))
			return ((char *)str);
	}
	return (NULL);
}

char	*ft_strrdiffc(const char *str, const char *set)
{
	int	len;

	if (str != NULL && set != NULL)
	{
		len = ft_strlen(str);
		while (len >= 0)
		{
			if (!ft_strchr(set, *(str + len)))
				return ((char *)str + len);
			len--;
		}
		if (!ft_strchr(set, *str))
			return ((char *)str + len);
	}
	return (NULL);
}
