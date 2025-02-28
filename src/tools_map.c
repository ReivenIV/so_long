/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:08:43 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 17:52:12 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will open the map file + count every line in it.
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

// Will count pecs in the map and update struct
void	count_pecs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])		
	{
		j = 0;
		//printf("%s\n", game->map[i]);					// only for testing mode
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->amount_c++;
			j++;
		}
		i++;
	}
}
