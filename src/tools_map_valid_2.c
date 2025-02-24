/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map_valid_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:57:11 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/24 17:25:19 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Usefull tool to check if all the paths are possible in the map or not.
static int	flood_fill(t_game *game, char **map, int x, int y)
{
	static int	collected_c;
	static int	exits;

	if (y < 0 || x < 0 || y > game->amount_rows || x > game->amount_cols || map[y][x] == '1' || map[y][x] == 'X')		// Limits of the flood fill
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
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
	//! printf("\n FF counted \n exits = %i\n a_c = %i vs %i\n\n", exits, collected_c, game->amount_c);
	if (exits == 1 && collected_c == game->amount_c)
		return (1);
	else
		return (0);
}

int	are_map_paths_valid(char **av, t_game *game)
{
	t_game	temp_map;

	init_struct_game(&temp_map);
	init_map(av[1], &temp_map, game->amount_rows);						// We create a new map in a temporary struct just to test it and modify it with flood fill
	update_player_coordinates(game);
	if (flood_fill(game, temp_map.map, game->coor_x, game->coor_y) == 0)
	{
		write(1, "ERROR : map path incorrect\n", 27);
		free_map(temp_map.map, &temp_map);
		free_map(game->map, game);
		exit(1);
	}
	return (1);
}
// Main to test are_map_paths_valid
// // int main(int argc, char **av)
// // {
// // 	t_game game;
	
// // 	if (argc != 2)
// // 	{
// // 		printf("Usage: %s <map_file>\n", av[0]);
// // 		return 1;
// // 	}
// // 	init_struct_game(&game);
// // 	game.amount_rows = count_lines(av[1]);
// // 	if (game.amount_rows == -1)
// // 	{
// // 		perror("Error counting lines in file");
// // 		return 1;
// // 	}
// // 	if (!init_map(av[1], &game, game.amount_rows))
// // 	{
// // 		perror("Error initializing map");
// // 		return 1;
// // 	}
// // 	game.amount_cols = ft_strlen(game.map[0]);                      // Set the amount_cols based on the first row length
// // 	count_pecs(&game);											// Will count amount of : Player, Exit, Collectibles
// // 	update_player_coordinates(&game);
// // 	printf("x: %i\ny: %i\n", game.coor_x, game.coor_y);
// //     print_map(game.map, game.amount_rows);
// //     printf("Starting flood fill at: (%d, %d)\n", game.coor_x, game.coor_y);
// // 	int res = are_map_paths_valid(av, &game);
// // 	printf("Flood fill result: %d\n", res);
// //     print_map(game.map, game.amount_rows);
// //     free_map(game.map, &game);
// //     return 0;
// // }

// Main to test flood_fill
// // int main(int argc, char **argv)
// // {
// //     t_game game;
// //     if (argc != 2)
// //     {
// //         printf("Usage: %s <map_file>\n", argv[0]);
// //         return 1;
// //     }
// //     init_struct_game(&game);
// //     game.amount_rows = count_lines(argv[1]);
// //     if (game.amount_rows == -1)
// //     {
// //         perror("Error counting lines in file");
// //         return 1;
// //     }
// //     if (!init_map(argv[1], &game))
// //     {
// //         perror("Error initializing map");
// //         return 1;
// //     }
// //     game.amount_cols = strlen(game.map[0]); // Set the amount_cols based on the first row length
// //     game.amount_c = 2;
// //     update_player_coordinates(&game);
// // 	printf("x: %i\ny: %i\n", game.coor_x, game.coor_y);
// //     print_map(game.map, game.amount_rows);
// //     printf("Starting flood fill at: (%d, %d)\n", game.coor_x, game.coor_y);
// //     int result = flood_fill(&game, game.map, game.coor_x, game.coor_y);
// //     printf("Flood fill result: %d\n", result);
// //     print_map(game.map, game.amount_rows);
// //     free_map(game.map, &game);
// //     return 0;
// // }