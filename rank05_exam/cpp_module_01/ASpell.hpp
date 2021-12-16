#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>

class ASpell
{
	private:
		std::string	name;
		std::string effects;
	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &cpy);
		virtual ~ASpell();
		ASpell	operator=(const ASpell &src);

		std::string	getName() const ;
		std::string	getEffects() const;

		virtual ASpell*	clone() const = 0;
};

#endif