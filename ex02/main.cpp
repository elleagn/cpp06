/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:32:56 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 19:57:24 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base* generate(void) {

    std::srand(std::time(NULL));
    int const outcome = std::rand() % 3;

    if (outcome == 0)
        return (new A);
    if (outcome == 1)
        return (new B);
    if (outcome == 2)
        return (new C);
    return (NULL);
}

void identify(Base* p) {
    if (!p)
        return ;

    if (dynamic_cast<A*>(p)) {
        std::cout << "p points to class A" << std::endl;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "p points to class B" << std::endl;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "p points to class C" << std::endl;
    }
}

void identify(Base& p) {

    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "p refers to class A" << std::endl;
    }
    catch(...) {

    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "p refers to class B" << std::endl;
    }
    catch(...) {

    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "p refers to class C" << std::endl;
    }
    catch(...) {

    }
}

int main() {
    Base* b = generate();
    identify(b);
    identify(*b);
    delete b;
}
