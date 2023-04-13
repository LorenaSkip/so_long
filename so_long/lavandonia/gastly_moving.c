/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gastly_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:58:49 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/05 11:27:03 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	follow_player(t_gastly *gastly, t_game *game);

void	move_gastly_to(t_gastly *gastly, t_tile *tile)
{
	gastly->tile->type = EMPTY;
	if (gastly->type == FOLLOW_GASTLY)
		tile->type = FOLLOWER;
	else
		tile->type = GASTLY;
	gastly->tile = tile;
}

t_bool	change_dir(t_gastly *gastly)
{
	if (gastly->dir == 0)
		gastly->dir = 1;
	else
		gastly->dir = 0;
	return (FALSE);
}

t_bool	move_horizontal(t_gastly *gastly, t_game *game)
{
	if (gastly->dir == 0)
	{
		if (gastly->tile->left->type == EMPTY)
			move_gastly_to(gastly, gastly->tile->left);
		else if (gastly->tile->left->type == PLAYER)
		{
			move_gastly_to(gastly, gastly->tile->left);
			kill_player(game, gastly->tile->position);
		}
		else
			return (change_dir(gastly));
	}
	else if (gastly->dir == 1)
	{
		if (gastly->tile->right->type == EMPTY)
			move_gastly_to(gastly, gastly->tile->right);
		else if (gastly->tile->right->type == PLAYER)
		{
			move_gastly_to(gastly, gastly->tile->right);
			kill_player(game, gastly->tile->position);
		}
		else
			return (change_dir(gastly));
	}
	return (TRUE);
}

t_bool	move_vertical(t_gastly *gastly, t_game *game)
{
	if (gastly->dir == 0)
	{
		if (gastly->tile->up->type == EMPTY)
			move_gastly_to(gastly, gastly->tile->up);
		else if (gastly->tile->up->type == PLAYER)
		{
			move_gastly_to(gastly, gastly->tile->up);
			kill_player(game, gastly->tile->position);
		}
		else
			return (change_dir(gastly));
	}
	else if (gastly->dir == 1)
	{
		if (gastly->tile->down->type == EMPTY)
			move_gastly_to(gastly, gastly->tile->down);
		else if (gastly->tile->down->type == PLAYER)
		{
			move_gastly_to(gastly, gastly->tile->down);
			kill_player(game, gastly->tile->position);
		}
		else
			return (change_dir(gastly));
	}
	return (TRUE);
}

void	move_enemies(t_game *game)
{
	t_gastly	*current;

	if (game->gastly_list == NULL)
		return ;
	current = game->gastly_list;
	while (TRUE)
	{
		if (current->type == HORIZONTAL_GASTLY)
			move_horizontal(current, game);
		else if (current->type == VERTICAL_GASTLY)
			move_vertical(current, game);
		else if (current->type == FOLLOW_GASTLY)
			follow_player(current, game);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}
