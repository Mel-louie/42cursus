/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:55:15 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/02 20:36:12 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>

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
int	checkLitteraleValue( char* end );

#endif
