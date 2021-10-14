/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:29:43 by mdesfont          #+#    #+#             */
/*   Updated: 2021/10/14 13:18:21 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Sample
{
public:
	Sample();
	~Sample();

	//member functions
	void	bliblou( void );
	void	setVal(int val);
//si la fonction est en "read only", ne pas hésiter à toujours la mettre en const
	int	getVal( void ) const;	

private:
	//member attributes
	int _val;
};
