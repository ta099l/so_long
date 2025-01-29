/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:18:31 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 18:13:28 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_lib/includes/libft.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <stdlib.h>

#define HEIGHT 49
#define WIDTH 50

typedef struct s_long
{
    char    **map;
    char    **c_map;
    int     n_rows;
    int     n_cols;
    int     n_player;
    int     n_collectable;
    int     n_exit;
    int     player_y;
    int     player_x;
    int     n_moves;
    int     cpy_n_collectable;
    int     flag;
    void    *mlx;
    void    *mlx_window;
    void    *p_front_img;
    void    *p_back_img;
    void    *p_right_img;
    void    *p_left_img;
    void    *d_open_img;
    void    *d_closed_img;
    void    *collectable_img;
    void    *wall_img;
    void    *floor_img;
    
}     t_long;

void    read_lines(t_long *var, char *path_map);
void    read_map(t_long *var, char   *path_map);
void	print_map(t_long *var);
int     main(int argc, char **argv);
void    error_extenstion(char *ext, t_long *var);
void    error_checking(t_long *var);
void	mlx_function(t_long	*var);
void	put_imgs(t_long *var);
void	what_block(t_long *var, int r, int c);
void	convert_imgs(t_long *var);
void	convert_imgs_prt2(t_long *var, int x ,int y);
int     clean_exit(t_long *var, int exit_code, char *message);
void    initialize_variables(t_long *var);
#endif
