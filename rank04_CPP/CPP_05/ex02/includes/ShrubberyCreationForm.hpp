/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:48:47 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:26:35 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>
#include <iostream>
#include <stdio.h>

class ShrubberyCreationForm: public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const& cpy );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm&	operator=( ShrubberyCreationForm const& src );

	std::string	getTarget( void ) const;

	void	execute ( Bureaucrat const& executor ) const;

	class FormNotOpenException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
