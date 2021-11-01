/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:02:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:28:52 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

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



// 	std::cout << std::endl;
// //	std::cout << "RobotomyRequestForm: \n";
// //	b3.signForm(f2);
// //	b4.signForm(f2);
// //	b4.executeForm(f2);
// //	b1.executeForm(f2);
// //	b1.executeForm(f2);
// 	//b1.execute(f2);
// //	b1.executeForm(f2);
// 	std::cout << std::endl;
// //	std::cout << "PresidentialPardonForm: \n";
// //	b3.signForm(f3);
// //	b5.signForm(f3);
// ///	b5.executeForm(f3);
// 	//b1.executeForm(f3);



	
	operatorTest();
	std::cout << std::endl;
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	// // leaks macos
	// // system("leaks Form");

	return (0);
}
