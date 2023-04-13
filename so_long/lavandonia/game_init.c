/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:13:00 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/11 11:08:06 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

void	open_images(t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = map_reader (argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, game_end, game);
	open_images(game);
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->pokeball_imgs.anim_frames = 25;
	game->effect.frames = 7;
	game->gastly_imgs.basic_anim = 16;
	game->gastly_imgs.follow_anim = 6;
}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->pokeball = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_pokeball = game->pokeball;
	anim_setup(game);
	game_init(game);
	return (TRUE);
}
