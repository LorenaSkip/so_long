/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:18:32 by lnitu             #+#    #+#             */
/*   Updated: 2023/03/31 10:51:31 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reset_gastly(t_gastly *gastly)
{
	if (gastly == NULL)
		return ;
	while (TRUE)
	{
		gastly->tile = gastly->og_tile;
		gastly->dir = 0;
		if (gastly->next == NULL)
			break ;
		gastly = gastly->next;
	}
}

int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->tilemap[y] != NULL)
	{
		x = 0;
		while (game->tilemap[y][x].type != 0)
		{
			game->tilemap[y][x].type = game->tilemap[y][x].og_type;
			if (game->tilemap[y][x].type == PLAYER)
				game->player.tile = &game->tilemap[y][x];
			x++;
		}
		y++;
	}
	reset_gastly(game->gastly_list);
	game->moves = 0;
	game->pokeball = game->og_pokeball;
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	return (0);
}
