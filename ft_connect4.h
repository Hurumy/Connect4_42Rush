/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:36 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/01 11:56:17 by komatsud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONNECT4_H
# define FT_CONNECT4_H 
# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"
//# include "get_next_line.h"

//////		**after add LIBFT, FIX PRINTF TO FT_PRINTF** 	//////

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

//x ->col	y ->row
//map[y][x], map[row][col];
//map[y][x] == 0 -> empty
//map[y][x] == 1 -> Players pawn
//map[y][x] == 2 -> AIs pawn
//1 <= y <= row
//1 <= x <= col
typedef struct s_info
{
	size_t	col;
	size_t	row;
	char	**maps;
	int		first_move;
	int		winner;
}	t_info;

//ft_init.c
int		ft_init(int argc, char **argv, t_info *t_maps);

//ft_randomly_choose_first_move.c
int		ft_randomly_choose_first_move(t_info *t_maps);

//ft_draw_fields.c
int		ft_draw_field(t_info *t_maps);

//ft_get_move.c
int		ft_get_move(t_info *t_maps);

//ft_add_pawn.c
int		ft_add_pawn(t_info *t_maps, size_t x, int player);

//ft_is_game_ended.c
int		ft_is_game_ended(t_info *t_maps, int turn_number, int where_to_put);

//ft_error.c
void	ft_error(void);
void	ft_error_with_free(t_info *t_maps);

//ft_free.c
int		ft_free_double_pointer(t_info *t_maps);
int		ft_free(t_info *t_maps);

//ft_exit.c
int		ft_exit(t_info *t_maps);


#endif