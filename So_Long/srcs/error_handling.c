/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabuayya <tabuayya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:01:27 by tabuayya          #+#    #+#             */
/*   Updated: 2025/01/28 13:11:15 by tabuayya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    error_extenstion(char *ext, t_long *var)
{
    int len;
    
    len = ft_strlen(ext);
    if ( (len <= 4) || !(ext[len-4] == '.' && ext[len-3] == 'b' && ext[len-2] == 'e' && ext[len-1] == 'r'))
	{
		ft_printf("Error: stupid");
		clean_exit(var, 1, "Extention is not correct\n"); //function
	}
}
void    error_borders(t_long *var)
{
    int     i;  
    
    i = 0;
    //ft_printf("%d", var->n_cols);
    while (i < var->n_cols)
    {
        //ft_printf("%i\n", var->map[0][i]);
        if(!(var->map[0][i] == '1'))
            clean_exit(var, 1, "Borders are not correct1\n"); //function
        
        i++;
    }
    i = 1;
    while(i < var->n_rows - 1)
	{
        //ft_printf("%d", var->n_cols);
		if(!(var->map[i][0] == '1') || !(var->map[i][var->n_cols - 1] == '1')) 
			clean_exit(var, 1, "Borders are not correct2\n"); //function
		i++;
	}
    i = 0;
    while (i < var->n_cols)
    {
        if(!(var->map[var->n_rows - 1][i] == '1'))
           clean_exit(var, 1, "Borders are not correct3\n"); //function
        i++;
    }
}
void    error_rectangle(t_long *var)
{
    int     i;
    int     len;

    len = 0;
    i = 1;
    var->n_cols = ft_strlen(var->map[0]) - 1;
    while(i < var->n_rows)
    {
        len = ft_strlen(var->map[i]) - 1;
        if (!(var->n_cols == len))
            clean_exit(var, 1, "Lines lingth is not correct\n"); //function
        i++;
    }
}
void    check_elements(t_long *var)
{
    int     r = 0;
    int     c = 0;
    
    while(var->map[r])
	{
		c = 0;
		while(var->map[r][c] != '\n')
		{
			if(!((var->map[r][c] == 'P') || (var->map[r][c] == 'C') || (var->map[r][c] == 'E') || (var->map[r][c] == '1') || (var->map[r][c] == '0')))
                clean_exit(var, 1, "yaman-Elements are not correct\n"); //function
            if (var->map[r][c] == 'P')
            {
                var->n_player++;
                //var->player_x = c;
                //var->player_y = r;
            }
            if (var->map[r][c] == 'C')
                var->n_collectable++;
            if (var->map[r][c] == 'E')
                var->n_exit++;   
			c++;
		}
		r++;
	}
    if ((var->n_player != 1) || (var->n_collectable < 1) || (var->n_exit != 1))
        clean_exit(var, 1, "2-Elements are not correct\n"); //function
}
void    error_checking(t_long *var)
{
    error_rectangle(var);
    error_borders(var);
    check_elements(var);
}
