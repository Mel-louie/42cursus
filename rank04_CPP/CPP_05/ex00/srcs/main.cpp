/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:02:31 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 15:21:59 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"

void basicsTests( Bureaucrat& bob )
{
	std::cout << "<------------ TEST CREATE AND DISPLAY BUREAUCRATE INFO ------------>" << std::endl;
	std::cout << std::endl;
	
	
	std::cout << "I'm a new Bureaucrat, my name is: " << bob.getName() << std::endl;
	std::cout << "My grade is: " << bob.getGrade() << std::endl;
	std::cout << std::endl;

}

void	incrementTests( Bureaucrat& bob )
{
	
	std::cout << "<--------------- TEST INCREMENT " << bob.getName() << " GRADE --------------->" << std::endl;
	std::cout << std::endl;
	
	int	i = bob.getGrade();
	while (i > 1)
	{
		bob.increment();
		i--;
	}
	std::cout << "New grade: " << bob.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "---------- Trying to increment one more time ----------" << std::endl;
	std::cout << std::endl;

	try
	{
		bob.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	decrementTest( Bureaucrat& bob)
{
	std::cout << "<--------------- TEST DECREMENT " << bob.getName() << " GRADE --------------->" << std::endl;
	std::cout << std::endl;
	
	int	i = bob.getGrade();
	while (i < 150)
	{
		bob.decrement();
		i++;
	}
	std::cout << "New grade: " << bob.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "---------- Trying to decrement one more time ----------" << std::endl;
	std::cout << std::endl;

	try
	{
		bob.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	operatorTest( Bureaucrat& bob )
{
	std::cout << "<--------------- TEST << OPERATOR --------------->" << std::endl;
	std::cout << std::endl;
	
	operator<<(std::cout, bob);
	std::cout << std::endl;

}

int	main()
{

	Bureaucrat*	bob = new Bureaucrat("Bob", 42);
	std::cout << std::endl;
	basicsTests( *bob );

	incrementTests( *bob );
	
	decrementTest( *bob );

	operatorTest( *bob );
		
	std::cout << "<------------------------------------------------>" << std::endl;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;

	// leaks macos
	//system("leaks Bureaucrat");
	return (0);
}
