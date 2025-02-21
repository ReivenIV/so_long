/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:00:04 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:14:09 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_img(t_game *game, void *img, int x, int y)
{
	x *= SIZE;
	y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

// void	draw_map(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < game->map_rows)
// 	{
// 		x = 0;
// 		while (x < game->map_cols)
// 		{
// 			if (game->map[y][x] == 'P')
// 				draw_img(game, game->img_player_d, x, y);
// 			else if (game->map[y][x] == 'E')
// 				draw_img(game, game->img_exit, x, y);
// 			else if (game->map[y][x] == 'C')
// 				draw_img(game, game->img_collect, x, y);
// 			else if (game->map[y][x] == '1')
// 				draw_img(game, game->img_wall, x, y);
// 			else if (game->map[y][x] == '0')
// 				draw_img(game, game->img_background, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }
void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int size = 32;
	y = 0;
	while (y < game->map_rows)
	{
		x = 0;
		while (x < game->map_cols)
		{
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player_d, x+size, y+size);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x+size, y+size);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x+size, y+size);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x+size, y+size);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_background, x+size, y+size);
			x++;
		}
		y++;
	}
}
