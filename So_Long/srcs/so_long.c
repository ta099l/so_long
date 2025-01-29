/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:18:40 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 18:28:16 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_long *var)
{
	int	r = 0;
	int	c;
	
	while(var->map[r])
	{
		c = 0;
		while(var->map[r][c])
		{
			ft_printf("%c", var->map[r][c]);
			c++;
		}
		r++;
	}
}
void	copy_map_and_allocate(t_long *var)
{
	int		x = 0;
	int		y;
	var->c_map =  malloc(sizeof(char *) * (var->n_rows + 1));
	if(!var->c_map)
			clean_exit(var, 1, "malloc");
	while(x < var->n_rows)
	{
		y = 0;
		var->c_map[x] = malloc(sizeof(char) * (var->n_cols + 1));
		if(!var->c_map)
			clean_exit(var, 1, "malloc");
		while(y < var->n_cols)
		{
			var->c_map[x][y] = var->map[x][y];
			y++;
		}
		var->c_map[x][y] = '\0';
		x++;
	}
	var->c_map[x] = NULL;
}
void	player_position(t_long *var)
{
	int	r = 0;
	int	c;
	
	while(var->map[r])
	{
		c = 0;
		while(var->map[r][c])
		{
			if (var->map[r][c] == 'P')
			{
				var->player_x = c;
				var->player_y = r;
				return;
			}
			c++;
		}
		r++;
	}
}
void	convert_imgs_prt2(t_long *var, int x ,int y)
{
	var->d_open_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/Coffin_open.xpm", &x, &y);
	if (!var->d_open_img)
		clean_exit(var, 1, "can't find one of the images5\n"); //function
	var->d_closed_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/Coffin_closed.xpm", &x, &y);
	if (!var->d_closed_img)
		clean_exit(var, 1, "can't find one of the images6\n"); //function
	var->collectable_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/brain.xpm", &x, &y);
	if (!var->collectable_img)
		clean_exit(var, 1, "can't find one of the images7\n"); //function
	var->wall_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/Wall.xpm", &x, &y);
	if (!var->wall_img)
		clean_exit(var, 1, "can't find one of the images8\n"); //function
	var->floor_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/Floor.xpm", &x, &y);
	if (!var->floor_img)
		clean_exit(var, 1, "can't find one of the images9\n"); //function
}
void	convert_imgs(t_long *var)
{
	int		x;
	int		y;

	x = WIDTH;
	y = HEIGHT;
	var->p_front_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/MonsterF.xpm", &x, &y);
	if (!var->p_front_img)
		clean_exit(var, 1, "can't find one of the images\n"); //function
	var->p_back_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/MonsterB.xpm", &x, &y);
	if (!var->p_back_img)
		clean_exit(var, 1, "can't find one of the images\n"); //function
	var->p_right_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/MonsterR.xpm", &x, &y);
	if (!var->p_right_img)
		clean_exit(var, 1, "can't find one of the images\n"); //function
	var->p_left_img = mlx_xpm_file_to_image(var->mlx, "./srcs/textures/MonsterL.xpm", &x, &y);
	if (!var->p_left_img)
		clean_exit(var, 1, "can't find one of the images\n"); //function
	convert_imgs_prt2(var, x, y);
}

void	block_type(t_long *var, int r, int c)
{
	int		block;
	int		x;
	int		y;

	x = c * WIDTH;
	y = r * HEIGHT;

	block = var->map[r][c];
	if (block == 'P')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->p_front_img, x, y);
	if (block == 'C')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->collectable_img, x, y);
	if (block == 'E')
	{
		if(!(var->n_collectable == 0)) 
			mlx_put_image_to_window(var->mlx, var->mlx_window, var->d_closed_img, x, y);
		else if(var->n_collectable == 0)
			mlx_put_image_to_window(var->mlx, var->mlx_window, var->d_open_img, x, y);
	}
	if (block == '1')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->wall_img, x, y);
	if (block == '0')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->floor_img, x, y);
}
void	put_imgs(t_long *var)
{
	int	r;
	int	c;
	
	r = 0;
	while(var->map[r])
	{
		c = 0;
		while(var->map[r][c])
		{
			block_type(var, r, c);
			c++;
		}
		r++;
	}
}
void	player_dir(t_long *var, char dir)
{
	int		x;
	int		y;

	x = var->player_x * WIDTH;
	y = var->player_y * HEIGHT;		
	if (dir == 'U')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->p_back_img, x, y);
	if (dir == 'D')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->p_front_img, x, y);
	if (dir == 'L')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->p_left_img, x, y);
	if (dir == 'R')
		mlx_put_image_to_window(var->mlx, var->mlx_window, var->p_right_img, x, y);
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
		if(var->map[y_new][x_new] == 'E')
		{
			if(var->n_collectable == 0)
				clean_exit(var, 0, "Die\n");
			else
				return;	
		}
		move_player_pt2(var, x_new, y_new, dir);
	}
}
int	key_press(int keycode, t_long *var)
{
	if(keycode == XK_Escape)
		clean_exit(var, 0, "Escape\n");
	if(keycode == XK_Up)
		move_player(var, 0, -1, 'U');
	if(keycode == XK_Down)
		move_player(var, 0, 1, 'D');
	if(keycode == XK_Left)
		move_player(var, -1, 0, 'L');
	if(keycode == XK_Right)
		move_player(var, 1, 0, 'R');
	return (0);
}
void	mlx_function(t_long	*var)
{
	var->mlx = mlx_init();
	if(!var->mlx)
		clean_exit(var, 1, "Failed to initialize mlx connection\n"); //function
	var->mlx_window = mlx_new_window(var->mlx, var->n_cols * WIDTH, var->n_rows * HEIGHT, "Zombie's Lunch");
	if(!var->mlx_window)
		clean_exit(var, 1, "Failed to open a window\n"); //function
	convert_imgs(var);
	put_imgs(var);
	mlx_hook(var->mlx_window, 17, 0 , clean_exit, var);
	mlx_hook(var->mlx_window, 2, 1L << 0, key_press, var);
	mlx_loop(var->mlx);
}
void	flood_fill(t_long *var, int x, int y)
{
	if (var->c_map[y][x] == '1')
		return;
	if (var->c_map[y][x] == 'C')
		var->cpy_n_collectable--;
	if (var->c_map[y][x] == 'E')
		var->flag = 1;
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
		clean_exit(var, 1, "map stupid");
}
int	main(int argc, char **argv)
{
	t_long	*var;
	
	var = malloc(sizeof(t_long));

	initialize_variables(var);	
	if (!var)
		clean_exit(var, 1, "Failed to allocate memory\n"); //function
	if (argc != 2)
		clean_exit(var, 1, "Expected 2 arguments\n");
	error_extenstion(argv[1], var);
	read_map(var, argv[1]);
	var->n_cols = ft_strlen(var->map[0]);
	//ft_printf("%i", var->n_cols);
	error_checking(var);
	player_position(var);
	copy_map_and_allocate(var);
	var->cpy_n_collectable = var->n_collectable;
	map_solvability(var);
	print_map(var);
	mlx_function(var);
}

