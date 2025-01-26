/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winniexd <winniexd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:58:00 by winniexd          #+#    #+#             */
/*   Updated: 2025/01/26 12:33:12 by winniexd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

void identify(Base *ptr) {
    if (dynamic_cast<A *>(ptr))
        std::cout << "Pointer: Object is of type A" << std::endl;
    if (dynamic_cast<B *>(ptr))
        std::cout << "Pointer: Object is of type B" << std::endl;
    if (dynamic_cast<C *>(ptr))
        std::cout << "Pointer: Object is of type C" << std::endl;
}

void identify(Base &ptr) {
    try {
        A& a = dynamic_cast<A&>(ptr);
        (void)a;
        std::cout << "Reference: Object is of type A" << std::endl;
    }
    catch (std::exception&) {
        try {
            B& b = dynamic_cast<B&>(ptr);
            (void)b;
            std::cout << "Reference: Object is of type B" << std::endl;
        }
        catch (std::exception&) {
            try {
                C& c = dynamic_cast<C&>(ptr);
                (void)c;
                std::cout << "Reference: Object is of type C" << std::endl;
            }
            catch (std::exception&) {
                std::cout << "Reference: Object is of unknown type" << std::endl;
            }
        }
    }
}

Base *generate() {
    std::srand(std::time(NULL));
    Base *ptr;
    
    int rand = std::rand();
    
    switch (rand % 3) {
        case 0:
            ptr = new A;
            std::cout << "A" << std::endl;
            break;
        case 1:
            ptr = new B;
            std::cout << "B" << std::endl;
            break;
        case 2:
            ptr = new C;
            std::cout << "C" << std::endl;
            break;
    }
    
    return ptr;
}

int main() {
    Base *ptr;
    
    ptr = generate();
    identify(ptr);
    identify(*ptr);
}