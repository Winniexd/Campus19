#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
    protected:
        std::string name;
        std::string effects;
    public:
        std::string getName() const;
        std::string getEffects() const;
        virtual ASpell* clone() const = 0;
        ASpell& operator=(const ASpell& rhs);
        ASpell(const ASpell& obj);
        ASpell(std::string name, std::string effects);
        virtual ~ASpell();
        void launch(const ATarget& target) const;
};