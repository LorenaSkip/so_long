/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wall_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:08:31 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/07 15:59:23 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_wallimgs_up(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_02.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.up_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_ul.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.up_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_ur.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.up = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_u.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.right = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_r.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_wallimgs_down(t_game *game)
{
	game->wall_imgs.down_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_dr.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.down_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_dl.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.down = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_d.xpm", &game->img_size.x, &game->img_size.y);
	game->wall_imgs.left = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall_l.xpm", &game->img_size.x, &game->img_size.y);
}
