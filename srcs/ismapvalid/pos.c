/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:20:31 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 17:05:20 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_pos(char *file)
{
	char	*map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = load_map(file);
	while (map[i])
	{
		if (map[i] == 'P')
			count++;
		i++;
	}
	free(map);
	if (count == 1)
		return (0);
	else if (count < 1)
	{
		ft_printf("Error\nIl faut au moins une position de depart.");
		return (1);
	}
	ft_printf("Error\nIl faut une seule position de depart.");
	return (1);
}

int	has_only_valid_characters(t_map *game_object)
{
	int		y;
	int		x;
	char	*valid_chars;

	valid_chars = "10PEC";
	y = 0;
	while (game_object->doublemap[y])
	{
		x = 0;
		while (game_object->doublemap[y][x])
		{
			if (!ft_strchr(valid_chars, game_object->doublemap[y][x]))
			{
				ft_printf("Error\nCaractère invalide dans la map :");
				ft_printf(" '%c'", game_object->doublemap[y][x]);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
