
#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;

class Warlock {
	private:
		std::string name;
		std::string title;
		std::map <std::string, ASpell *> spellBook;
		Warlock &operator=(const Warlock &rhs);
		Warlock(const Warlock& obj);
		Warlock();
	public:
		std::string const& getName() const;
		std::string const& getTitle() const;
		void setTitle(const std::string &title);
		Warlock(std::string name, std::string title);
		~Warlock();
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spell);
		void launchSpell(std::string spell, const ATarget& target);
};
