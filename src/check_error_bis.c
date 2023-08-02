/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 05:14:55 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/02 00:19:09 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_wall_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '\n')
				break ;
			if (game->map[0][x] != '1' || \
				game->map[game->size_map.y -1][x] != '1' || \
				game->map[y][0] != '1' || \
				game->map[y][game->size_map.x -1] != '1')
			{
				print_error("Error\n-Empty wall\n");
				exit (EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len <= 4 || file[len - 5] == '/'
		|| file[len - 4] != '.' || file[len - 3] != 'b'
		|| file[len - 2] != 'e' || file[len - 1] != 'r')
	{
		print_error("Error\nfail extension\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(EXIT_SUCCESS);
}
