/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csubires <csubires@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:03:28 by csubires          #+#    #+#             */
/*   Updated: 2024/07/19 10:52:50 by csubires         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# ifndef HEX_BASE
#  define HEX_BASE "0123456789abcdef"
# endif
# ifndef WIN_W
#  define WIN_W 1920
# endif
# ifndef WIN_H
#  define WIN_H 1080
# endif
# ifndef STEP
#  define STEP 10
# endif
# ifndef ROT_STEP
#  define ROT_STEP 0.05
# endif
# ifndef ZOOM_STEP
#  define ZOOM_STEP 0.5
# endif
# ifndef ALTITUDE_STEP
#  define ALTITUDE_STEP 0.1
# endif

# define BG_COLOR	0xFFFFFF
# define DEGREE_30	0.523599
# define DEGREE_45	0.785399
# define DEGREE_60	1.047197

#endif
