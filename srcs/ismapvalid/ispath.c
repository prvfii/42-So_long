/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:31:36 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/26 14:52:32 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_move_valid(t_game *game_object, int y, int x,
		int has_visited[MAX_LINES][MAX_LINES])
{
	if (game_object->map[y][x] == WALL || has_visited[y][x])
		return (false);
	return (true);
}

static void	flood_fill(t_game *game_object, int y, int x,
		int has_visited[MAX_LINES][MAX_LINES])
{
	int			i;
	static int	direction_x[] = {-1, 0, 0, 1};
	static int	direction_y[] = {0, -1, 1, 0};
	int			new_x;
	int			new_y;

	i = 0;
	has_visited[y][x] = 1;
	while (i < 4)
	{
		new_x = x + direction_x[i];
		new_y = y + direction_y[i];
		if (is_move_valid(game_object, new_y, new_x, has_visited))
			flood_fill(game_object, new_y, new_x, has_visited);
		i++;
	}
}

static t_map_position	find_position(t_game *game_object, char tile)
{
	t_map_position	pos;

	pos.y = 0;
	while (game_object->map[pos.y])
	{
		pos.x = 0;
		while (game_object->map[pos.y][pos.x])
		{
			if (game_object->map[pos.y][pos.x] == tile)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

static bool	check_items_collected(t_game *game,
		int has_visited[MAX_LINES][MAX_LINES])
{
	t_map_position	item_pos;
	int				y;
	int				x;

	item_pos.y = 0;
	while (game->map[item_pos.y])
	{
		item_pos.x = 0;
		while (game->map[item_pos.y][item_pos.x])
		{
			if (game->map[item_pos.y][item_pos.x] == 'C')
			{
				y = item_pos.y;
				x = item_pos.x;
				if (!has_visited[y][x])
				{
					return (false);
				}
			}
			item_pos.x++;
		}
		item_pos.y++;
	}
	return (true);
}

int	is_valid_path(t_game *game)
{
	int				has_visited[MAX_LINES][MAX_LINES];
	t_map_position	start;
	t_map_position	exit;
	int				i;
	int				j;

	i = 0;
	while (i < MAX_LINES)
	{
		j = 0;
		while (j < MAX_LINES)
		{
			has_visited[i][j] = 0;
			j++;
		}
		i++;
	}
	start = find_position(game, 'P');
	exit = find_position(game, 'E');
	flood_fill(game, start.y, start.x, has_visited);
	if (!has_visited[exit.y][exit.x])
		return (0);
	return (check_items_collected(game, has_visited));
}
