
#include <iostream>

class Warlock {
	private:
		std::string name;
		std::string title;
		Warlock &operator=(const Warlock &rhs);
		Warlock(Warlock& obj);
	public:
		std::string const& getName() const;
		std::string const& getTitle() const;
		void setTitle(const std::string &title);
		Warlock(std::string name, std::string title);
		~Warlock();
		void introduce() const;
};
