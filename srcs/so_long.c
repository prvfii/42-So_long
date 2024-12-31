/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:25:59 by fimazouz          #+#    #+#             */
/*   Updated: 2024/07/25 17:11:13 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (argc != 2 && ft_printf("Error\nIl faut un fichier en parametre."))
		return (1);
	if (initmap(&map, argv) != 1)
	{
		ft_printf("Error\nProblème lors de l'ouverture du fichier\
		 vérifiez si il est valide.");
		return (1);
	}
	if (checkmap(&map, argv))
	{
		free_strs(map.doublemap);
		windowsize(&game, argv);
		totalofcoll(&game, argv[1]);
		initgame(&game, argv, &map);
		mlx_hook(game.win, 2, 1L << 0, handle_keymove, &game);
		mlx_hook(game.win, ON_DESTROY, 0, close_window, &game);
		drawmap(&game);
		mlx_loop(game.mlx);
		return (0);
	}
	return (EXIT_FAILURE);
}
