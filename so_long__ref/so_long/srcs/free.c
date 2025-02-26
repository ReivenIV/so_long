/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:35:29 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/26 16:28:39 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->amount_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map, game);
	free_map(game->temp_map, game);
	mlx_destroy_image(game->mlx, game->img_player_w);
	mlx_destroy_image(game->mlx, game->img_player_a);
	mlx_destroy_image(game->mlx, game->img_player_s);
	mlx_destroy_image(game->mlx, game->img_player_d);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_bg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}
