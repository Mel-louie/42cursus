#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){}

void    SpellBook::learnSpell(ASpell *spell)
{
    for (std::list<ASpell *>::iterator it = (this->spells).begin() ; it != (this->spells).end() ; it++)
    {
        if ((*it)->getName() == spell->getName())
            return ;
    }
    (this->spells).push_back(spell->clone());
}

void    SpellBook::forgetSpell( std::string const & spellName)
{
    for (std::list<ASpell *>::iterator it = (this->spells).begin() ; it != (this->spells).end() ; it++)
    {
        if ((*it)->getName() == spellName)
        {
            delete *it;
            (this->spells).erase(it);
            return;
        }
    }
}

ASpell* SpellBook::createSpell(std::string const & spellName)
{
    for (std::list<ASpell*>::iterator it = (this->spells).begin() ; it != (this->spells).end() ; it++)
    {
        if ((*it)->getName() == spellName)
            return (*it);
    }
    return (0);
}
