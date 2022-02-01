#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget( void ) {}

ATarget::ATarget( const ATarget& cpy): _type(cpy.getType()) {}

ATarget::ATarget( std::string type ): _type(type) {}

ATarget::~ATarget( void ) {}


ATarget&        ATarget::operator=( ATarget const & src )
{
    this->_type = src._type;
    return (*this);
}

std::string const &ATarget::getType( void ) const
{
    return (this->_type);
}

void    ATarget::getHitBySpell( const ASpell &spell ) const
{
    std::cout << this->getType() << " has been " << spell.getEffects() << std::endl;
}
