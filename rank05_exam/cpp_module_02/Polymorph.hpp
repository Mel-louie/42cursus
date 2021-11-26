#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph: public ASpell
{
public:
    Polymorph( void );
    virtual ~Polymorph( void );

    ASpell*  clone( void ) const ;
};

#endif