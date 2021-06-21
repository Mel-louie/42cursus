/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_codes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:16 by user42            #+#    #+#             */
/*   Updated: 2021/06/21 18:13:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_CODES_H
# define EXIT_CODES_H

# define ERR_ARG "Error\n\033[0;35mWrong number of arguments.\033[0m\n"
# define ER_BAD_EXT "Error\n\033[0;35mMap extention must be \'.ber\'\033[0m\n"
# define ER_END "Error\n\033[0;35m\'.ber\' mustn't end with a \\n\033[0m\n"
# define ER_MEMORY "Error\n\033[0;35mCan't alloc memory.\033[0m\n"
# define ER_MULTIC "Error\n\033[0;35mMulti 'P' or 'E' in the map.\033[0m\n"
# define ER_NOTSURR "Error\n\033[0;35mWrong map's format.\033[0m\n"
# define ER_OPEN "Error\n\033[0;35mCan't open the file map.\033[0m\n"
# define ER_WRONGCHAR "Error\n\033[0;35mMap contains wrong char.\033[0m\n"
# define EXIT_OK "\033[1;32mSo Long, and Thanks for All the Fish 🐟\033[0m\n"

#endif
