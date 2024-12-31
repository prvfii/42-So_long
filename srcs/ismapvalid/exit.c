/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firdawssemazouz <firdawssemazouz@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:14:17 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/24 00:35:55 by firdawssema      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_exit(char *file)
{
	char	*map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = load_map(file);
	while (map[i])
	{
		if (map[i] == 'E')
			count++;
		i++;
	}
	free(map);
	if (count == 1)
		return (0);
	else if (count > 1)
	{
		ft_printf("Error\nIl doit y avoir une seule sortie (E).");
		return (1);
	}
	ft_printf("Error\nIl doit y avoir au moins une sortie (E).");
	return (1);
}
