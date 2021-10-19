/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:28:24 by louielouie        #+#    #+#             */
/*   Updated: 2021/10/19 13:31:37 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

class Karen
{
public:
	Karen();
	~Karen();
	void	complain( std::string level );
	
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif