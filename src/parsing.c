/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:27:08 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/02 01:56:07 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_map_xy(char *file, t_game *game)
{
	int		x;
	int		y;
	int		fd;
	char	*str;

	y = 0;
	x = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str[x])
	{
		x++;
	}
	game->size_map.x = x -1;
	while (str != NULL)
	{
		y++;
		free(str);
		str = get_next_line(fd);
	}
	game->size_map.y = y;
	close(fd);
	game->size_map.len = ft_strlen(*game->map);
}

void	create_map(char *file, t_game *game)
{
	int	fd;
	int	x;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error("Error\nfail open file");
		exit (EXIT_FAILURE);
	}
	game->map = malloc(sizeof(char *) * (game->size_map.y + 1) + 1);
	game->map[x] = get_next_line(fd);
	while (game->map[x] != NULL)
	{
		x++;
		game->map[x] = get_next_line(fd);
	}
	close(fd);
}

void	ft_init_game(char **av, t_game *game)
{
	check_extension(av[1]);
	game->mlx = mlx_init();
	create_map(av[1], game);
	count_map_xy(av[1], game);
	check_element_map(game);
	check_wall_map(game);
}
