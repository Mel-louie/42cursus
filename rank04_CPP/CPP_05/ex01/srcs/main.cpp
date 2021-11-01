/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:02:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 17:01:03 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"

void basicsTests( Bureaucrat& bob, Bureaucrat &bobbie )
{
	std::cout << "<------------ TEST CREATE AND DISPLAY BUREAUCRAT INFO ------------>" << std::endl;
	std::cout << std::endl;
	
	
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

	Form f("28B", 5, 5);
	
	operator<<(std::cout, f);
}

int	main()
{
	Bureaucrat b1("Bob", 1);
	Bureaucrat b2("Bobbie", 6);
	std::cout << std::endl;

	basicsTests( b1, b2 );


	std::cout << "<------------ CREATE A FORM 1 ------------>" << std::endl;
	std::cout << std::endl;
	try {
		Form f1("28B", 5, 5);
		std::cout << f1 << std::endl;
	
		b1.signForm(f1);
		f1.beSigned(b1);
		b2.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "<------------ CREATE A FORM 2 ------------>" << std::endl;
	std::cout << std::endl;
	try {
		Form f2("28C", 1, 150);
		std::cout << f2 << std::endl;

		b1.signForm(f2);
		f2.beSigned(b1);
		b2.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "<------------ CREATE A FORM 3 ------------>" << std::endl;
	std::cout << std::endl;
	try {
		Form f3("28A", 0, 150);
		std::cout << f3 << std::endl;

		b1.signForm(f3);
		f3.beSigned(b1);
		b2.signForm(f3);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "<------------ CREATE A FORM 4 ------------>" << std::endl;
	std::cout << std::endl;
	try {
		Form f4("28D", 1, 151);
		std::cout << f4 << std::endl;

		b1.signForm(f4);
		f4.beSigned(b1);
		b2.signForm(f4);
		std::cout << f4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	
	operatorTest();
	std::cout << std::endl;
	// leaks macos
	// system("leaks Form");
	return (0);
}
