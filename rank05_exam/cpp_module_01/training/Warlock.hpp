#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class ASpell;
class ATarget;

class Warlock {

private:
    std::string _name;
    std::string _title;
    Warlock( void );
    Warlock( const Warlock& cpy);
    Warlock operator=( const Warlock& src);
    std::vector<ASpell*>    spells;

public:
    Warlock( std::string const name, std::string const title );
    virtual ~Warlock( void );

   std::string const& getName( void ) const;
   std::string const& getTitle( void ) const;

   void setTitle( std::string const& title);

   void introduce( void ) const;

    void learnSpell( ASpell* spell);
    void forgetSpell( std::string spellName );
    void launchSpell( std::string spellName, ATarget& target );

};

#endif