
#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title): name(name), title(title) {
	std::cout << this->name << ": this looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

std::string const& Warlock::getName() const {
	return name;
}

std::string const& Warlock::getTitle() const {
	return title;
}

void Warlock::setTitle(std::string const &title) {
	this->title = title;
}
