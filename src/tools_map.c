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

	////print_game_struct(game);
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

// // int main()
// // {
// //     t_game game;
// //     init_struct_game(&game);
// //     game.amount_rows = 5;
// //     game.amount_cols = 5;
// //     game.amount_c = 1;

// //     char *map[5] = {
// //         "11111",
// //         "1C0E1",
// //         "10001",
// //         "1P001",
// //         "11111"
// //     };

// //     printf("test\n");

// //     int result = flood_fill(&game, map, 1, 1);
// //     printf("Flood fill result: %d\n", result);

// //     return 0;
// // }