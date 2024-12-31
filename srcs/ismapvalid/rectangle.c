/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 01:33:28 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/28 13:33:20 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkrectangle(t_map *data)
{
	int		i;
	size_t	len;

	if (data->doublemap == NULL || data->lines <= 0)
	{
		ft_printf("Error\nLa carte est vide ou non valide.");
		return (1);
	}
	len = ft_strlen(data->doublemap[0]);
	i = 1;
	while (i < data->lines)
	{
		if (ft_strlen(data->doublemap[i]) != len)
		{
			ft_printf("Error\nLa carte doit être rectangulaire.");
			return (1);
		}
		i++;
	}
	data->colums = len;
	return (0);
}
