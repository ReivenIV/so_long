/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_player_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:38:25 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/26 19:21:21 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// put next img
// // void	put_bg(t_game *game, int x, int y)
// // {
// // 	mlx_put_image_to_window(game->mlx, game->win, game->img_bg, game->coor_x * SIZE, game->coor_y * SIZE);
// // }
// ny = new_y & nx = new_x 
void	next_player_move(t_game *game, int nx, int ny, char key)
{
	int	x;
	int	y;

	x = game->coor_x * SIZE;
	y = game->coor_y * SIZE;
	
	nx = nx * SIZE;
	ny = ny * SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img_bg, x, y);
	// W A S D
	if (key == 'w')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_w, nx, ny);
	if (key == 'a')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_a, nx, ny);
	if (key == 's')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_s, nx, ny);	
	if (key == 'd')
		mlx_put_image_to_window(game->mlx, game->win, game->img_p_d, nx, ny);
	game->moves++;
	ft_printf("%s%d\n", "Moves: ", game->moves); //TODO Will need write & putnbr
}
