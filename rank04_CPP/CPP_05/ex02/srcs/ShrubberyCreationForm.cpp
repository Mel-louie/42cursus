/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:06:23 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:27:08 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137), _target( "houseDefault" )
{
	std::cout << "ShrubberyCreationForm default constructor has been called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("ShrubberyCreationForm", 145, 137), _target( target )
{
	std::cout << "ShrubberyCreationForm constructor has been called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& cpy ): AForm("ShrubberyCreationForm", 145, 137), _target(cpy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor has been called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor has been called" << std::endl;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const& src )
{
	if (this != &src )
	{
		AForm::operator=( src );
		this->_target = src.getTarget();
	}
	return ( *this );
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return ( this->_target );
}


