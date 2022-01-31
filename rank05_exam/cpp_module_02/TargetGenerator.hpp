#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <list>

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const & src);
		TargetGenerator &	operator=(TargetGenerator const & rhs);

		std::list<ATarget *> targets;
	
	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget * target);
		void		forgetTargetType(std::string const & name);
		ATarget *	createTarget(std::string const & name);
};


#endif
