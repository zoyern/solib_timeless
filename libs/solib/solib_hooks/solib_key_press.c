/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_key_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 02:15:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/11 02:15:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_hooks.h"

unsigned long	ft_unbrlen_base(size_t n, int base)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_uitoa_base(size_t n, size_t base, char *ref_base)
{
	size_t	size;
	char	*result;

	if (base < 2 || base > 16)
		return (NULL);
	size = ft_unbrlen_base(n, base);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = 0;
	if (!n)
		result[0] = '0';
	while (n > 0)
	{
		result[size--] = ref_base[n % base];
		n /= base;
	}
	return (result);
}

int	solib_key_press(int keycode, t_solib *solib)
{
	if (((unsigned char)keycode >= 'a' && (unsigned char)keycode >= 'z') && solib->inputs.keys[229].pressed)
	{
		printf("maj keyPress keycode :%d -- %c\n", (unsigned char)keycode - 32, (unsigned char)keycode - 32);
		solib->inputs.keys[(unsigned char)keycode - 32].pressed = TRUE;
	}
	solib->inputs.keys[(unsigned char)keycode].pressed = TRUE;
	printf("keycode : %d -- %d -- %c -- %s\n", keycode, (unsigned char)keycode,(unsigned char)keycode, ft_uitoa_base((size_t)keycode, 16, "0123456789ABCDEF"));
	//printf("keycode : %d -- %ld -- %s\n", keycode + 10, (unsigned long)keycode + 10, ft_uitoa_base((unsigned long)keycode + 10, 16, "0123456789ABCDEF"));
	//printf("keycode : %d -- uckeycode : %d -- symbole : %c -- maj : %d -- upercase : %d -- symbole : %c\n",keycode, (unsigned char)keycode, (unsigned char)keycode, solib->inputs.keys[225].pressed, (unsigned char)keycode - 32, (unsigned char)keycode - 32);
	if (solib->events.key_press)
		solib->events.key_press(keycode);
    return 0;
}
