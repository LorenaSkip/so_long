/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:44:54 by lnitu             #+#    #+#             */
/*   Updated: 2023/03/27 10:13:55 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	error(char *message)
{
	printf("\033[0;31m" "Error\n	%s\n" "\033[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("\033[0;31m" "Error\n	%s\n" "\033[0m", message);
	return (0);
}

void	warning(char *message)
{
	printf("\033[0;33m" "Warning\n	%s\n" "\033[0m", message);
}
