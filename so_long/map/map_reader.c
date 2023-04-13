/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnitu <lnitu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:54:54 by lnitu             #+#    #+#             */
/*   Updated: 2023/04/04 11:08:53 by lnitu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../gnl/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

/* how many new line (\n) are in file */
static int	file_linecount(char *file)
{
	int		line;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 1)
			return (-1);
		if (c == '\n')
			line++;
	}
	close(fd);
	return (line);
}

/* just allocate memory for the same lines as the file in a string array */
static char	**allocate_columns(char *file)
{
	char	**map;
	int		linecount;

	linecount = file_linecount(file);
	if (linecount <= 0)
		return (null_error("Wait! open or reading file error..."));
	map = malloc(sizeof(char *) * linecount + 1);
	if (map == NULL)
		return (null_error("Wait! malloc error..."));
	return (map);
}

/* create with a map as found in file with malloc */
char	**map_reader(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = allocate_columns(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}
