#include "ATarget.hpp"

ATarget::ATarget(): type()
{}

ATarget::ATarget(std::string const & itype): type(itype)
{}

ATarget::ATarget(ATarget const & src): type(src.type)
{}

ATarget::~ATarget()
{}

ATarget &			ATarget::operator=(ATarget const & rhs)
{
	this->type = rhs.type;
	return (*this);
}

void				ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}

std::string const &		ATarget::getType(void) const
{ return (this->type); }
