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

void	ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
	if ( this->getIsSign() == false )
		throw AForm::AFormNotSignedException();
	if ( this->getGradeToExe() < executor.getGrade() )
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream	fshrubbery;
		std::string	target = this->_target;
		target.append("_shrubbery");
		fshrubbery.open(target.c_str());
		if (!fshrubbery.is_open())
			throw ShrubberyCreationForm::FormNotOpenException();
		else
		{
			std::cout << "Bureaucrat " << executor.getName() << ", grade " << executor.getGrade() << " executes Form " << this->getName() << std::endl;
			fshrubbery << "            #  ## ###\n";
			fshrubbery << "          # #### ######\n";
			fshrubbery << "        ### \\/#|### |/####\n";
			fshrubbery << "      ##\\/#/ \\||/##/_/##/_#\n";
			fshrubbery << "     ###  \\/###|/ \\/ # ###\n";
			fshrubbery << "   ##_\\_#\\_\\## | #/###_/_####\n";
			fshrubbery << "  ## #### # \\ #| /  #### ##/##\n";
			fshrubbery << "   __#_--###`  |{,###---###-~\n";
			fshrubbery << "           #,#@@@#,#\n";
			fshrubbery << "              @@@            \n";
			fshrubbery << "              @@@            \n";
			fshrubbery << "              @@@            \n";
			fshrubbery << "              @@@            \n";
			fshrubbery << "              @@@            \n";
			fshrubbery << "              @@@            \n";
			fshrubbery << "           _ _@@@_ _          \n";
			fshrubbery.close();
		}
	}	
}

const char*	ShrubberyCreationForm::FormNotOpenException::what() const throw()
{
	return ("ShrubberyCreationForm can't be open!");
}
