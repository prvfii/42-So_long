/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:49:51 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 17:02:29 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_x][new_y] == '1')
		return ;
	if (game->map[new_x][new_y] == 'C' && ++(game->collected))
		game->map[new_x][new_y] = '0';
	if (game->map[new_x][new_y] == 'E')
	{
		if (game->collected == game->total_coll)
		{
			ft_printf("Félicitations,\ntu as GAGNÉ !!!!!\n");
			close_window(game);
		}
		game->exit_x = new_x;
		game->exit_y = new_y;
	}
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		game->map[game->player_x][game->player_y] = 'E';
	else
		game->map[game->player_x][game->player_y] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_x][game->player_y] = 'P';
	game->moves++;
	ft_printf("Total moves : %d\n", game->moves);
	drawmap(game);
}
