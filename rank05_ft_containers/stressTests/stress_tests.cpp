/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stress_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:00:31 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/31 15:59:51 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <iostream>
#include <iterator>
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"

int	vectorStressTest()
{
	std::cout << std::endl;
	std::cout << "<----- VECTOR STRESS TEST ----->" << std::endl;
	std::cout << std::endl;

	// start measuring time
	struct timespec std_begin, std_end; 
	clock_gettime(CLOCK_REALTIME, &std_begin);
	std::vector<int>	s(1e7,888);
	
	s.assign(1e6, 65);
	s.insert(s.begin(), 1e8, 8);
	s.erase(s.begin(), s.end());
	
	// stop measuring time and calculate the elapsed time
	clock_gettime(CLOCK_REALTIME, &std_end);
	long std_seconds = std_end.tv_sec - std_begin.tv_sec;
	long std_nanoseconds = std_end.tv_nsec - std_begin.tv_nsec;
	double std_elapsed = std_seconds + std_nanoseconds*1e-9;


	// start measuring time
	struct timespec ft_begin, ft_end; 
	clock_gettime(CLOCK_REALTIME, &ft_begin);	
	ft::vector<int>	f(1e7,888);

	f.assign(1e6, 65);
	f.insert(f.begin(), 1e8, 8);
	f.erase(f.begin(), f.end());
	
	// stop measuring time and calculate the elapsed time
	clock_gettime(CLOCK_REALTIME, &ft_end);
	long ft_seconds = ft_end.tv_sec - ft_begin.tv_sec;
	long ft_nanoseconds = ft_end.tv_nsec - ft_begin.tv_nsec;
	double ft_elapsed = ft_seconds + ft_nanoseconds*1e-9;
	
	if (ft_elapsed > std_elapsed * 20)
	{
		std::cout << "\033[31mStress test isn't OK:\033[0m" << std::endl;
		std::cout << "ft::vector time:  " << ft_elapsed << std::endl
			<< "std::vector time: " << std_elapsed << " | std time * 20 = "<< std_elapsed * 20 << std::endl;
		return (1);
	}
	else
	{
		std::cout << "\033[32mStress test is OK:\033[0m" << std::endl;
		std::cout << "ft::vector time:  " << ft_elapsed << std::endl
			<< "std::vector time: " << std_elapsed << " | std time * 20 = "<< std_elapsed * 20 << std::endl;
		return (0);
	}
}

int	stackStressTest()
{
	std::cout << std::endl;
	std::cout << "<----- STACK STRESS TEST ----->" << std::endl;
	std::cout << std::endl;
	std::vector<int> v(1e7, 42);

	// start measuring time
	struct timespec std_begin, std_end; 
	clock_gettime(CLOCK_REALTIME, &std_begin);
	std::stack<int, std::vector<int> >	s1(v);
	
	for (int i = 0 ; i < 1e6 ; i++)
		s1.push(i);

	while (!s1.empty())
		s1.pop();
	
	// stop measuring time and calculate the elapsed time
	clock_gettime(CLOCK_REALTIME, &std_end);
	long std_seconds = std_end.tv_sec - std_begin.tv_sec;
	long std_nanoseconds = std_end.tv_nsec - std_begin.tv_nsec;
	double std_elapsed = std_seconds + std_nanoseconds*1e-9;


	// start measuring time
	struct timespec ft_begin, ft_end; 
	clock_gettime(CLOCK_REALTIME, &ft_begin);	
	ft::stack<int, std::vector<int> >	f1(v);

	for (int i = 0 ; i < 1e6 ; i++)
		f1.push(i);

	while (!f1.empty())
		f1.pop();
	
	// stop measuring time and calculate the elapsed time
	clock_gettime(CLOCK_REALTIME, &ft_end);
	long ft_seconds = ft_end.tv_sec - ft_begin.tv_sec;
	long ft_nanoseconds = ft_end.tv_nsec - ft_begin.tv_nsec;
	double ft_elapsed = ft_seconds + ft_nanoseconds*1e-9;
	
	if (ft_elapsed > std_elapsed * 20)
	{
		std::cout << "\033[31mStress test isn't OK:\033[0m" << std::endl;
		std::cout << "ft::stack time:  " << ft_elapsed << std::endl
			<< "std::stack time: " << std_elapsed << " | std time * 20 = "<< std_elapsed * 20 << std::endl;
		return (1);
	}
	else
	{
		std::cout << "\033[32mStress test is OK:\033[0m" << std::endl;
		std::cout << "ft::stack time:  " << ft_elapsed << std::endl
			<< "std::stack time: " << std_elapsed << " | std time * 20 = "<< std_elapsed * 20 << std::endl;
		return (0);
	}
}

int main()
{
	vectorStressTest();
	stackStressTest();
	return (0);
}