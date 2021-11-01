/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:31:41 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:05:06 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string	const	_name;
	bool	_isSign;
	int const	_gradeToSign;
	int const	_gradeToExe;

public:
	AForm( void );
	AForm( std::string name, int gradeToSign, int gradeToExe );
	AForm( AForm const& cpy );
	virtual ~AForm( void );

	AForm&	operator=( AForm const& src );

	std::string const	getName( void ) const;
	bool	getIsSign( void ) const;
	int	getGradeToSign( void ) const;
	int	getGradeToExe( void ) const;

	void beSigned( Bureaucrat& bur);

	virtual void	execute (Bureaucrat const & executor) const = 0;

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
	
	class AFormNotSignedException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	
};

std::ostream&	operator<<( std::ostream& o, AForm const& src );

#endif
