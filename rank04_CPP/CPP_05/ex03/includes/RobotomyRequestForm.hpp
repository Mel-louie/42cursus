/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:48:47 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/30 19:26:35 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>
#include <iostream>
#include <stdio.h>

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const& cpy );
	~RobotomyRequestForm( void );

	RobotomyRequestForm&	operator=( RobotomyRequestForm const& src );

	std::string	getTarget( void ) const;

	void	execute ( Bureaucrat const& executor ) const;
};

#endif
