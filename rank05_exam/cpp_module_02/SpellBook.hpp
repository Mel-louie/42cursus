#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <list>

class SpellBook
{
private:
    SpellBok( const SpellBook &cpy );
    SpellBook& operator=( const SpellBook &src );

    std::list<ASpell*> spells;

public:
    SpellBook();
    virtual ~Spellbook();

    void    learnSpell(ASpell *spell);
    void    forgetSpell(std::string const & spellName);
    ASpell* createSpell(std::string const & spellName);
};

#endif