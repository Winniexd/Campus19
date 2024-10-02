#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
    private:
        std::string type;
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget& operator=(const ATarget& rhs);
        ATarget(const ATarget& obj);
        std::string getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(const ASpell& spell) const;
};