/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:23:28 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/05 11:43:25 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_char(char c);
int	valid_uniquechar(char c, char checker, t_bool *bool);
int	valid_border(char c, t_vector point, t_vector size);

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("no argument..."));
	if (argc > 2)
		warning("only the first file would be used");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("map should be a .ber file"));
	return (1);
}

static t_mapchecker	init_checkerdata(char **map)
{
	t_mapchecker	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_pokeball = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

static int	checks(char **map, t_mapchecker *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
		return (error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
		data->b_pokeball = TRUE;
	return (TRUE);
}

int	valid_map(char **map)
{
	t_mapchecker	data;
	t_bool			valid;

	data = init_checkerdata(map);
	valid = TRUE;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != data.size.x)
			valid = error("map must be rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_pokeball)
		valid = error("there must be one 'P' and 'E', and at least one 'C'");
	return (valid);
}
