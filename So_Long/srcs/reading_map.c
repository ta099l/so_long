/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:41:36 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 20:06:00 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//reads number of rows
void	read_lines(t_long *var, char *path_map)
{
	int		fd;
	char	*line;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		clean_exit(var, 1, "Error: stupid, Failed to open the map\n");
	line = get_next_line(fd);
	if (!line)
	{
		close (fd);
		clean_exit(var, 1, "Error: stupid, Failed to read the map\n");
	}
	while (line)
	{
		var->n_rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

//reads map and stores each line in map
void	read_map(t_long *var, char *path_map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	read_lines(var, path_map);
	var->map = malloc(sizeof(char *) * (var->n_rows + 1));
	if (!var->map)
		clean_exit(var, 1, "Error: stupid, Malloc died\n");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		clean_exit(var, 1, "Error: stupid, Failed to open the map\n");
	line = get_next_line(fd);
	if (!line)
	{
		close (fd);
		clean_exit(var, 1, "Error: stupid, Failed to read the map\n");
	}
	while (line)
	{
		var->map[i++] = line;
		line = get_next_line(fd);
	}
	var->map[i] = NULL;
	close(fd);
}
