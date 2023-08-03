/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:11:10 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/03 05:50:58 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_data	img;

	if (ac != 2)
	{
		ft_putstr("Error\nInvalid number of arguments!\n");
		return (1);
	}
	if (ac == 0)
	{
		ft_putstr("Error\nEmpty map!\n");
		return (EXIT_FAILURE);
	}
	ft_init_game(av, &game);
	game.mlx_win = mlx_new_window(game.mlx, game.size_map.x * 64,
			game.size_map.y * 64, "Hello So_long!");
	img.img = mlx_new_image(game.mlx, 1920, 1080);
	insert_picture(&game);
	ft_print_map(&game);
	ft_collect_item(&game);
	solver(game, av);
	mlx_key_hook(game.mlx_win, key_press, &game);
	mlx_hook(game.mlx_win, 17, 1L << 17, exit_game_give_up, &game);
	mlx_loop(game.mlx);
	exit (0);
}
