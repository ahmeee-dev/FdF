/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:41:18 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/05 13:04:32 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <unistd.h>

float	initialize(float *res, float *f_check, int *i, int *j)
{
	(*res) = 0.0;
	(*f_check) = 1.0;
	(*i) = 0;
	(*j) = 0;
	return (1.0);
}

float	ft_atof(char *str, int done)
{
	int		i;
	int		j;
	float	res;
	float	f_check;
	float	sign;

	sign = initialize(&res, &f_check, &i, &j);
	while (j < done)
	{
		if (str[i] == ' ' && i > 0 && (str[i - 1] != ' '))
			j++;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '.' || str[i] == ',')
			f_check = 0;
		if (str[i] != '.' && f_check != 0)
			res = res * 10.0 + ((float)str[i] - 48.0);
		i++;
	}
	return ((res * sign));
}

void	line_division(int *i, char *str, t_coordinates *matrix, t_map *map)
{
	int	done;

	done = 0;
	while (done < map->map_x)
	{
		matrix[*i].z = ft_atof(str, done);
		done++;
		(*i)++;
	}
}

void	z_position(t_coordinates *matrix, t_map *map)
{
	int		i;
	char	*res;

	i = 0;
	map->fd = open(map->file, O_RDONLY);
	res = get_next_line(map->fd);
	while (res != NULL)
	{
		line_division(&i, res, matrix, map);
		free(res);
		res = get_next_line(map->fd);
	}
	free(res);
}

void	matrix_population(t_coordinates **matrix, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_x * map->map_y)
	{
		(*matrix)[i].x = i % map->map_x;
		(*matrix)[i].y = i / map->map_x;
		i++;
	}
	z_position(*matrix, map);
}
