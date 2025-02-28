/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:08:43 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:49:35 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will open the map file + count every line in it.
int	count_lines(char *av)
{
	char	*line;
	int		amount_lines;
	int		fd;

	amount_lines = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		amount_lines++;
	}
	close(fd);
	return (amount_lines);
}

// Will count pecs in the map and update struct
void	count_pecs(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
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
