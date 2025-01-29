/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:20:51 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 21:21:04 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_imgs(t_long *var, int x, int y)
{
	if (!(var->n_collectable == 0))
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->d_closed_img, x, y);
	else if (var->n_collectable == 0)
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->d_open_img, x, y);
}

void	block_type(t_long *var, int r, int c)
{
	int	block;
	int	x;
	int	y;

	x = c * WIDTH;
	y = r * HEIGHT;
	block = var->map[r][c];
	if (block == 'P')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->p_front_img, x, y);
	if (block == 'C')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->collectable_img, x, y);
	if (block == 'E')
		exit_imgs(var, x, y);
	if (block == '1')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->wall_img, x, y);
	if (block == '0')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->floor_img, x, y);
}

void	put_imgs(t_long *var)
{
	int	r;
	int	c;

	r = 0;
	while (var->map[r])
	{
		c = 0;
		while (var->map[r][c])
		{
			block_type(var, r, c);
			c++;
		}
		r++;
	}
	if (var->bonus_ptr)
		free(var->bonus_ptr);
	var->bonus_ptr = ft_itoa(var->n_moves);
	if (!var->bonus_ptr)
		clean_exit(var, 1, "Error: stupid, Malloc died\n");
	mlx_string_put(var->mlx, var->mlx_window,
		5, 25, 0xFFFFFF, "Number of moves");
	mlx_string_put(var->mlx, var->mlx_window,
		105, 25, 0xFFFFFF, var->bonus_ptr);
}
