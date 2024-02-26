/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_cycles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:36:30 by marvin            #+#    #+#             */
/*   Updated: 2024/01/26 03:36:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solib_time.h"

uint64_t so_get_cycles(void) {
    uint32_t lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return (((uint64_t)hi << 32) | lo);
}

// Fonction pour convertir la fréquence en cycles par milliseconde
double mhz_to_cycles_per_ms(double frequencyMHz) {
    return frequencyMHz * 1e6 / 1000000.0;  // Convertit en cycles par milliseconde
}

// Fonction pour convertir les cycles en millisecondes
double cycles_to_ms(uint64_t cycles, double cpuFrequencyPerMs) {
    return cycles / cpuFrequencyPerMs;
}