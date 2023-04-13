/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follower_moving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:01:35 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 10:45:31 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	move_horizontal(t_gastly *gastly, t_game *game);
t_bool	move_vertical(t_gastly *gastly, t_game *game);

int	define_dir(int value)
{
	if (value < 0)
		return (1);
	else if (value > 0)
		return (0);
	return (-1);
}

/* for move the gastly close to the player */
void	follow_player(t_gastly *gastly, t_game *game)
{
	int	dis_x;
	int	dis_y;

	if (game->player.tile == NULL)
		return ;
	dis_x = gastly->tile->position.x - game->player.tile->position.x;
	dis_y = gastly->tile->position.y - game->player.tile->position.y;
	if (dis_x > dis_y)
	{
		gastly->dir = define_dir(dis_x);
		if (!move_horizontal(gastly, game) || gastly->dir == -1)
		{
			gastly->dir = define_dir(dis_y);
			move_vertical(gastly, game);
		}
	}
	else
	{
		gastly->dir = define_dir(dis_y);
		if (!move_vertical(gastly, game) || gastly->dir == -1)
		{
			gastly->dir = define_dir(dis_x);
			move_horizontal(gastly, game);
		}
	}
}
