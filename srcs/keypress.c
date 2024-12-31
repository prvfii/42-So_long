/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:23:49 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/28 13:46:48 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	free(strs);
}

int	close_window(t_game *data)
{
	ft_printf("Fin du jeu...\n");
	mlx_destroy_window(data->mlx, data->win);
	free_strs(data->dupl_map);
	free_strs(data->map);
	exit(0);
	return (0);
}

int	handle_keymove(int key, t_game *game)
{
	if (key == ESC_KEY)
		close_window(game);
	else if (key == W_KEY)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == A_KEY)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == S_KEY)
		move_player(game, game->player_x + 1, game->player_y);
	else if (key == D_KEY)
		move_player(game, game->player_x, game->player_y + 1);
	return (0);
}
