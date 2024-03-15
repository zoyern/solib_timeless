/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:29:31 by tauer             #+#    #+#             */
/*   Updated: 2023/08/24 10:56:54 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi_base(char *str, char *base);
int		index_num(char c, char *base);
int		ft_strlen(char *base);
int		find_in_base(char c, char *base);
int		check_base(char *base);

char	*mal_nbr(long int nbr, int len_base, int i)
{
	char	*str;
	int		null;
	int		size;

	null = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		null += 1;
	}
	while (nbr > 0)
	{
		nbr /= len_base;
		i++;
	}
	size = i + null;
	str = (char *)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_rev_numbers(char *str, int i, int size)
{
	char	current;

	while (i < (size / 2))
	{
		current = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = current;
		i++;
	}
	return (str);
}

char	*ft_stock_base(long int nbr, char *base, int len_base, int i)
{
	long int	copy_start;
	char		*duplicated;

	if (nbr == 0)
	{
		duplicated = (char *)malloc(sizeof(char) * (2));
		duplicated[0] = base[0];
		duplicated[1] = '\0';
		return (duplicated);
	}
	copy_start = nbr;
	duplicated = mal_nbr(nbr, len_base, 0);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		duplicated[i++] = base[nbr % len_base];
		nbr /= len_base;
	}
	if (copy_start < 0)
		duplicated[i++] = '-';
	duplicated[i] = '\0';
	return (ft_rev_numbers(duplicated, 0, ft_strlen(duplicated)));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;

	if (!(base_from) || !(base_to) || !(nbr))
		return (NULL);
	if (check_base(base_from) == 1 || check_base(base_to) == 1)
		return (NULL);
	str = ft_stock_base(ft_atoi_base(nbr, base_from), base_to,
			ft_strlen(base_to), 0);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*base_from;
// 	char	*base_to;
// 	char	*result;

// 	str = "0";
// 	base_from = "01";
// 	base_to = "123456789";
// 	result = ft_convert_base(str, base_from, base_to);
// 	printf("convert base :%s\n", result);
// 	if (result[0] == '\0')
// 		return (0);
// 	free(result);
// 	return (0);
// }
