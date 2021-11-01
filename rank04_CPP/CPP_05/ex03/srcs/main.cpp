/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:02:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/01 17:21:41 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

void basicsTests( Bureaucrat& bob, Bureaucrat &bobbie )
{
	std::cout << "I'm a new Bureaucrat, my name is: " << bob.getName() << std::endl;
	std::cout << "My grade is: " << bob.getGrade() << std::endl;
	std::cout << std::endl;
	
	std::cout << "I'm a new Bureaucrat, my name is: " << bobbie.getName() << std::endl;
	std::cout << "My grade is: " << bobbie.getGrade() << std::endl;
	std::cout << std::endl;
}

void	operatorTest( void )
{
	std::cout << std::endl;
	std::cout << "<--------------- TEST << OPERATOR --------------->" << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm f("Road");
	std::cout << std::endl;
	
	std::cout << "operator<< "; operator<<(std::cout, f);
}

void	shrubberyCreationForm_tests( Bureaucrat& b1, Bureaucrat& b2 )
{
	std::cout << "<---------- TEST ShrubberyCreationForm ---------->" << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm form1("garden");
	ShrubberyCreationForm form2("pool");
	std::cout << std::endl;

	std::cout << "Grade min to be signed: " << form1.getGradeToSign() << ", grade min to be execute: " << form1.getGradeToExe() << std::endl;
	std::cout << std::endl;


	std::cout << "form1:" << std::endl;
	std::cout << std::endl;
	b2.signForm(form1);
	b2.executeForm(form1);
	b1.executeForm(form1);
	b1.signForm(form1);
	b1.executeForm(form1);
	std::cout << std::endl;

	std::cout << "form2:" << std::endl;
	std::cout << std::endl;
	b2.signForm(form2);
	b2.executeForm(form2);
	std::cout << std::endl;

	std::cout << std::endl;
}

void	robotomyRequestForm( Bureaucrat &b1, Bureaucrat &b2 )
{
	std::cout << "<----------- TEST RobotomyRequestForm ----------->" << std::endl;
	std::cout << std::endl;

	RobotomyRequestForm form1("Jean");
	RobotomyRequestForm form2("Michel");
	std::cout << std::endl;

	std::cout << "Grade min to be signed: " << form1.getGradeToSign() << ", grade min to be execute: " << form1.getGradeToExe() << std::endl;
	std::cout << std::endl;


	std::cout << "form1:" << std::endl;
	std::cout << std::endl;
	b2.signForm(form1);
	b2.executeForm(form1);
	b1.executeForm(form1);
	b1.signForm(form1);
	b1.executeForm(form1);
	std::cout << std::endl;

	std::cout << "form2:" << std::endl;
	std::cout << std::endl;
	b2.signForm(form2);
	b2.executeForm(form2);
	std::cout << std::endl;

	std::cout << std::endl;
}

void	presidentialPardonForm( Bureaucrat &b1, Bureaucrat &b2 )
{
	std::cout << "<---------- TEST PresidentialPardonForm ---------->" << std::endl;
	std::cout << std::endl;

	PresidentialPardonForm form1("Bumblebee");
	PresidentialPardonForm form2("Tristan");
	std::cout << std::endl;

	std::cout << "Grade min to be signed: " << form1.getGradeToSign() << ", grade min to be execute: " << form1.getGradeToExe() << std::endl;
	std::cout << std::endl;


	std::cout << "form1:" << std::endl;
	std::cout << std::endl;
	b2.signForm(form1);
	b2.executeForm(form1);
	b1.executeForm(form1);
	b1.signForm(form1);
	b1.executeForm(form1);
	std::cout << std::endl;

	std::cout << "form2:" << std::endl;
	std::cout << std::endl;
	b2.signForm(form2);
	b2.executeForm(form2);
	std::cout << std::endl;

	std::cout << std::endl;
}

int	main()
{
	Bureaucrat b1("Bob", 1);
	Bureaucrat b2("Bobbie", 149);
	std::cout << std::endl;
	
	basicsTests( b1, b2 );

	shrubberyCreationForm_tests( b1, b2 );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;

	robotomyRequestForm( b1, b2 );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;

	presidentialPardonForm( b1, b2 );
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;

	operatorTest();
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// // leaks macos
	// // system("leaks Form");

	return (0);
}
