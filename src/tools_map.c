/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:08:43 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 17:08:43 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *av)
{
	char	*line;								// Pointer to hold each line read from the file
	int		amount_lines;						// Variable to count the number of lines
	int		fd;									// File descriptor for the file

	amount_lines = 0;
	fd = open(av, O_RDONLY);					// Open the file in read-only mode
	if (fd == -1)								// Check if the file was opened successfully
		return (-1);							// Return -1 if there was an error opening the file
	while ((line = get_next_line(fd)) != NULL)	// Read the next line from the file
	{
		free(line);								// Free the memory allocated for the line
		amount_lines++;							// Increment the line count
	}
	close(fd);									// Close the file descriptor
	return (amount_lines);						// Return the total number of lines
}

// Test count_lines function 
// // int main(int argc, char **argv)
// // {
// // 	int lines = count_lines(argv[1]);
// // 	printf("Number of lines: %d\n", lines);
// // 	return (0);
// // }

//TODO need testing !! 
int	flood_fill(t_game *game, char **map, int x, int y)
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
	if (exits == 1 && collected_c == game->amount_c)
		return (1);
	else
		return (0);
}
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