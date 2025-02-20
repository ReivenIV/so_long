/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:03:01 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 16:03:01 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_struct_game(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->img_player_w = 0;
	game->img_player_a = 0;
	game->img_player_s = 0;
	game->img_player_d = 0;
	game->img_exit = 0;
	game->img_collect = 0;
	game->img_wall = 0;
	game->img_background = 0;
	game->map = 0;
	game->temp_map = 0;
	game->img_width = 32
	game->img_height = 32
	game->map_rows = 0;
	game->map_cols = 0;
	game->player = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->exit = 0;
	game->collect = 0;
	game->collected = 0;
	game->wall = 0;
	game->background = 0;
	game->moves = 0;
}
