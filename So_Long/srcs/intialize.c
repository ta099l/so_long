/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:58:16 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 20:33:03 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_variables(t_long *var)
{
	var->map = NULL;
	var->c_map = NULL;
	var->n_rows = 0;
	var->n_cols = 0;
	var->n_player = 0;
	var->n_collectable = 0;
	var->n_exit = 0;
	var->player_y = 0;
	var->player_x = 0;
	var->n_moves = 0;
	var->cpy_n_collectable = 0;
	var->flag = 0;
	var->mlx = NULL;
	var->mlx_window = NULL;
	var->p_front_img = NULL;
	var->p_back_img = NULL;
	var->p_right_img = NULL;
	var->p_left_img = NULL;
	var->d_open_img = NULL;
	var->d_closed_img = NULL;
	var->collectable_img = NULL;
	var->wall_img = NULL;
	var->floor_img = NULL;
	var->bonus_ptr = NULL;
}
