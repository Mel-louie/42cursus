/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:12:44 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/28 15:44:14 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSBRAIN_HPP
# define CLASSBRAIN_HPP

# include <iostream>
# include <string>

class Brain {

public:
	Brain();
	Brain( Brain const& cpy );
	Brain( std::string const& ideas );
	virtual ~Brain();

	Brain&	operator=( Brain const& src );

	//setters
	void	setIdeas( std::string const& ideas);

	//display ideas
	void	displayIdeas( void );
	
private:
	std::string	_ideas[100];
};

#endif