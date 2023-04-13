/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:57:39 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/13 11:07:51 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
	{
		player->current_img = player->idle_img_1;
	}
	else if (player->framecount == player->idle_frames)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	pokeball_animation(t_pokeball_img *img)
{
	static int	frame;

	if (img->anim_frames == 0)
		return ;
	if (frame == img->anim_frames)
	{
		img->current_img = img->img_0;
	}
	else if (frame >= img->anim_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

static void	effect_animation(t_effect *effect)
{
	if (effect->counter < effect->frames)
		effect->counter++;
}

static void	gastly_animation(t_gastly_img *img)
{
	static int	basic_count;
	static int	follower_count;

	if (basic_count == img->basic_anim)
		img->basic_current = img->basic_1;
	else if (basic_count > img->basic_anim * 2)
	{
		img->basic_current = img->basic_2;
		basic_count = 0;
	}
	basic_count++;
	if (follower_count == img->follow_anim)
		img->follow_current = img->follow_1;
	else if (follower_count > img->follow_anim * 2)
	{
		img->follow_current = img->follow_2;
		follower_count = 0;
	}
	follower_count++;
}

int	update(t_game *game)
{
	player_animation(&game->player);
	pokeball_animation(&game->pokeball_imgs);
	effect_animation(&game->effect);
	gastly_animation(&game->gastly_imgs);
	render(*game);
	return (1);
}
