#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <list>
#include "ASpell.hpp"

class	SpellBook
{
	private:
		SpellBook(SpellBook const & src);
		SpellBook &	operator=(SpellBook const & rhs);

		std::list<ASpell *> spells;
	
	public:
		SpellBook();
		~SpellBook();

		void		learnSpell(ASpell * spell);
		void		forgetSpell(std::string const & spellname);
		ASpell *	createSpell(std::string const & spellname);
};


#endif
