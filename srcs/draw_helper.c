/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firdawssemazouz <firdawssemazouz@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:11:53 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/23 15:24:21 by firdawssema      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, t_coords coords)
{
	if (game->map[coords.x][coords.y] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			coords.ptr_x, coords.ptr_y);
	else if (game->map[coords.x][coords.y] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			coords.ptr_x, coords.ptr_y);
	else if (game->map[coords.x][coords.y] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			coords.ptr_x, coords.ptr_y);
	else if (game->map[coords.x][coords.y] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			coords.ptr_x, coords.ptr_y);
}

void	draw_row(t_game *game, int x)
{
	int			y;
	t_coords	coords;

	y = 0;
	while (y < game->width / IMG_W)
	{
		coords.ptr_x = y * IMG_W;
		coords.ptr_y = x * IMG_W;
		coords.x = x;
		coords.y = y;
		mlx_put_image_to_window(game->mlx, game->win, game->img_back,
			coords.ptr_x, coords.ptr_y);
		draw_tile(game, coords);
		y++;
	}
}
