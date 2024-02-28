/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 06:40:28 by almounib          #+#    #+#             */
/*   Updated: 2024/02/28 09:27:50 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_UTILS_H
# define SOLIB_UTILS_H

//Utils
t_solib_timing	get_time_by_millis(double millis);
double			fps_to_ms(int fps);
int				ms_to_fps(double ms);

#endif