/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:10:29 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 16:57:12 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	windowsize(t_game *data, char **av)
{
	data->width = (countcolumns(av[1]) * IMG_W);
	data->height = (countlines(av[1]) * IMG_W);
}

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	initgameimg(t_game *game)
{
	int	img_width;
	int	img_height;

	img_height = IMG_W;
	img_width = IMG_W;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "So long");
	game->img_back = mlx_xpm_file_to_image(game->mlx, "./textures/empty.xpm",
			&img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/item.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&img_width, &img_height);
}

void	initgame(t_game *game, char **av, t_map *play)
{
	int	width;
	int	height;

	initgameimg(game);
	game->moves = 0;
	game->collected = 0;
	game->exit_x = -1;
	game->exit_y = -1;
	game->total_coll = items(av[1]);
	game->exit = count_exit(av[1]);
	initmapsplit(game, av, play);
	find_player(game);
	width = game->width / IMG_W;
	height = game->height / IMG_W;
	if (!is_map_surrounded_by_walls(game->map, width, height))
	{
		ft_printf("Error\nMap doit être entourée de murs.");
		exit(EXIT_FAILURE);
	}
	if (!is_valid_path(game))
	{
		ft_printf("Error\nPas de chemin valide.");
		exit(EXIT_FAILURE);
	}
}

void	drawmap(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->height / IMG_W)
	{
		draw_row(game, x);
		x++;
	}
}
