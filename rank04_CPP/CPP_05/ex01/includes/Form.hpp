/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:31:41 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 16:29:52 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string	const	_name;
	bool	_isSign;
	int const	_gradeToSign;
	int const	_gradeToExe;

public:
	Form( void );
	Form( std::string name, int gradeToSign, int gradeToExe );
	Form( Form const& cpy );
	~Form( void );

	Form&	operator=( Form const& src );

	std::string const	getName( void ) const;
	bool	getIsSign( void ) const;
	int	getGradeToSign( void ) const;
	int	getGradeToExe( void ) const;

	void beSigned( Bureaucrat& bur);

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

std::ostream&	operator<<( std::ostream& o, Form const& src );

#endif
