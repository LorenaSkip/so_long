/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gastlygen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:46:08 by lnitu             #+#    #+#             */
/*   Updated: 2023/03/30 11:58:43 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_gastly	*new_gastly(t_gastlytype type, t_tile *tile)
{
	t_gastly	*gastly;

	gastly = malloc(sizeof(t_gastly));
	if (gastly == NULL)
		return (null_error("malloc error on a new gastly..."));
	gastly->type = type;
	gastly->dir = 0;
	gastly->tile = tile;
	gastly->og_tile = gastly->tile;
	gastly->next = NULL;
	return (gastly);
}

t_gastly	*last_gastly(t_gastly *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_gastly(t_game *game, t_gastlytype type, t_tile *tile)
{
	t_gastly	*new;

	new = new_gastly(type, tile);
	if (new == NULL)
		return ;
	if (game->gastly_list == NULL)
		game->gastly_list = new;
	else
		last_gastly(game->gastly_list)->next = new;
}		
