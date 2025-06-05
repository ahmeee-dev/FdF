/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:57:41 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/01/03 15:37:35 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str && str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str && str[i] == '+')
		i++;
	else if (str && str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
	return (0);
}
