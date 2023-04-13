/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:13:47 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:13:52 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lettercount(const char *str, char c)
{
	int	lcount;

	lcount = 0;
	while (str[lcount] != c && str[lcount] != '\0')
		lcount++;
	return (lcount);
}

char	**ft_split(const char *str, char c)
{
	char	**output;
	int		wordcount;
	int		wordindex;
	int		lettercount;

	if (str == NULL)
		return (NULL);
	wordcount = ft_wordcount(str, c);
	output = malloc(sizeof(char *) * wordcount + 1);
	if (output == NULL)
		return (NULL);
	wordindex = 0;
	while (wordindex < wordcount)
	{
		while (*str == c)
			str++;
		lettercount = ft_lettercount(str, c);
		output[wordindex] = ft_substr(str, 0, lettercount);
		if (output[wordindex] == NULL)
			return (NULL);
		str += lettercount;
		wordindex++;
	}
	output[wordindex] = NULL;
	return (output);
}
