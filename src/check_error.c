/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 00:01:09 by dferjul           #+#    #+#             */
/*   Updated: 2023/06/30 05:13:41 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *str)
{
	ft_putstr(str);
}

int	check_search_element(t_game *game, char c)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == c)
				i++;
			y++;
		}
		x++;
	}
	return (i);
}

void	check_element_map(t_game *game)
{
	if (check_search_element(game, 'C') < 1)
	{
		print_error("Error\n-empty 'C' character\n");
		exit (EXIT_FAILURE);
	}
	else if (check_search_element(game, 'E') != 1)
	{
		print_error("Error\n-empty 'E' character\n");
		exit (EXIT_FAILURE);
	}
	else if (check_search_element(game, 'P') != 1)
	{
		print_error("Error\n-empty 'P' character\n");
		exit (EXIT_FAILURE);
	}
}

void	check_rectangular_map(t_game *game)
{
	int	s;
	int	i;

	i = 0;
	while (game->map[i])
	{
		s = ft_strlen(game->map[i]);
		if (game->map[i] == game->map[game->size_map.y -1])
			s++;
		if (s != game->size_map.x +1)
		{
			print_error("Error\n-check_struct_map fail");
			exit (EXIT_FAILURE);
		}
		i++;
	}
}
