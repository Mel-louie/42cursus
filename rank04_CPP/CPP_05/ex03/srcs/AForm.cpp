/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:56:12 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:23:06 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

/*
 * Default AForm requires the highest grade (1) to be signed and executed
 */

AForm::AForm( void ): _name( "johnSmith" ), _isSign(false), _gradeToSign(1), _gradeToExe(1)
{
	return ;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExe ): _name( name ), _isSign(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe)
{

	if ( gradeToSign < 1 || gradeToExe < 1)
		throw AForm::GradeTooHighException();
	if ( gradeToSign > 150 || gradeToExe > 150)
		throw AForm::GradeTooLowException();
	
	return ;
}

AForm::AForm( AForm const& cpy ): _name(cpy.getName()), _isSign(false), _gradeToSign(cpy.getGradeToSign()), _gradeToExe(cpy.getGradeToExe())
{

	if ( cpy.getGradeToSign() < 1 || cpy.getGradeToExe() < 1)
		throw AForm::GradeTooHighException();
	if ( cpy.getGradeToSign() > 150 || cpy.getGradeToExe() > 150)
		throw AForm::GradeTooLowException();
	
	return ;
}

AForm::~AForm( void )
{
	return ;
}

AForm&	AForm::operator=( AForm const& src )
{
	if (this != &src )
		this->_isSign = src.getIsSign();
	return ( *this );
}

std::string const	AForm::getName( void ) const
{
	return ( this->_name );
}

bool	AForm::getIsSign( void ) const
{
	return ( this->_isSign );
}

int	AForm::getGradeToSign( void ) const
{	
	return ( this->_gradeToSign);
}

int	AForm::getGradeToExe( void ) const
{	
	return ( this->_gradeToExe);
}

void	AForm::beSigned( Bureaucrat& bur )
{
	if (bur.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_isSign = true;
	return ;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is to high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is to low!");
}

const char* AForm::AFormNotSignedException::what() const throw()
{
	return ("Form isn't sign!");
}

std::ostream&	operator<<( std::ostream& o, AForm const& src )
{
	o << src.getName() << ": Form is ";
	if (src.getIsSign() == true)
		o << "signed";
	else
		o << "not signed";
	o << ". Grade minimun to be signed: " << src.getGradeToSign();
	o << ". Grade minimun to be execute: " << src.getGradeToExe();
	o << std::endl;
	return ( o );
}
