/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:28:05 by lbordona          #+#    #+#             */
/*   Updated: 2025/02/21 17:32:37 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_struct(t_game *game)
{
	if (map_is_rectangular(game->map) == 0)
	{
		free_map(game->map, game);
		exit(1);
	}
	if (map_wall_is_valid(game->map) == 0)
	{
		ft_printf("\033[0;31mError → Map isn't surrounded by walls.\n");
		free_map(game->map, game);
		exit(1);
	}
	if (map_is_correct(game->map) == 0)
	{
		free_map(game->map, game);
		exit(1);
	}
	if (map_is_functional(game) == 0)
	{
		ft_printf("\033[0;31mError → Map has invalid number of Collectible");
		ft_printf("\033[0;31m, Exit or Player.\n");
		free_map(game->map, game);
		exit(1);
	}
}

void	check_map_path(char *av, t_game *game)
{
    init_temp_map(av, game); 												// Initialize temp_map as a copy of the main map
    player_position(game); 													// Find the player's starting position
    if (flood_fill(game, game->temp_map, game->coor_x, game->coor_y) == 0)
    {
        ft_printf("\033[0;31mError → Map doesn't have any valid path.\n");
        free_map(game->temp_map, game); 									// Free the temporary map
        free_map(game->map, game); 											// Free the main map
        exit (1);
    }
}

void	full_map_checker(char *av, t_game *game)
{
	game->map_rows = count_lines(av);
	init_map(av, game);
	game->map_cols = ft_strlen(game->map[0]);
	check_map_struct(game);
	check_map_path(av, game);
}
