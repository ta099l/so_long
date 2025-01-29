/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:18:31 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 21:18:47 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_dir(t_long *var, char dir)
{
	int		x;
	int		y;

	x = var->player_x * WIDTH;
	y = var->player_y * HEIGHT;
	if (dir == 'U')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->p_back_img, x, y);
	if (dir == 'D')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->p_front_img, x, y);
	if (dir == 'L')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->p_left_img, x, y);
	if (dir == 'R')
		mlx_put_image_to_window(var->mlx,
			var->mlx_window, var->p_right_img, x, y);
}

void	move_player_pt2(t_long *var, int x_new, int y_new, char dir)
{
	var->map[var->player_y][var->player_x] = '0';
	var->map[y_new][x_new] = 'P';
	var->player_x = x_new;
	var->player_y = y_new;
	var->n_moves++;
	ft_printf("Number of Moves: %i\n", var->n_moves);
	put_imgs(var);
	player_dir(var, dir);
}

void	move_player(t_long *var, int x, int y, char dir)
{
	int	x_new;
	int	y_new;

	x_new = var->player_x + x;
	y_new = var->player_y + y;
	if (!(var->map[y_new][x_new] == '1'))
	{
		if (var->map[y_new][x_new] == 'C')
		{
			var->n_collectable--;
			var->map[y_new][x_new] = '0';
		}
		if (var->map[y_new][x_new] == 'E')
		{
			if (var->n_collectable == 0)
				clean_exit(var, 0, "Die\n");
			else
				return ;
		}
		move_player_pt2(var, x_new, y_new, dir);
	}
}

int	key_press(int keycode, t_long *var)
{
	if (keycode == XK_Escape)
		clean_exit(var, 0, "Escape\n");
	if (keycode == XK_Up)
		move_player(var, 0, -1, 'U');
	if (keycode == XK_Down)
		move_player(var, 0, 1, 'D');
	if (keycode == XK_Left)
		move_player(var, -1, 0, 'L');
	if (keycode == XK_Right)
		move_player(var, 1, 0, 'R');
	return (0);
}
