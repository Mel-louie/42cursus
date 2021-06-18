/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_codes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:55:25 by mdesfont          #+#    #+#             */
/*   Updated: 2020/07/31 13:45:58 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_CODES_H
# define EXIT_CODES_H

# define OK_CODE "\033[32;1mBye, hope you had a great moment!\033[0m\n"
# define OK_SCREEN "\033[32;1mA screen of the 1st image's been taken!\033[0m\n"

# define ERR_ARGS "Error\nWrong numbers of arguments.\n"
# define ERR_INVALID_EXT "Error\nMap extention should be '.cub'\n"
# define ERR_MEM_ALLOC "Error\nMemory allocation failed.\n"
# define ERR_OPEN "Error\nCouldn't open the file to parse.\n"
# define ERR_OPEN_TEX "Error\nCouldn't open texture file.\n"
# define ERR_DATS "Error\nSome datas seem wrong or empty, check .cub.\n"
# define ERR_RES "Error\nResolution must have 2 numbers, only 2, only digits.\n"
# define ERR_RESO_SMALL "Error\nResolution is to small. Minumum is: 50x50\n"
# define ERR_DUP_RES "Error\nToo much 'R' datas, 'R' needs just one line.\n"
# define ERR_NB_COLOR "Error\nOne color argument is needed, comma separated.\n"
# define ERR_COLOR "Error\nInvalid colors format.\n"
# define ERR_VAL_COLOR "Error\nColors should go from 0 to 255.\n"
# define ERR_DUB_COLOR "Error\nToo much color datas.\n"
# define ERR_NB_TEX "Error\nWrong number of texture's arguments.\n"
# define ERR_DUP_TEX "Error\nToo much texture argument.\n"
# define ERR_MISS_DATS "Error\nArgument(s) missing in .cub file.\n"
# define ERR_PLAYER "Error\nPlayer is missing.\n"
# define ERR_BMPO "Error\nCouldn't open screenshot.bmp.\n"
# define ERR_BMPC "Error\nCouldn't close screenshot.bmp.\n"
# define ERR_MIS_INFO "Error\nBad formating of .cub file.\n"
# define ERR_MAP "Error\nMap isn't well format or contained wrong char.\n"
# define ERR_WRONG_CHAR "Error\nThere is a wrong character in the map.\n"
# define ERR_PLAYER_MANY "Error\nToo many players.\n"

#endif
