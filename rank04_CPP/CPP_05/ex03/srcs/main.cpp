/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:02:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/01 18:36:18 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

void basicsTests( Bureaucrat& bob )
{
	std::cout << "I'm a new Bureaucrat, my name is: " << bob.getName() << std::endl;
	std::cout << "My grade is: " << bob.getGrade() << std::endl;
	std::cout << std::endl;
	
	std::cout << "I'm a new Intern, no one cares about my name."<< std::endl;
	std::cout << "I don't have grade." << std::endl;
	std::cout << std::endl;
}

void	shrubberyCreationForm_tests( Bureaucrat& b1, Intern& intern )
{
	std::cout << "<---------- TEST ShrubberyCreationForm ---------->" << std::endl;
	std::cout << std::endl;

	AForm*	shrubbery = intern.makeForm("ShrubberyCreationForm", "garden");
	if ( shrubbery == NULL )
	{
		delete shrubbery;
		return ;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	b1.signForm(*shrubbery);
	b1.executeForm(*shrubbery);

	std::cout << std::endl;
	delete shrubbery;
}

void	robotomyRequestForm( Bureaucrat &b1, Intern& intern )
{
	std::cout << "<----------- TEST RobotomyRequestForm ----------->" << std::endl;
	std::cout << std::endl;

	AForm*	robotomy = intern.makeForm("RobotomyRequestForm", "JeanMi");
	
	std::cout << std::endl;
	if ( robotomy == NULL )
	{
		delete robotomy;
		return ;
	}
	std::cout << std::endl;
	b1.signForm(*robotomy);
	b1.executeForm(*robotomy);

	std::cout << std::endl;
	delete robotomy;
}

void	presidentialPardonForm( Bureaucrat &b1, Intern& intern )
{
	std::cout << "<---------- TEST PresidentialPardonForm ---------->" << std::endl;
	std::cout << std::endl;

	AForm*	president = intern.makeForm("PresidentialPardonForm", "Thierry");
	if ( president == NULL )
	{
		delete president;
		return ;
	}
	std::cout << std::endl;

	b1.signForm(*president);
	b1.executeForm(*president);

	std::cout << std::endl;
	delete president;
}

void	wrongForm( Bureaucrat &b1, Intern& intern )
{
	std::cout << "<--------------- TEST wrongForm --------------->" << std::endl;
	std::cout << std::endl;

	AForm*	wrong = intern.makeForm("WrongForm", "wrong");
	if ( wrong == NULL )
	{
		delete wrong;
		return ;
	}
	std::cout << std::endl;

	b1.signForm(*wrong);
	b1.executeForm(*wrong);

	std::cout << std::endl;
	delete wrong;
}

int	main()
{
	std::cout << std::endl;
	Bureaucrat b1("Bob", 4);
	Intern	intern;
	std::cout << std::endl;
	
	basicsTests( b1 );

	shrubberyCreationForm_tests( b1, intern );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;

	robotomyRequestForm( b1, intern );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;

	presidentialPardonForm( b1, intern );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;

	wrongForm( b1, intern );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;	

	// // leaks macos
	// // system("leaks Form");

	return (0);
}
