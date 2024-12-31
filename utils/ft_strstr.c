/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fimazouz <fimazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:52:05 by firdawssema       #+#    #+#             */
/*   Updated: 2024/07/23 11:08:09 by fimazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strber(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (haystack[i] != '.')
		i++;
	while (needle[j] && haystack[i])
	{
		if (needle[j] == haystack[i])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	if (needle[j] == '\0' && haystack[i] != '\0')
		return (0);
	if (needle[j] != '\0' && haystack[i] == '\0')
		return (0);
	return (1);
}
