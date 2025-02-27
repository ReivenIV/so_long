/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exit_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:00:32 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 13:38:34 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// At the end of the game or ESC we will free everything and end the proces.
void	handler_exit_game(t_game *game)
{
	free_map(game->map, game);
	mlx_destroy_image(game->mlx, game->img_p_w);
	mlx_destroy_image(game->mlx, game->img_p_a);
	mlx_destroy_image(game->mlx, game->img_p_s);
	mlx_destroy_image(game->mlx, game->img_p_d);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_bg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}