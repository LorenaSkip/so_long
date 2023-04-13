/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:23:05 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/13 10:49:20 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

void	free_enemies(t_game *game)
{
	t_gastly	*next;

	if (game->gastly_list == NULL)
		return ;
	while (TRUE)
	{
		next = game->gastly_list->next;
		free (game->gastly_list);
		if (next == NULL)
			break ;
		game->gastly_list = next;
	}
}

int	game_end(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	free_enemies(game);
	game->gastly_list = NULL;
	exit(0);
}	
