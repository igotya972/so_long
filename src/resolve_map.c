/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 05:08:25 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/03 01:30:07 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_map_bis(char *file, t_game *game)
{
	int	fd;
	int	x;

	x = 0;
	fd = open(file, O_RDONLY);
	game->map_bis = malloc(sizeof(char *) * (game->size_map.y + 1) + 1);
	game->map_bis[x] = get_next_line(fd);
	while (game->map_bis[x] != NULL)
	{
		x++;
		game->map_bis[x] = get_next_line(fd);
	}
	game->map_bis[x + 1] = NULL;
	close(fd);
}

void	resolve_map(char **map, t_solv size, t_solv cur)
{
	if ((map[cur.pos_x][cur.pos_y] == '1' || map[cur.pos_x][cur.pos_y] == 'X' 
		|| map[cur.pos_x][cur.pos_y] == 'E'))
	{
		return ;
	}
	map[cur.pos_x][cur.pos_y] = 'X';
	resolve_map(map, size, (t_solv){cur.pos_x - 1, cur.pos_y});
	resolve_map(map, size, (t_solv){cur.pos_x + 1, cur.pos_y});
	resolve_map(map, size, (t_solv){cur.pos_x, cur.pos_y - 1});
	resolve_map(map, size, (t_solv){cur.pos_x, cur.pos_y + 1});
}

void	resolv(char	**map, t_solv size, t_solv begin)
{
	int	x;
	int	y;

	x = 0;
	resolve_map(map, size, begin);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
			{
				print_error("Error\nResolv failed\n");
				exit(EXIT_FAILURE);
			}
			y++;
		}
		x++;
	}
}

void	solver(t_game game, char **av)
{
	t_solv	solv;
	t_solv	size;

	create_map_bis(av[1], &game);
	solv.pos_x = game.player.pos_x;
	solv.pos_y = game.player.pos_y;
	size.pos_x = game.size_map.x;
	size.pos_y = game.size_map.y;
	resolv(game.map_bis, size, solv);
}
