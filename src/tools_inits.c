/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:03:01 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/26 15:58:13 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game *game)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	game->img_player_w = mlx_xpm_file_to_image(game->mlx, PLAYER_W, &w, &h);
	game->img_player_a = mlx_xpm_file_to_image(game->mlx, PLAYER_A, &w, &h);
	game->img_player_s = mlx_xpm_file_to_image(game->mlx, PLAYER_S, &w, &h);
	game->img_player_d = mlx_xpm_file_to_image(game->mlx, PLAYER_D, &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT, &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, IMG_C, &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL, &w, &h);
	game->img_bg = mlx_xpm_file_to_image(game->mlx, IMG_BG, &w, &h);
}

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
	// // game->img_width = 32;
	// // game->img_height = 32;
	game->amount_rows = 0;
	game->amount_cols = 0;
	game->player = 0;
	game->coor_x = 0;
	game->coor_y = 0;
	game->amount_c = 0;
	game->collected = 0;
	game->moves = 0;
	game->exit = 0;
}

int	init_map(char *av, t_game *game, int amount_rows)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = 0;
	game->map = malloc(sizeof(char *) * (amount_rows + 1));
	if (!game->map)
		return (write(2, "Error: malloc failed\n", 21), 0);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (free(game->map), 0);
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i])
				return (write(2, "Error: malloc failed in ft_strtrim\n", 35), free_map(game->map, game), close(fd), 0);
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