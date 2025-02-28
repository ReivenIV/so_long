/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:34:14 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 13:34:29 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// For amount of lines raisons the handler will call draw_img.
// draw_image will use mlx to put images in the window.
static void	draw_img(t_game *game, void *img, int x, int y)
{
	x = x * SIZE;
	y = y * SIZE;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

// Will draw the initial state of the map
void	handler_map_draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->amount_rows)
	{
		x = 0;
		while (x < game->amount_cols)
		{

			if (game->map[y][x] == 'P')
				draw_img(game, game->img_p_d, x, y);
			else if (game->map[y][x] == 'E')
				draw_img(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->img_collect, x, y);
			else if (game->map[y][x] == '1')
				draw_img(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				draw_img(game, game->img_bg, x, y);
			x++;
		}
		y++;
	}
}