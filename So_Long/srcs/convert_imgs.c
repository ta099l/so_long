/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:22:21 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 21:48:13 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_imgs_prt2(t_long *var, int x, int y)
{
	var->d_open_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/Coffin_open.xpm", &x, &y);
	if (!var->d_open_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->d_closed_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/Coffin_closed.xpm", &x, &y);
	if (!var->d_closed_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->collectable_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/brain.xpm", &x, &y);
	if (!var->collectable_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->wall_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/Wall.xpm", &x, &y);
	if (!var->wall_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->floor_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/Floor.xpm", &x, &y);
	if (!var->floor_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
}

void	convert_imgs(t_long *var)
{
	int	x;
	int	y;

	x = WIDTH;
	y = HEIGHT;
	var->p_front_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/MonsterF.xpm", &x, &y);
	if (!var->p_front_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->p_back_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/MonsterB.xpm", &x, &y);
	if (!var->p_back_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->p_right_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/MonsterR.xpm", &x, &y);
	if (!var->p_right_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	var->p_left_img = mlx_xpm_file_to_image(var->mlx,
			"./srcs/textures/MonsterL.xpm", &x, &y);
	if (!var->p_left_img)
		clean_exit(var, 1, "Error: stupid, can't find one of the images\n");
	convert_imgs_prt2(var, x, y);
}
