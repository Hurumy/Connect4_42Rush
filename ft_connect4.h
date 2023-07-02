/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:36 by komatsud          #+#    #+#             */
/*   Updated: 2023/07/02 18:19:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONNECT4_H
# define FT_CONNECT4_H 
# include <stdlib.h>
# include <time.h>
# include <limits.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"

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
# define A_KEY			0
# define S_KEY			1
# define D_KEY			2
# define F_KEY			3

# define PLAYER_MOVE (1)
# define CPU_MOVE (2)

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
	void	*screen;
	void	*window;
	void	*tip_empty;
	void	*tip_player;
	void	*tip_cpu;
	void	*tip_cursor;
	void	*tip_base;
	int		cursor;
	size_t	input_mode;
}	t_info;

//ft_init.c
int		ft_is_num(char c);
int		ft_is_positive_num(char *str);
int		ft_atoi_rewrite(char *str);
int		ft_arg_to_number(int argc, char **argv, t_info *t_maps);
int		ft_init_map_row(t_info *t_maps, size_t y);
int		ft_malloc_maps(t_info *t_maps);
int		ft_init(int argc, char **argv, t_info *t_maps);
int		ft_is_positive_num(char *str);
int		ft_atoi_rewrite(char *str);

//ft_randomly_choose_first_move.c
int		ft_randomly_choose_first_move(t_info *t_maps);

//ft_draw_fields.c
int		ft_draw_field(t_info *t_maps);

//ft_get_move.c
int		ft_get_move(t_info *t_maps);
int		ft_move_by_player(void);
int		ft_move_by_cpu(t_info *t_maps, int turn_cnt);

//ft_add_pawn.c
int		ft_add_pawn(t_info *t_maps, size_t x, int player);

//ft_is_game_ended.c
int		ft_is_game_ended(t_info *t_maps, int turn_number, int where_to_put);

//ft_show_result.c
int		ft_show_result(t_info *t_maps);

//ft_error.c
void	ft_error(void);
void	ft_error_with_free(t_info *t_maps);

//ft_free.c
int		ft_free_double_pointer(t_info *t_maps);
int		ft_free(t_info *t_maps);

//ft_exit.c
int		ft_exit(t_info *t_maps);

//bonus
//ft_libx_connect4.c
int		main_libx(int argc, char **argv);

//ft_init_libx.c
int		ft_init_libx(int argc, char **argv, t_info *t_maps);
int		ft_arg_to_number_libx(int argc, char **argv, t_info *t_maps);

//ft_draw_tiles.c
int		ft_put_img(t_info *t_maps, char map, size_t x, size_t y);
int		ft_draw_field_libx(t_info *t_maps);

//ft_hooks.c
int		ft_set_keyhook(int keycode, t_info *t_maps);

//ft_free_libx.c
int		ft_free_libx(t_info *t_maps);

//ft_error_libx.c
void	ft_error_with_free_libx(t_info *t_maps);

//mlx.h?
void	*mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);

#endif
