
#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <string> 
#include "ASpell.hpp"
class ASpell;


class ATarget
{
private:
    std::string  _type;

public:
    ATarget( void );
    ATarget( const ATarget &cpy);
    ATarget( std::string type );
    virtual ~ATarget( void );

    ATarget&    operator=(  ATarget const &src );

    std::string const &getType( void ) const;

    virtual ATarget*    clone( void ) const = 0;

    void    getHitBySpell( const ASpell &spell) const;
};

#endif
