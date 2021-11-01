/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:06:23 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:27:08 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45), _target( "houseDefault" )
{
	std::cout << "RobotomyRequestForm default constructor has been called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm("RobotomyRequestForm", 72, 45), _target( target )
{
	std::cout << "RobotomyRequestForm constructor has been called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const& cpy ): AForm("RobotomyRequestForm", 72, 45), _target(cpy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor has been called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor has been called" << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const& src )
{
	if (this != &src )
	{
		AForm::operator=( src );
		this->_target = src.getTarget();
	}
	return ( *this );
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return ( this->_target );
}

void	RobotomyRequestForm::execute( Bureaucrat const& executor ) const
{
	int	halfOfTHeTime = 0;

	if ( this->getIsSign() == false )
		throw AForm::AFormNotSignedException();
	if ( this->getGradeToExe() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << ", grade " << executor.getGrade() << " executes Form " << this->getName() << std::endl;
		std::cout << "BzZZZZzzzzZzzzz... BzzzzZZZzzZZZzzzzzz... BBZZZZZzZZzzZZZZZZ... BBBZZZZZZZZZZZZZzzzzzz.Zz.." << std::endl;
		
		//pseudo-random number generator
		srand( time ( NULL ));
		halfOfTHeTime = rand();
		if ( halfOfTHeTime % 2 == 0 )
			std::cout << this->getTarget() << " is Robotomised. The Robotomy was a SUCCESS!!" << std::endl;
		else
			std::cout << this->getTarget() << " isn't Robotomised. The Robotomy was a FAILURE?!" << std::endl;
	}
}
