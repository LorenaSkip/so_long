/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:46:22 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/13 11:10:57 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemies(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	move_to_gastly(t_game *game, t_tile *tile);
void	pick_pokeball(t_game *game, t_tile *tile);

void	effect_anim(t_effect *effect, t_vector pos)
{
	effect->counter = 0;
	effect->pos = pos;
}

/* animazione personaggio allo start */
void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

/* muovere il personaggio */
t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == POKEBALL)
		pick_pokeball(game, tile);
	else if (tile->type == EXIT && game->pokeball <= 0)
		move_to_exit(game, tile);
	else if (tile->type == GASTLY || tile->type == FOLLOWER)
	{
		move_to_gastly(game, tile);
		return (FALSE);
	}
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

/* controllo dei tasti che vengono premuti */
int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		game_end(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_W)
			moved = move_to(game, game->player.tile->up);
	else if (key == KEY_S)
			moved = move_to(game, game->player.tile->down);
	else if (key == KEY_A)
			moved = move_to(game, game->player.tile->left);
	else if (key == KEY_D)
			moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
		printf("MOSSE -> %02d\n", ++game->moves);
	return (1);
}
