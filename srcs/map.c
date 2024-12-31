/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 00:18:53 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 17:00:22 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initmap(t_map *data, char **av)
{
	char	*map;

	map = load_map(av[1]);
	if (!map)
		return (-1);
	data->count_c = items(av[1]);
	data->doublemap = ft_split(map, '\n');
	data->lines = countlines(av[1]);
	data->colums = countcolumns(av[1]);
	free(map);
	return (1);
}

int	checkmap(t_map *game, char **av)
{
	if (checkber(av[1]) != 0)
		return (0);
	if (openfile(av[1]) == 0)
		return (0);
	if (count_exit(av[1]) != 0)
		return (0);
	if (count_items(av[1]) != 0)
		return (0);
	if (count_pos(av[1]) != 0)
		return (0);
	if (checkrectangle(game) != 0)
		return (0);
	if (has_only_valid_characters(game) != 0)
		return (0);
	if (checkwindow(game) != 0)
		return (0);
	return (1);
}

void	initmapsplit(t_game *data, char **av, t_map *play)
{
	char	*map;

	(void)(play);
	map = load_map(av[1]);
	data->map = ft_split(map, '\n');
	data->dupl_map = ft_split(map, '\n');
	free(map);
}

int	is_map_surrounded_by_walls(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	checkwindow(t_map *map)
{
	if (map->lines * 32 > 1920 || map->colums * 32 > 1080)
	{
		ft_printf("Error\nMap trop grande.");
		return (1);
	}
	return (0);
}
