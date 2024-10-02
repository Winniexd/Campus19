#include "ATarget.hpp"

ATarget::ATarget(std::string type): type(type) {

}

ATarget& ATarget::operator=(const ATarget& rhs) {
    this->type = rhs.type;
    return *this;
}

ATarget::ATarget(const ATarget& obj) {
    *this = obj;
}

ATarget::~ATarget() {
    
}

std::string ATarget::getType() const {
    return this->type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}