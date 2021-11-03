/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:55:15 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/04 00:08:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>

/*
 * CONVERTERS
 */
void	printChar( double value );
void	printInt( double value );
void	printDouble( double value );
void	printFloat( double value, int precision );
int	floatPecision( char* str );

/*
 * UTILS
 */
void	displayUsage( void );

#endif
