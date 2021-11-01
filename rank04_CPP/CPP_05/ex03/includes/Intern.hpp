/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:26:27 by mdesfont          #+#    #+#             */
/*   Updated: 2021/11/01 18:00:51 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
private:
	std::string	_arrForms[3];
	AForm*	( Intern::*_ptrForms[3] )( std::string );

public:
	Intern( void );
	Intern( Intern const& cpy );
	~Intern( void );

	Intern&	operator=( Intern const& src );
	AForm*	makeForm( std::string form, std::string target );
	AForm*	makeShrubberyForm( std::string target );
	AForm*	makeRobotomyForm( std::string target );
	AForm*	makePresisentialForm( std::string target );
};

#endif
