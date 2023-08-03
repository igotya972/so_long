/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collect_and_exit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:05:37 by dferjul           #+#    #+#             */
/*   Updated: 2023/07/29 04:20:30 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_collect_item(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->player.key = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->player.key++;
			j++;
		}
		i++;
	}
	return (game->player.key);
}
