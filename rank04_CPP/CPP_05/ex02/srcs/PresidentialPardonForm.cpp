/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:06:23 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/01 17:14:25 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5), _target( "houseDefault" )
{
	std::cout << "PresidentialPardonForm default constructor has been called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PresidentialPardonForm", 25, 5), _target( target )
{
	std::cout << "PresidentialPardonForm constructor has been called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const& cpy ): AForm("PresidentialPardonForm", 25, 5), _target(cpy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor has been called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructor has been called" << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const& src )
{
	if (this != &src )
	{
		AForm::operator=( src );
		this->_target = src.getTarget();
	}
	return ( *this );
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return ( this->_target );
}

void	PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
	if ( this->getIsSign() == false )
		throw AForm::AFormNotSignedException();
	if ( this->getGradeToExe() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	else
	{                           
		std::cout << "Bureaucrat " << executor.getName() << ", grade " << executor.getGrade() << " executes Form " << this->getName() << std::endl;
		std::cout << this->getTarget() << " has been pardonned by the Great President Zafod Beeblebrox" << std::endl;
	}	
}

const char*	PresidentialPardonForm::FormNotOpenException::what() const throw()
{
	return ("PresidentialPardonForm can't be open!");
}
