/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:33:50 by dferjul           #+#    #+#             */
/*   Updated: 2023/08/02 04:20:21 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_data	new_data(t_game *game, char *path)
{
	t_data	img;

	img.img = mlx_xpm_file_to_image(game->mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	insert_picture(t_game *game)
{
	game->wall = new_data(game, "./picture/wall.xpm");
	game->v_zero = new_data(game, "./picture/floor/sol_egypt1.xpm");
	game->c_collector = new_data(game, "./picture/collector/daco.xpm");
	game->e_exit = new_data(game, "./picture/exit/d2_texture_escalier.xpm");
	game->p_pos = new_data(game, "./picture/perso/chicken_2.xpm");
}

void	put_picture(t_game *groot, t_data pic, int x, int y)
{	
	mlx_put_image_to_window
	(groot->mlx, groot->mlx_win, pic.img, x * 64, y * 64);
}

void	ft_print_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			put_picture(game, game->v_zero, y, x);
			if (game->map[x][y] == '1')
				put_picture(game, game->wall, y, x);
			else if (game->map[x][y] == 'C')
				put_picture(game, game->c_collector, y, x);
			else if (game->map[x][y] == 'E')
				put_picture(game, game->e_exit, y, x);
			y++;
		}
		x++;
	}
	ft_print_map_p(game);
}

void	ft_print_map_p(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->player.pos_x = x;
				game->player.pos_y = y;
				put_picture(game, game->p_pos, y, x);
			}
			y++;
		}
		x++;
	}
}
