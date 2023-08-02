/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:13:36 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/01 17:15:11 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key_code, t_game *game)
{
	if (key_code == ESC_KEY || key_code == 65307)
		exit_game(game);
	if (key_code == W_KEY || key_code == UP_ARROW_KEY || key_code == 119)
		ft_move_up(game);
	if (key_code == S_KEY || key_code == DOWN_ARROW_KEY || key_code == 115)
		ft_move_down(game);
	if (key_code == A_KEY || key_code == LEFT_ARROW_KEY || key_code == 97)
		ft_move_left(game);
	if (key_code == D_KEY || key_code == RIGHT_ARROW_KEY || key_code == 100)
		ft_move_right(game);
	ft_print_map(game);
	return (EXIT_SUCCESS);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player.pos_x - 1][game->player.pos_y] == EXIT_CHAR)
	{
		if (0 == ft_collect_item(game))
			exit_game(game);
		else
			return ;
	}
	if (game->map[game->player.pos_x - 1][game->player.pos_y] == WALL_CHAR)
		return ;
	game->map[game->player.pos_x - 1][game->player.pos_y] = PLAYER_CHAR;
	game->map[game->player.pos_x][game->player.pos_y] = VOID_CHAR;
	ft_printf("Step : %d\n", game->player.step);
	game->player.step++;
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player.pos_x + 1][game->player.pos_y] == EXIT_CHAR)
	{
		if (0 == ft_collect_item(game))
			exit_game(game);
		else
			return ;
	}
	if (game->map[game->player.pos_x + 1][game->player.pos_y] == WALL_CHAR)
		return ;
	game->map[game->player.pos_x + 1][game->player.pos_y] = PLAYER_CHAR;
	game->map[game->player.pos_x][game->player.pos_y] = VOID_CHAR;
	ft_printf("Step : %d\n", game->player.step);
	game->player.step++;
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->player.pos_x][game->player.pos_y - 1] == EXIT_CHAR)
	{
		if (0 == ft_collect_item(game))
			exit_game(game);
		else
			return ;
	}
	if (game->map[game->player.pos_x][game->player.pos_y - 1] == WALL_CHAR)
		return ;
	game->map[game->player.pos_x][game->player.pos_y - 1] = PLAYER_CHAR;
	game->map[game->player.pos_x][game->player.pos_y] = VOID_CHAR;
	ft_printf("Step : %d\n", game->player.step);
	game->player.step++;
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->player.pos_x][game->player.pos_y + 1] == EXIT_CHAR)
	{
		if (0 == ft_collect_item(game))
			exit_game(game);
		else
			return ;
	}
	if (game->map[game->player.pos_x][game->player.pos_y + 1] == WALL_CHAR)
		return ;
	game->map[game->player.pos_x][game->player.pos_y + 1] = PLAYER_CHAR;
	game->map[game->player.pos_x][game->player.pos_y] = VOID_CHAR;
	ft_printf("Step : %d\n", game->player.step);
	game->player.step++;
}
