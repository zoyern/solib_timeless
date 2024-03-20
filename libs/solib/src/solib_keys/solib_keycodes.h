/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_keycodes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:34:39 by almounib          #+#    #+#             */
/*   Updated: 2024/02/28 08:41:48 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_KEYCODES_H
# define SOLIB_KEYCODES_H

/*
Niveau 1	pas de touche modificatrice (0)
Niveau 2	⇧ (1)
Niveau 3	Alt gr (2)
Niveau 4	Alt gr + ⇧ (2 + 1 = 3)
*/

/*typedef struct s_solib_keycode {
	int	space = 32;
	int	exclam = 33;
	int	quotedbl = 34;
	int	numbersign = 35;
	int	dollar = 36;
	int	percent = 37;
	int	ampersand = 38;
	int	apostrophe = 39;
	int	parenleft = 40;
	int	parenright = 41;
	int	asterisk = 42;
	int	plus = 43;
	int	comma = 44;
	int	minus = 45;
	int	period = 46;
	int	slash = 47;
	int	alpha_0 = 48;
	int	alpha_1 = 49;
	int	alpha_2 = 50;
	int	alpha_3 = 51;
	int	alpha_4 = 52;
	int	alpha_5 = 53;
	int	alpha_6 = 54;
	int	alpha_7 = 55;
	int	alpha_8 = 56;
	int	alpha_9 = 57;
	int colon = 58;
	int	semicolon = 59;
	int	less = 60;
	int	equal = 61;
	int	greater = 62;
	int	question = 63;
	int	at = 64;
	int	a_up = 65;
	int	b_up = 66;
	int	c_up = 67;
	int	d_up = 68;
	int	e_up = 69;
	int	f_up = 70;
	int	g_up = 71;
	int	h_up = 72;
	int	i_up = 73;
	int	j_up = 74;
	int	k_up = 75;
	int	l_up = 76;
	int	m_up = 77;
	int	n_up = 78;
	int	o_up = 79;
	int	p_up = 80;
	int	q_up = 81;
	int	r_up = 82;
	int	s_up = 83;
	int	t_up = 84;
	int	u_up = 85;
	int	v_up = 86;
	int	w_up = 87;
	int	x_up = 88;
	int	y_up = 89;
	int	z_up = 90;
	int	bracketleft = 91;
	int	backslash = 92;
	int	bracketright = 93;
	int	circum = 94;
	int	underscore = 95;
	int	grave = 96;
	int	a = 97;
	int	b = 98;
	int	c = 99;
	int	d = 100;
	int	e = 101;
	int	f = 102;
	int	g = 103;
	int	h = 104;
	int	i = 105;
	int	j = 106;
	int	k = 107;
	int	l = 108;
	int	m = 109;
	int	n = 110;
	int	o = 111;
	int	p = 112;
	int	q = 113;
	int	r = 114;
	int	s = 115;
	int	t = 116;
	int	u = 117;
	int	v = 118;
	int	w = 119;
	int	x = 120;
	int	y = 121;
	int	z = 122;
	int	braceleft = 123;
	int	bar = 124;
	int	braceright = 125;
	int	tilde = 126;
	int	nobreakspace = 160;
	int	exclamdown = 161;
	int	cent = 162;
	int	sterling = 163;
	int	currency = 164;
	int	yen = 165;
	int	brokenbar = 166;
	int	section = 167;
	int	diaeresis = 168;
	int	copyright = 169;
	int	ordfeminine = 170;
	int	guillemotleft = 171;
	int	notsign = 172;
	int	hyphen = 173;
	int	 registered = 174;
	int	macron = 175;
	int	degree = 176;
	int	twosuperior = 178;
	int	threesuperior = 179;
	int	acute = 180;
	int	mu = 181;
	int	paragraph = 182;
	int	onesuperior = 185;
	int	eacute_up = 201;
	int	eacute = 233;
	int	dead_breve = 65109;
	int	dead_caron = 65114;
	int	dead_cedilla = 65115;
	int	dead_ogonek = 65116;
	int	backspace = 65288;
	int	tab = 65289;
	int	clear = 65291;
	int	return_ = 65293;
	int	pause = 65299;
	int	scroll_lock = 65300;
	int	escape = 65307;
	int	home = 65360;
	int	left = 65361;
	int	up = 65362;
	int	right = 65363;
	int	down = 65364;
	int	pg_up = 65365;
	int	pg_dn = 65366;
	int	end = 65367;
	int	insert = 65379;
	int	cancel = 65385;
	int	num_lock = 65407;
	int	keypad_enter = 65421;
	int	keypad_home = 65429;
	int	keypad_left = 65430;
	int	keypad_up = 65431;
	int	keypad_right = 65432;
	int	keypad_down = 65433;
	int	keypad_pg_up = 65434;
	int	keypad_pg_dn = 65435;
	int	keypad_end = 65436;
	int	keypad_begin = 65437;
	int	keypad_insert = 65438;
	int	keypad_delete = 65439;
	int	keypad_multiply = 65450;
	int	keypad_plus = 65451;
	int	keypad_separator = 65452;
	int	keypad_minus = 65453;
	int	keypad_decimal = 65454;
	int	keypad_divide = 65455;
	int	keypad_0 = 65456;
	int	keypad_0 = 65456;
	int	keypad_1 = 65457;
	int	keypad_2 = 65458;
	int	keypad_3 = 65459;
	int	keypad_4 = 65460;
	int	keypad_5 = 65461;
	int	keypad_6 = 65462;
	int	keypad_7 = 65463;
	int	keypad_8 = 65464;
	int	keypad_9 = 65465;
	int	keypad_equal = 65469;
	int	f1 = 65470;
	int	f2 = 65471;
	int	f3 = 65472;
	int	f4 = 65473;
	int	f5 = 65474;
	int	f6 = 65475;
	int	f7 = 65476;
	int	f8 = 65477;
	int	f9 = 65478;
	int	f10 = 65479;
	int	f11 = 65480;
	int	f12 = 65481;
	int	shift_left = 65505;
	int	shift_right = 65506;
	int	ctrl_left = 65507;
	int	ctrl_right = 65508;
	int	caps_lock = 65509;
	int	alt = 65513;
	int	alt_gr = 65514;
	int	delete_ = 65535;
} t_solib_keycode;*/

#endif