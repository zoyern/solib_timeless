/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:47:51 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 03:47:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_time_by_millis(double millis, int *hours, int *minutes, int *seconds, int *milliseconds)
{
	*hours = ((int)millis / (3600 * 1000));
	*minutes = (((int)millis / 60000) % 60);
	*seconds = (((int)millis / 1000) % 60);
    *milliseconds = ((int)millis - (*hours * 3600 * 1000) - (*minutes * 60000) - (*seconds * 1000));
}

double fps_to_ms(int fps)
{
    return 1000.0 / fps;
}

int ms_to_fps(double ms)
{
    return (int)(1000.0 / ms);
}