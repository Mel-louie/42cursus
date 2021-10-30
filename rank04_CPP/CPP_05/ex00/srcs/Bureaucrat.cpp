/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:57:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 14:43:52 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _grade(10), _name("johnSmith")
{
	std::cout << "Bureaucrat default constructor has been called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string const name, int grade): _name( name )
{
	std::cout << "Bureaucrat constructor has been called" << std::endl;

	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const& cpy ): _name( cpy.getName() )
{
	std::cout << "Bureaucrat copy constructor has been called" << std::endl;

	if ( cpy.getGrade() < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( cpy.getGrade() > 150 )
		throw Bureaucrat::GradeTooLowException();
	this->_grade = cpy.getGrade();
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor has been called" << std::endl;
	return ;
}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat const& src )
{
	if (this != &src )
		this->_grade = src.getGrade();
	return ( *this );
}

int	Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

std::string const	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

void	Bureaucrat::increment( void )
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = this->_grade - 1;
	return ;
}

void	Bureaucrat::decrement( void )
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = this->_grade + 1;
	return ;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is to high! 1 is the max.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is to low! 150 is the min.");
}

std::ostream&	operator<<( std::ostream& o, Bureaucrat const& src )
{
	o << src.getName() << " bureaucrat grade " << src.getGrade() << std::endl;
	return ( o );
}
