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


