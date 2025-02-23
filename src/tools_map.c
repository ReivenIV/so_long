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

// TODO count lines (will need GNL)
// int	count_lines(char *av){}


// is an strlen but in the context for these project i prefer to call it count_cols 
// TODO we will use strlen for these one babe
// // int	count_cols(char *line)
// // {
// // 	int	count;

// // 	count = 0;
// // 	while (line[count] != '\0')
// // 		count++;
// // 	return (count);
// // }

void	update_map_data(t_game *game)
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
			if (game->map[i][j] == 'C')
				game->amount_c++;
			else if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
}
