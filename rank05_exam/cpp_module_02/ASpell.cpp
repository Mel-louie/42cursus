#include "ASpell.hpp"

ASpell::ASpell(): name(), effects()
{}

ASpell::ASpell(std::string const & iname, std::string const & ieffects): name(iname), effects(ieffects)
{}

ASpell::ASpell(ASpell const & src): name(src.name), effects(src.effects)
{}

ASpell::~ASpell()
{}

ASpell &		ASpell::operator=(ASpell const & rhs)
{
	this->name = rhs.name;
	this->effects = rhs.effects;
	return (*this);
}

void			ASpell::launch(ATarget const & target) const
{ target.getHitBySpell((*this)); }

std::string const &	ASpell::getName(void) const
{ return (this->name); }

std::string const &	ASpell::getEffects(void) const
{ return (this->effects); }
