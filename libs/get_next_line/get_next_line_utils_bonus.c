/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:28:09 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/25 17:10:45 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned long	ft_strlen(const char *str)
{
	int	k;

	k = 0;
	if (!str)
		return (0);
	while (str[k])
		k++;
	return (k);
}

void	ft_strmcat(char **dst, char *src)
{
	char	*out;
	int		dst_len;
	int		src_len;
	int		k;

	dst_len = ft_strlen(*dst);
	src_len = ft_strlen(src);
	out = malloc((dst_len + src_len + 1) * sizeof(char));
	k = 0;
	while (k < (dst_len + src_len))
	{
		if (k < dst_len)
			out[k] = (*dst)[k];
		else
		{
			if (src[k - dst_len] == -1)
				break ;
			out[k] = src[k - dst_len];
		}
		k++;
	}
	out[k] = 0;
	free(*dst);
	*dst = out;
}

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long sz)
{
	unsigned long	len;

	len = (ft_strlen(src));
	if (!sz)
		return (len);
	while (*src && sz-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}

int	has_char(char *str, char c)
{
	int	k;

	k = -1;
	if (!str)
		return (-1);
	while (str[++k])
		if (str[k] == c)
			return (k);
	return (-1);
}

char	*ft_substr(char const *s, unsigned long start, unsigned long len)
{
	char			*t;
	unsigned long	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_stralloc(1, 0));
	i = ft_strlen(s + start);
	if (len > i)
		len = i;
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	ft_strlcpy(t, s + start, len + 1);
	return (t);
}
