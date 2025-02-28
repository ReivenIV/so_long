/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_valid_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:11 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:38:54 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
flood_fill : Usefull tool to check if all the paths are
possible in the map or not.
*/
// Check if its possible to collect all C without passing throught the Exit. 
static int	flood_fill_c(t_game *game, char **map, int x, int y)
{
	static int	collected_c;

	if (y < 0 || x < 0 || y >= game->amount_rows || x >= game->amount_cols
		|| map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'C')
		collected_c++;
	map[y][x] = 'X';
	flood_fill_c(game, map, x + 1, y);
	flood_fill_c(game, map, x - 1, y);
	flood_fill_c(game, map, x, y + 1);
	flood_fill_c(game, map, x, y - 1);
	if (collected_c == game->amount_c)
		return (1);
	else
		return (0);
}

// will check if its possible to collect all C and E 
static int	flood_fill_e_c(t_game *game, char **map, int x, int y)
{
	static int	collected_c;
	static int	exits;

	if (y < 0 || x < 0 || y >= game->amount_rows || x >= game->amount_cols
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		exits++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		collected_c++;
	map[y][x] = 'X';
	flood_fill_e_c(game, map, x + 1, y);
	flood_fill_e_c(game, map, x - 1, y);
	flood_fill_e_c(game, map, x, y + 1);
	flood_fill_e_c(game, map, x, y - 1);
	if (exits == 1 && collected_c == game->amount_c)
		return (1);
	else
		return (0);
}
// We will check if all paths are possible in the map to collect/exit. 
// We create a temporary map where we will feel it with "X's"
// and then we free it. 

int	are_map_paths_valid(char **av, t_game *game)
{
	t_game	temp_map;
	t_game	temp_map_2;

	init_struct_game(&temp_map);
	init_struct_game(&temp_map_2);
	if (init_map(av[1], &temp_map, game->amount_rows) == 0 || init_map(av[1],
			&temp_map_2, game->amount_rows) == 0)
		return (free_map(temp_map.map, game),
			free_map(temp_map_2.map, game), 0);
	get_player_coordinates(game);
	if (flood_fill_c(game, temp_map.map, game->coor_x, game->coor_y) == 0
		|| flood_fill_e_c(game, temp_map_2.map, game->coor_x, game->coor_y)
		== 0)
	{
		write(1, "ERROR : map path incorrect\n", 27);
		free_map(temp_map.map, game);
		free_map(temp_map_2.map, game);
		free_map(game->map, game);
		exit(1);
	}
	free_map(temp_map.map, game);
	free_map(temp_map_2.map, game);
	return (1);
}
