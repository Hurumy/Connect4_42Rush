/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:36 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 10:01:07 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONNECT4_H
# define FT_CONNECT4_H 
# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>
//# include "libft.h"
//# include "ft_printf.h"
//# include "get_next_line.h"

//colors
# define RESET_COLOR	"\033[0m"
# define BLACK   		"\033[30m"
# define RED     		"\033[31m"
# define GREEN   		"\033[32m"
# define YELLOW  		"\033[33m"
# define BLUE    		"\033[34m"
# define MAGENTA 		"\033[35m"
# define CYAN    		"\033[36m"
# define WHITE   		"\033[37m"
# define GREY    		"\033[90m"
# define PLAYER_PAWN	GREEN"●"RESET_COLOR
# define AI_PAWN		RED"◆"RESET_COLOR

//x ->col
//y ->row
//map[y][x], map[row][col];
//map[y][x] == 0 -> empty
//map[y][x] == 1 ->first movers pawn
//map[y][x] == 2 ->second movers pawn
typedef struct s_info
{
	size_t	col;
	size_t	row;
	char	**maps;
	int		first_move;
}	t_info;

//ft_init.c
int		ft_init(int argc, char **argv, t_info *t_maps);

//ft_draw_fiels.c
int		ft_draw_field(t_info *t_maps);

//ft_error.c
void	ft_error(void);
void	ft_error_with_free(t_info *t_maps);

//ft_free.c
int		ft_free_double_pointer(char **map);
int		ft_free(t_info *t_maps);


#endif