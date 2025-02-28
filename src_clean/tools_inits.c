/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 88888888 <88888888@contact.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:03:01 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/28 18:55:49 by 88888888         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Will "mount" the images to the struct
void	init_images(t_game *game)
{
	int	w;
	int	h;

	w = WIDTH;
	h = HEIGHT;
	game->img_p_w = mlx_xpm_file_to_image(game->mlx, PLAYER_W, &w, &h);
	game->img_p_a = mlx_xpm_file_to_image(game->mlx, PLAYER_A, &w, &h);
	game->img_p_s = mlx_xpm_file_to_image(game->mlx, PLAYER_S, &w, &h);
	game->img_p_d = mlx_xpm_file_to_image(game->mlx, PLAYER_D, &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT, &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, IMG_C, &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL, &w, &h);
	game->img_bg = mlx_xpm_file_to_image(game->mlx, IMG_BG, &w, &h);
}

// Will init the struct, everything 0
void	init_struct_game(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->img_p_w = 0;
	game->img_p_a = 0;
	game->img_p_s = 0;
	game->img_p_d = 0;
	game->img_exit = 0;
	game->img_collect = 0;
	game->img_wall = 0;
	game->img_bg = 0;
	game->map = 0;
	game->temp_map = 0;
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

// Will "mount" the map from the file.ber to the struct **map
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		if (!game->map[i])
			return (write(2, "Error: malloc failed in ft_strtrim\n", 35),
				free_map(game->map, game), close(fd), 0);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
