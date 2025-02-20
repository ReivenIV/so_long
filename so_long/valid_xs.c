/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_xs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:00:46 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 16:00:46 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// Will check if the second argument is ".ber" (the correct map file format)
static int	is_dot_ber(char *map_file)
{
	int	i;

	if (!map_file)
		return (0);
	i = ft_strlen(map_file) - 1;
	if (map_file[i] == 'r' && map_file[i - 1] == 'e' && map_file[i - 2] == 'b' && map_file[i - 3] == '.' )
		return (1);
	return (0);
}

// First validator 
// Will validate amount of args, map file format & if its possible to open the map file.
int	validator_xs(int ac, char **av)
{
	int	fd;

	if (ac != 2)																// does it has 2 arguments ? 
	{
		write(1, "Error: only 2 params, ./so_long map.ber\n", 28);
		exit (1);
	}
	if (is_dot_ber(av[1]) == 0)													// is 2 arg .ber format ?
	{
		write(1, "Error: param 2 must be .ber format\n", 35);
		exit (1);	
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)																	// can we open the file ? 
	{
		write(1, "Error: failed to open file\n", 27);
		close(fd);
		exit (1);	
	}
	close(fd);
	return (1);
}