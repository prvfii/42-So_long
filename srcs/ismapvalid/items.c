/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:49:41 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 16:57:21 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_items(char *file)
{
	char	*map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = load_map(file);
	while (map[i])
	{
		if (map[i] == 'C')
			count++;
		i++;
	}
	free(map);
	if (count >= 1)
		return (0);
	else
	{
		ft_printf("Error\nIl faut au moins un item (C) a collecter.");
		return (1);
	}
}

int	items(char *file)
{
	int		count;
	char	*map;
	int		i;

	i = 0;
	count = 0;
	map = load_map(file);
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			count++;
		i++;
	}
	free(map);
	return (count);
}

void	totalofcoll(t_game *game, char *file)
{
	game->total_coll = items(file);
}
