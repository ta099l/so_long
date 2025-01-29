/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:18:40 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 21:46:32 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_long *var)
{
	int	r;
	int	c;

	r = 0;
	while (var->map[r])
	{
		c = 0;
		while (var->map[r][c])
		{
			if (var->map[r][c] == 'P')
			{
				var->player_x = c;
				var->player_y = r;
				return ;
			}
			c++;
		}
		r++;
	}
}

void	mlx_function(t_long	*var)
{
	var->mlx = mlx_init();
	if (!var->mlx)
		clean_exit(var, 1, "Failed to initialize mlx connection\n");
	var->mlx_window = mlx_new_window(var->mlx,
			var->n_cols * WIDTH, var->n_rows * HEIGHT, "Zombie's Lunch\n");
	if (!var->mlx_window)
		clean_exit(var, 1, "Failed to open a window\n");
	convert_imgs(var);
	put_imgs(var);
	mlx_hook(var->mlx_window, 17, 0, clean_exit, var);
	mlx_hook(var->mlx_window, 2, 1L << 0, key_press, var);
	mlx_loop(var->mlx);
}

int	main(int argc, char **argv)
{
	t_long	*var;

	var = malloc(sizeof(t_long));
	if (!var)
		clean_exit(var, 1, "Error: stupid, Failed to allocate memory\n");
	initialize_variables(var);
	if (argc != 2)
		clean_exit(var, 1, "Error: stupid, Expected 2 arguments\n");
	error_extenstion(argv[1], var);
	read_map(var, argv[1]);
	var->n_cols = ft_strlen(var->map[0]);
	error_checking(var);
	player_position(var);
	copy_map_and_allocate(var);
	var->cpy_n_collectable = var->n_collectable;
	map_solvability(var);
	mlx_function(var);
	return (0);
}
