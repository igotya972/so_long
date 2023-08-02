/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:19:30 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/02 01:49:54 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Get_next_line/get_next_line.h"
# include "printf/libftprintf.h"
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef enum e_key_code
{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	W_KEY = 13,
	CLOSE_ICON = 17,
	ESC_KEY = 53,
	KEY_RELEASE = 3,
	LEFT_ARROW_KEY = 123,
	RIGHT_ARROW_KEY = 124,
	DOWN_ARROW_KEY = 125,
	UP_ARROW_KEY = 126
}			t_key_code;

typedef enum e_map_char
{
	WALL_CHAR = '1',
	PLAYER_CHAR = 'P',
	COIN_CHAR ='C',
	EXIT_CHAR = 'E',
	VOID_CHAR = '0'
}			t_map_char;

typedef struct s_axe
{
	int	x;
	int	y;
	int	len;
}		t_axe;

typedef struct s_solv
{
	int	pos_x;
	int	pos_y;
}		t_solv;

typedef struct s_players
{
	int		pos_x;
	int		pos_y;
	int		move;
	int		stored;
	int		key;
	int		step;
	t_axe	axe;
}			t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_axe	size;
}				t_data;

typedef struct s_sprites
{
	void	*player;
	void	*ground;
	void	*wall;
	t_data	*key;
	void	*exit;
}			t_sprites;

typedef struct s_game
{
	t_sprites	sprite;
	char		**map;
	char		**map_bis;
	t_axe		size_map;
	void		*mlx;
	void		*mlx_win;
	t_data		wall;
	t_data		p_pos;
	t_data		v_zero;
	t_data		c_collector;
	t_data		e_exit;
	t_player	player;
}				t_game;

/*	src/parsing.C	*/
void	create_map(char *file, t_game *game);
void	count_map_xy(char *file, t_game *game);
void	ft_init_game(char **av, t_game *game);
/*	src/check_error.c	*/
void	print_error(char *str);
void	check_element_map(t_game *game);
int		check_search_element(t_game *game, char c);
void	check_rectangular_map(t_game *game);
/*	src/check_error_bis.c	*/
void	check_wall_map(t_game *game);
int		check_extension(char *file);
int		exit_game(t_game *game);
/*	libft/libft	*/
//int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
/*	src/picture_utils	*/
void	ft_put_all_sprites(t_game *game, int width, int height);
void	put_picture(t_game *groot, t_data pic, int x, int y);
void	insert_picture(t_game *game);
void	ft_print_map(t_game *game);
void	ft_print_map_p(t_game *game);
/*	src/player.c	*/
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		key_press(int key_code, t_game *game);
/*	src/player_collect_and exit.c	*/
int		ft_collect_item(t_game *game);
/*	src/resolve_map.c	*/
void	create_map_bis(char *file, t_game *game);
void	resolve_map(char **map, t_solv size, t_solv cur);
void	resolv(char	**map, t_solv size, t_solv begin);
void	solver(t_game game, char **av);

#endif