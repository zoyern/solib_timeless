/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:50:51 by tauer             #+#    #+#             */
/*   Updated: 2023/08/23 19:17:28 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (1);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	index_num(char c, char *base)
{
	int	c_index;

	c_index = 0;
	while (base[c_index] && base[c_index] != c)
		c_index++;
	return (c_index);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	if (check_base(base) == 0)
	{
		i = 0;
		while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		while ((str[i] == '-' || str[i] == '+') && str[i])
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (find_in_base(str[i], base))
		{
			num = (num * ft_strlen(base) + index_num(str[i], base));
			i++;
		}
	}
	return (num * sign);
}
