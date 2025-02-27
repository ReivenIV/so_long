/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bobydear <bobydear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:30:26 by bobydear          #+#    #+#             */
/*   Updated: 2025/02/27 14:00:12 by bobydear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_game_struct(t_game *game)
{
    printf("{\n");
    printf("  \"mlx\": %p,\n", game->mlx);
    printf("  \"win\": %p,\n", game->win);
    printf("  \"img_p_w\": %p,\n", game->img_p_w);
    printf("  \"img_p_a\": %p,\n", game->img_p_a);
    printf("  \"img_p_s\": %p,\n", game->img_p_s);
    printf("  \"img_p_d\": %p,\n", game->img_p_d);
    printf("  \"img_exit\": %p,\n", game->img_exit);
    printf("  \"img_collect\": %p,\n", game->img_collect);
    printf("  \"img_wall\": %p,\n", game->img_wall);
    printf("  \"img_bg\": %p,\n", game->img_bg);
    printf("  \"map\": %p,\n", game->map);
    printf("  \"temp_map\": %p,\n", game->temp_map);
    // // printf("  \"img_width\": %d,\n", game->img_width);
    // // printf("  \"img_height\": %d,\n", game->img_height);
    printf("  \"coor_x\": %d,\n", game->coor_x);
    printf("  \"coor_y\": %d,\n", game->coor_y);
    printf("  \"collected\": %d,\n", game->collected);
    printf("  \"moves\": %d\n", game->moves);
    printf("  \"amount_player\": %d,\n", game->player);
    printf("  \"amount_exit\": %d,\n", game->exit);
    printf("  \"amount_rows\": %d,\n", game->amount_rows);
    printf("  \"amount_cols\": %d,\n", game->amount_cols);
    printf("  \"amount_c\": %d,\n", game->amount_c);
    printf("}\n");
}

void print_map(char **map, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", map[i]);
    }
}