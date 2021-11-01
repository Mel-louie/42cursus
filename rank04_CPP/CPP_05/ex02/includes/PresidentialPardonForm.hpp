/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:48:47 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/01 17:11:44 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>
#include <iostream>
#include <stdio.h>

class PresidentialPardonForm: public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const& cpy );
	~PresidentialPardonForm( void );

	PresidentialPardonForm&	operator=( PresidentialPardonForm const& src );

	std::string	getTarget( void ) const;

	void	execute ( Bureaucrat const& executor ) const;

	class FormNotOpenException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
