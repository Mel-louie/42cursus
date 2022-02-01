
#include "Warlock.hpp"
#include <string>
#include <iostream>
#include <vector>

Warlock::Warlock( std::string const name, std::string const title): _name( name ), _title( title )
{
    std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock( void )
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
}

std::string const& Warlock::getName( void ) const
{
    return ( this->_name );
}

std::string const& Warlock::getTitle( void ) const
{
    return ( this->_title );
}

void    Warlock::setTitle( std::string const& title )
{
    this->_title = title;
}

void    Warlock::introduce( void ) const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << " !" << std::endl;
}

void Warlock::learnSpell( ASpell* spell)
{
    if (spell)
    {
        for (std::vector<ASpell*>::const_iterator it = (this->spells).begin() ; it != (this->spells).end(); it++)
            if ((*it)->getName() == spell->getName())
                return ;
    }
    this->spells.push_back(spell);
}
    
void Warlock::forgetSpell( std::string spellName )
{
    for (std::vector<ASpell*>::const_iterator it = (this->spells).begin() ; it != (this->spells). end() ; it++)
        {
            if ((*it)->getName() == spellName)
            {
                delete (*it);
                (this->spells).erase(it);
                return ;
            }
        }
}
    
void Warlock::launchSpell( std::string spellName, ATarget& target )
{
    for (std::vector<ASpell*>::const_iterator it = (this->spells).begin() ; it != (this->spells).end() ; it++)
    {
        if ((*it)->getName() == spellName)
            {target.getHitBySpell(*(*it));
            return;}
    }
}
