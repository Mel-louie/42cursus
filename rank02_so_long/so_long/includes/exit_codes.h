/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_codes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:16 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 17:50:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_CODES_H
# define EXIT_CODES_H

# define ERR_ARG "Error\n\033[1;34mWrong number of arguments.\033[0m\n"
# define ER_BAD_EXT "Error\n\033[1;34mMap extention must be \'.ber\'\033[0m\n"
# define ER_END "Error\n\033[1;34m\'.ber\' mustn't end with a \\n\033[0m\n"
# define ER_MEMORY "Error\n\033[1;34mCan't alloc memory.\033[0m\n"
# define ER_MULTIC "Error\n\033[1;34mMulti 'P' or 'E' on the map.\033[0m\n"
# define ER_NO_EX "Error\n\033[1;34mThere is no exit\033[0m\n"
# define ER_NO_PL "Error\n\033[1;34mThere is no player.\033[0m\n"
# define ER_NO_CO "Error\n\033[1;34mThere is no colectibles.\033[0m\n"
# define ER_NOTSURR "Error\n\033[1;34mWrong map's format.\033[0m\n"
# define ER_OPEN "Error\n\033[1;34mCan't open the file map.\033[0m\n"
# define ER_REC "Error\n\033[1;34mMap must be rectangular.\033[0m\n"
# define ER_TILES "Error\n\033[1;34mCan't open tiles.\033[0m\n"
# define ER_WRONGCHAR "Error\n\033[1;34mMap contains wrong char.\033[0m\n"
# define EXIT_OK "\033[1;32mSo Long, and Thanks for All the Fish 🐟\033[0m\n"
# define WON "\033[1;32mCONGRATS YOU WON!1!!\nEnjoy the fish 🐟 🐟 🐟\033[0m\n"

#endif
