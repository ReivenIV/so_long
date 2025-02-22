/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:35:29 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/22 15:13:08 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_game(t_game *game)
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
