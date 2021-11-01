/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:41:34 by mdesfont          #+#    #+#             */
/*   Updated: 2021/11/01 18:28:43 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern( void )
{
    std::cout << "Intern constructor has been called" << std::endl;

	this->_arrForms[0] = "ShrubberyCreationForm";
	this->_arrForms[1] = "RobotomyRequestForm";
	this->_arrForms[2] = "PresidentialPardonForm";
	this->_ptrForms[0] = &Intern::makeShrubberyForm;
	this->_ptrForms[1] = &Intern::makeRobotomyForm;
	this->_ptrForms[2] = &Intern::makePresisentialForm;
}

Intern::Intern( Intern const& cpy )
{
	std::cout << "Intern copy constructor has been called" << std::endl;

	this->_arrForms[0] = cpy._arrForms[0];
	this->_arrForms[1] = cpy._arrForms[1];
	this->_arrForms[2] = cpy._arrForms[2];
	this->_ptrForms[0] = cpy._ptrForms[0];
	this->_ptrForms[1] = cpy._ptrForms[1];
	this->_ptrForms[2] = cpy._ptrForms[2];
}

Intern::~Intern( void )
{
	std::cout << "Intern destructor has been called" << std::endl;
}

Intern&	Intern::operator=( Intern const& src )
{
	(void)src;
	return ( *this );
}

AForm*	Intern::makeForm( std::string form, std::string target )
{
	int	i = -1;

	while (++i < 3)
	{
		if ( form.compare( this->_arrForms[i] ) == 0)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (( this->*_ptrForms[i] )( target ));
		}
	}
	std::cout << "Requested Form (" << form << ") doesn't exist. Please, be carefull." << std::endl;
	return ( NULL );
}

AForm*	Intern::makeShrubberyForm( std::string target )
{
	return ( new ShrubberyCreationForm( target ) );
}

AForm*	Intern::makeRobotomyForm( std::string target )
{
	return ( new RobotomyRequestForm( target ) );
}

AForm*	Intern::makePresisentialForm( std::string target )
{
	return ( new PresidentialPardonForm( target ) );
}
