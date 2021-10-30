/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:57:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 16:02:03 by louielouie       ###   ########.fr       */
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

void	Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned( *this );
		std::cout << "Bureaucrate " << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Bureaucrat " << this->_name << " cannot sign because : " << e.what() << std::endl;
	}
	
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is to high! Max grade in 1.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is to low! Min grade is 150.");
}

std::ostream&	operator<<( std::ostream& o, Bureaucrat const& src )
{
	o << src.getName() << " bureaucrat grade " << src.getGrade() << std::endl;
	return ( o );
}
