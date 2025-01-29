/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:01:27 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/29 21:39:58 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_extenstion(char *ext, t_long *var)
{
	int	len;

	len = ft_strlen(ext);
	if ((len <= 4) || !(ext[len - 4] == '.' && ext[len - 3] == 'b'
			&& ext[len - 2] == 'e' && ext[len - 1] == 'r'))
		clean_exit(var, 1, "Error: stupid, Extention is not correct\n");
}

void	error_borders(t_long *var)
{
	int	i;

	i = 0;
	while (i < var->n_cols)
	{
		if (!(var->map[0][i] == '1'))
			clean_exit(var, 1, "Error: stupid, Borders are not correct1\n");
		i++;
	}
	i = 1;
	while (i < var->n_rows - 1)
	{
		if (!(var->map[i][0] == '1') || !(var->map[i][var->n_cols - 1] == '1'))
			clean_exit(var, 1, "Error: stupid, Borders are not correct2\n");
		i++;
	}
	i = 0;
	while (i < var->n_cols)
	{
		if (!(var->map[var->n_rows - 1][i] == '1'))
			clean_exit(var, 1, "Error: stupid, Borders are not correct3\n");
		i++;
	}
}

void	error_rectangle(t_long *var)
{
	int	i;
	int	len;

	len = 0;
	i = 1;
	var->n_cols = ft_strlen(var->map[0]) - 1;
	while (i < var->n_rows)
	{
		len = ft_strlen(var->map[i]) - 1;
		if (!(var->n_cols == len))
			clean_exit(var, 1, "Error: stupid, Lines length is not correct\n");
		i++;
	}
}

void	check_elements(t_long *var)
{
	int	r;
	int	c;

	r = 0;
	while (var->map[r])
	{
		c = 0;
		while (var->map[r][c] != '\n')
		{
			if (!((var->map[r][c] == 'P') || (var->map[r][c] == 'C')
				|| (var->map[r][c] == 'E') || (var->map[r][c] == '1')
					|| (var->map[r][c] == '0')))
				clean_exit(var, 1, "Error: stupid, Elements are not correct\n");
			if (var->map[r][c] == 'P')
				var->n_player++;
			if (var->map[r][c] == 'C')
				var->n_collectable++;
			if (var->map[r][c] == 'E')
				var->n_exit++;
			c++;
		}
		r++;
	}
	if ((var->n_player != 1) || (var->n_collectable < 1) || (var->n_exit != 1))
		clean_exit(var, 1, "Error: stupid, Elements are not correct\n");
}

void	error_checking(t_long *var)
{
	error_rectangle(var);
	error_borders(var);
	check_elements(var);
}
