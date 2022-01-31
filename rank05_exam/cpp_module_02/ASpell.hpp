#ifndef ASPELL_HPP
# define ASPELL_HPP

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class	ASpell
{
	private:
		std::string	name;
		std::string	effects;
	
	public:	
		ASpell();
		ASpell(std::string const & iname, std::string const & ieffects);
		ASpell(ASpell const & src);
		virtual ~ASpell();

		ASpell &		operator=(ASpell const & rhs);

		virtual ASpell *	clone(void)		const = 0;
		void			launch(ATarget const & target) const;

		std::string const &	getName(void)		const;
		std::string const &	getEffects(void)	const;
};



#endif
