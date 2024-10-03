#include "ASpell.hpp"
#include <iostream>
#include <map>

class SpellBook {
	private:
		SpellBook& operator=(SpellBook const &rhs);
		SpellBook(SpellBook& const obj);
		std::map <std::string, ASpell*> spellBook;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* spell);
		void forgetSpell(ASpell* spell);
		ASpell* createSpell(std::string const &spell);
};