/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobytrap <bobytrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:30:26 by bobytrap          #+#    #+#             */
/*   Updated: 2025/02/23 12:30:26 by bobytrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_game_struct(t_game *game)
{
    printf("{\n");
    printf("  \"mlx\": %p,\n", game->mlx);
    printf("  \"win\": %p,\n", game->win);
    printf("  \"img_player_w\": %p,\n", game->img_player_w);
    printf("  \"img_player_a\": %p,\n", game->img_player_a);
    printf("  \"img_player_s\": %p,\n", game->img_player_s);
    printf("  \"img_player_d\": %p,\n", game->img_player_d);
    printf("  \"img_exit\": %p,\n", game->img_exit);
    printf("  \"img_collect\": %p,\n", game->img_collect);
    printf("  \"img_wall\": %p,\n", game->img_wall);
    printf("  \"img_bg\": %p,\n", game->img_bg);
    printf("  \"map\": %p,\n", game->map);
    printf("  \"temp_map\": %p,\n", game->temp_map);
    printf("  \"img_width\": %d,\n", game->img_width);
    printf("  \"img_height\": %d,\n", game->img_height);
    printf("  \"amount_rows\": %d,\n", game->amount_rows);
    printf("  \"amount_cols\": %d,\n", game->amount_cols);
    printf("  \"player\": %d,\n", game->player);
    printf("  \"coor_x\": %d,\n", game->coor_x);
    printf("  \"coor_y\": %d,\n", game->coor_y);
    printf("  \"amount_c\": %d,\n", game->amount_c);
    printf("  \"collected\": %d,\n", game->collected);
    printf("  \"moves\": %d\n", game->moves);
    printf("}\n");
}

void print_map(char **map, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", map[i]);
    }
}