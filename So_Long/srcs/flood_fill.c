/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:15:27 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/30 18:22:37 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map_and_allocate(t_long *var)
{
	int	x;
	int	y;

	x = 0;
	var->c_map = malloc(sizeof(char *) * (var->n_rows + 1));
	if (!var->c_map)
		clean_exit(var, 1, "Malloc Died\n");
	while (x < var->n_rows)
	{
		y = 0;
		var->c_map[x] = malloc(sizeof(char) * (var->n_cols + 1));
		if (!var->c_map[x])
			clean_exit(var, 1, "Malloc Died\n");
		while (y < var->n_cols)
		{
			var->c_map[x][y] = var->map[x][y];
			y++;
		}
		var->c_map[x][y] = '\0';
		x++;
	}
	var->c_map[x] = NULL;
}

void	flood_fill(t_long *var, int x, int y)
{
	if (var->c_map[y][x] == '1')
		return ;
	if (var->c_map[y][x] == 'C')
		var->cpy_n_collectable--;
	if (var->c_map[y][x] == 'E')
	{
		var->flag = 1;
		return ;
	}
	var->c_map[y][x] = '1';
	flood_fill(var, x + 1, y);
	flood_fill(var, x - 1, y);
	flood_fill(var, x, y + 1);
	flood_fill(var, x, y - 1);
}

void	map_solvability(t_long *var)
{
	flood_fill(var, var->player_x, var->player_y);
	if (var->cpy_n_collectable > 0 || var->flag == 0)
		clean_exit(var, 1, "Error: stupid, map stupid\n");
}
