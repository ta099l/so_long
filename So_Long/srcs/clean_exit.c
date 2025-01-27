/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:24:25 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/26 15:40:48 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_2d_array(char  **array)
{
    int     r;

    r = 0;
    while(array[r])
        free(array[r++]);
    free(array);
}
void    images_destroy(t_long *var)
{
    if(var->p_front_img)
        mlx_destroy_image(var->mlx, var->p_front_img);
    if(var->p_back_img)
        mlx_destroy_image(var->mlx, var->p_back_img);
    if(var->p_right_img)
        mlx_destroy_image(var->mlx, var->p_right_img);
    if(var->p_left_img)
        mlx_destroy_image(var->mlx, var->p_left_img);
    if(var->d_open_img)
        mlx_destroy_image(var->mlx, var->d_open_img);
    if(var->d_closed_img)
        mlx_destroy_image(var->mlx, var->d_closed_img);
    if(var->collectable_img)
        mlx_destroy_image(var->mlx, var->collectable_img);
    if(var->wall_img)
        mlx_destroy_image(var->mlx, var->wall_img);
    if(var->floor_img)
        mlx_destroy_image(var->mlx, var->floor_img);  
}
int     clean_exit(t_long *var, int exit_code, char *message)
{
    if(var->map)
        free_2d_array(var->map);
    //if (var->map_cpy)
        //free_2d_array(var->map_cpy);
    //if (var->bonus_ptr)
        //free(var->bonus_ptr);
    images_destroy(var);
    if (var->mlx_window)
        mlx_destroy_window(var->mlx, var->mlx_window);
    if(var->mlx)
    {
        mlx_destroy_display(var->mlx);
        free(var->mlx);
    }
    if(var)
        free(var);
    if(exit_code == 1)
        ft_putstr_fd(message, 2);
    if(exit_code == 0)
        ft_putstr_fd(message, 1);
    exit(exit_code);
    }