/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:05:42 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 14:43:58 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	int	_grade;
	std::string const	_name;

public:
	Bureaucrat( void );
	Bureaucrat( std::string const name, int grade );
	Bureaucrat( Bureaucrat const& cpy );
	~Bureaucrat( void );

	Bureaucrat&	operator=( Bureaucrat const& src );

	int	getGrade( void ) const;
	std::string const	getName( void ) const;

	void	increment( void );
	void	decrement( void );

	class GradeTooHighException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	
	class GradeTooLowException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& o, Bureaucrat const& src );

#endif
