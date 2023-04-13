/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:55:18 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/05 10:32:44 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../utils.h"
# include "../so_long.h"

int		valid_file(int argc, char *file);
char	**map_reader(char *file);
int		valid_map(char **map);

typedef struct s_mapchecker
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_pokeball;
}	t_mapchecker;

void	add_gastly(t_game *game, t_gastlytype type, t_tile *tile);

#endif
