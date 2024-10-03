#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects) {

}

ASpell::~ASpell() {

}

ASpell& ASpell::operator=(ASpell const &rhs) {
    this->name = rhs.name;
    this->effects = rhs.effects;
    return *this;
}

ASpell::ASpell(const ASpell &obj) {
    *this = obj;
}

std::string ASpell::getName() const {
    return this->name;
}

std::string ASpell::getEffects() const {
    return this->effects;
}

void ASpell::launch(const ATarget& target) const {
    target.getHitBySpell(*this);
}