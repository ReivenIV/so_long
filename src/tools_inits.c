/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:03:01 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/20 16:03:01 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct_game(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->img_player_w = 0;
	game->img_player_a = 0;
	game->img_player_s = 0;
	game->img_player_d = 0;
	game->img_exit = 0;
	game->img_collect = 0;
	game->img_wall = 0;
	game->img_bg = 0;
	game->map = 0;
	game->temp_map = 0;
	game->img_width = 32;
	game->img_height = 32;
	game->amount_rows = 0;
	game->amount_cols = 0;
	game->player = 0;
	game->coor_x = 0;
	game->coor_y = 0;
	game->amount_c = 0;
	game->collected = 0;
	game->moves = 0;
}

int	init_map(char *av, t_game *game)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->map = malloc(sizeof(char *) * (game->amount_rows + 1));
	if (!game->map)
		return (0);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (free(game->map), exit(1), 0);
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i])
				return (free_map(game->map, game), close(fd), 0);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
// Test init_map
// // int main(int ac, char **av)
// // {
// // 	(void)ac;
// //     t_game game;
// //     init_struct_game(&game);
// //     game.amount_rows = count_lines(av[1]);
// //     if (game.amount_rows == -1)
// //     {
// //         perror("Error counting lines in file");
// //         return 1;
// //     }
// //     init_map(av[1], &game);
// // 	print_map(game.map, game.amount_rows);
// //     free_map(game.map, &game);
// //     return (0);
// // }