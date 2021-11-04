/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louielouie <louielouie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:46:21 by louielouie        #+#    #+#             */
/*   Updated: 2021/11/04 11:04:49 by louielouie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

class	Basic
{
private:
	int	_nb;
public:
	Basic( int nb ) : _nb( nb ) {}

	bool operator>( Basic const &rhs) const {
		return (this->_nb > rhs._nb);
	}
	bool operator<( Basic const &rhs ) const {
		return (this->_nb < rhs._nb);
	}

//getter
	int getNb(void) const { return _nb; }
};

int	main( void )
{
	std::cout << "<---- Test with two int ---->" << std::endl;
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;
	std::cout << "[swap]" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "[min]" << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "[max]" << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<---- Test with two string ---->" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << std::endl;
	std::cout << "[swap]" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "[min]" << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "[max]" << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<---- Test with two long ---->" << std::endl;
	long	longA = 445662186347;
	long	longB = 854983446278;

	std::cout << "longA = " << longA << ", longB = " << longB << std::endl;
	std::cout << std::endl;
	std::cout << "[swap]" << std::endl;
	::swap(longA, longB);
	std::cout << "longA = " << longA << ", longB = " << longB << std::endl;
	std::cout << "[min]" << std::endl;
	std::cout << "min( longA, longB ) = " << ::min( longA, longB ) << std::endl;
	std::cout << "[max]" << std::endl;
	std::cout << "max( longA, longB ) = " << ::max( longA, longB ) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<---- Test with two pointer ---->" << std::endl;
	int		*ptrA = &a;
	int		*ptrB = &b;

	std::cout << "*ptrA = " << *ptrA << ", *ptrB = " << *ptrB << std::endl;
	std::cout << std::endl;
	std::cout << "[swap]" << std::endl;
	::swap(*ptrA, *ptrB);
	std::cout << "*ptrA = " << *ptrA << ", *ptrB = " << *ptrB << std::endl;
	std::cout << "[min]" << std::endl;
	std::cout << "min( *ptrA, *ptrB ) = " << ::min( *ptrA, *ptrB ) << std::endl;
	std::cout << "[max]" << std::endl;
	std::cout << "max( *ptrA, *ptrB ) = " << ::max( *ptrA, *ptrB ) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<---- Test with an int and a double ---->" << std::endl;
	int e = 2;
	double f = 3.8;

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << std::endl;
	std::cout << "[can't swap]" << std::endl;
	//compilation error: candidate template ignored: deduced conflicting types for parameter 'T' ('int' vs. 'double')
	// ::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "[min] we should cast the int e in a double" << std::endl;
	std::cout << "min<double>( e, f ) = " << ::min<double>( e, f ) << std::endl;
	std::cout << "[max] we should cast the int e in a double" << std::endl;
	std::cout << "max<double>( e, f ) = " << ::max<double>( e, f ) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "<---- Test with an int and a class ---->" << std::endl;
	Basic	classA(1);
	Basic	classB(2);

	std::cout << "classA = " << classA.getNb() << ", classB = " << classB.getNb() << std::endl;
	std::cout << std::endl;
	std::cout << "[swap]" << std::endl;
	::swap( classA, classB );
	std::cout << "classA = " << classA.getNb() << ", classB = " << classB.getNb() << std::endl;
	std::cout << "[min]" << std::endl;
	std::cout << "min( classA, classB ) = " << ::min( classA, classB ).getNb() << std::endl;
	std::cout << "[max]" << std::endl;
	std::cout << "max( classA, classB ) = " << ::max( classA, classB ).getNb() << std::endl;
	std::cout << std::endl;

	return (0);
}
