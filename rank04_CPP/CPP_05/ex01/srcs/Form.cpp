/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:56:12 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 16:44:04 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/*
 * Default form requires the highest grade (1) to be signed and executed
 */

Form::Form( void ): _name( "johnSmith" ), _isSign(false), _gradeToSign(1), _gradeToExe(1)
{
	std::cout << "Form default constructor has been called" << std::endl;
	return ;
}

Form::Form( std::string name, int gradeToSign, int gradeToExe ): _name( name ), _isSign(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{
	std::cout << "Form constructor has been called" << std::endl;

	if ( gradeToSign < 1 || gradeToExe < 1)
		throw Form::GradeTooHighException();
	if ( gradeToSign > 150 || gradeToExe > 150)
		throw Form::GradeTooLowException();
	
	return ;
}

Form::Form( Form const& cpy ): _name(cpy.getName()), _isSign(false), _gradeToSign(cpy.getGradeToSign()), _gradeToExe(cpy.getGradeToExe())
{
	std::cout << "Form copy constructor has been called" << std::endl;

	if ( cpy.getGradeToSign() < 1 || cpy.getGradeToExe() < 1)
		throw Form::GradeTooHighException();
	if ( cpy.getGradeToSign() > 150 || cpy.getGradeToExe() > 150)
		throw Form::GradeTooLowException();
	
	return ;
}

Form::~Form( void )
{
	std::cout << "Form destructor has been called" << std::endl;
	return ;
}

Form&	Form::operator=( Form const& src )
{
	if (this != &src )
		this->_isSign = src.getIsSign();
	return ( *this );
}

std::string const	Form::getName( void ) const
{
	return ( this->_name );
}

bool	Form::getIsSign( void ) const
{
	return ( this->_isSign );
}

int	Form::getGradeToSign( void ) const
{	
	return ( this->_gradeToSign);
}

int	Form::getGradeToExe( void ) const
{	
	return ( this->_gradeToExe);
}

void	Form::beSigned( Bureaucrat& bur )
{
	if (bur.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_isSign = true;
	return ;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is to high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is to low!");
}

std::ostream&	operator<<( std::ostream& o, Form const& src )
{
	o << src.getName() << " form is ";
	if (src.getIsSign() == true)
		o << "signed";
	else
		o << "not signed";
	o << ". Grade minimun to be signed: " << src.getGradeToSign();
	o << ". Grade minimun to be execute: " << src.getGradeToExe();
	o << std::endl;
	return ( o );
}
