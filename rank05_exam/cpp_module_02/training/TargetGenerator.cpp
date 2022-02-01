#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(): targets()
{}

TargetGenerator::~TargetGenerator()
{
	for (std::list<ATarget *>::iterator it = (this->targets).begin(); it != (this->targets).end(); it++)
		delete *it;
	(this->targets).clear();
}

void		TargetGenerator::learnTargetType(ATarget * target)
{
	for (std::list<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); it++)
	{
		if ((*it)->getType() == target->getType())
			return ;
	}
	this->targets.push_back(target->clone());
}

void		TargetGenerator::forgetTargetType(std::string const & name)
{
	for (std::list<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); it++)
	{
		if ((*it)->getType() == name)
		{
			delete *it;
			this->targets.erase(it);
			return ;
		}
	}
}

ATarget *	TargetGenerator::createTarget(std::string const & name)
{
	for (std::list<ATarget *>::iterator it = this->targets.begin(); it != this->targets.end(); it++)
	{
		if ((*it)->getType() == name)
			return (*it);
	}
	return (0);
}
