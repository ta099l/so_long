/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:18:40 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/26 19:56:34 by tabuayya         ###   ########.fr       */
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

void	what_block(t_long *var, int r, int c)
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
			what_block(var, r, c);
			c++;
		}
		r++;
	}
}
void	
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
	mlx_hook(var->mlx_window. 2, 1L << 0, , var);
	mlx_key_hook(var->mlx_window,key_press, var);
	mlx_loop(var->mlx);
}
int	main(int argc, char **argv)
{
	t_long	*var;
	
	var = malloc(sizeof(t_long));
	if (!var)
		clean_exit(var, 1, "Failed to allocate memory\n"); //function
	if (argc != 2)
		clean_exit(var, 1, "Expected 2 arguments\n");
	error_extenstion(argv[1], var);
	read_map(var, argv[1]);
	//var->n_cols = ft_strlen(var->map[3]);
	//ft_printf("%i", var->n_cols);
	error_checking(var);
	print_map(var);
	mlx_function(var);
}

