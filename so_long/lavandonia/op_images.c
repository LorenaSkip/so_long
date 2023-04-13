/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:47:17 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/13 11:00:56 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_wallimgs_up(t_game *game);
void	open_wallimgs_down(t_game *game);

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_02.xpm", &game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_03.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

static void	open_pokeball_imgs(t_game *game)
{
	game->pokeball_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/pokeball_1.xpm",
			&game->img_size.x, &game->img_size.y);
	game->pokeball_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/pokeball_2.xpm",
			&game->img_size.x, &game->img_size.y);
	game->pokeball_imgs.current_img = game->pokeball_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"sprites/effect.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_gastly_imgs(t_game *game)
{
	game->gastly_imgs.basic_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_01.xpm", &game->img_size.x, &game->img_size.y);
	game->gastly_imgs.basic_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_02.xpm", &game->img_size.x, &game->img_size.y);
	game->gastly_imgs.basic_current = game->gastly_imgs.basic_1;
	game->gastly_imgs.follow_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_03.xpm", &game->img_size.x, &game->img_size.y);
	game->gastly_imgs.follow_2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_04.xpm", &game->img_size.x, &game->img_size.y);
	game->gastly_imgs.follow_current = game->gastly_imgs.follow_1;
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_wallimgs_up (game);
	open_wallimgs_down (game);
	open_player_imgs(game);
	open_pokeball_imgs(game);
	open_gastly_imgs(game);
	open_door_imgs(game);
}
