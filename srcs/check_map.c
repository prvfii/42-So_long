/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:31:06 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/25 17:03:09 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	openfile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nProblème avec l'ouverture du fichier,\
		 vérifiez si il est valide.");
		exit(0);
	}
	return (fd);
}

char	*load_map(char *file)
{
	int		fd;
	char	buf[101];
	char	*mapcontent;
	char	*tmp;
	int		nb_read;

	mapcontent = ft_strdup("");
	fd = openfile(file);
	nb_read = read(fd, buf, 100);
	while (nb_read > 0)
	{
		buf[nb_read] = '\0';
		tmp = mapcontent;
		mapcontent = ft_strjoin(mapcontent, buf);
		free(tmp);
		nb_read = read(fd, buf, 100);
	}
	if (nb_read == -1)
	{
		perror("Error reading file");
		close(fd);
		return (NULL);
	}
	close(fd);
	return (mapcontent);
}

int	checkber(char *file)
{
	if (ft_strber(file, ".ber") == 1)
		return (0);
	else
	{
		ft_printf("Error\nLa map doit avoir l'extension .ber");
		return (1);
	}
}

int	countlines(char *file)
{
	char	*map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = load_map(file);
	if (!map)
		return (-1);
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	count++;
	free(map);
	return (count);
}

int	countcolumns(char *file)
{
	char	*map;
	int		i;

	i = 0;
	map = load_map(file);
	if (!map)
		return (-1);
	while (map[i] != '\n' && map[i] != '\0')
	{
		i++;
	}
	free(map);
	return (i);
}
