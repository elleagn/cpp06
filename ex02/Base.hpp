/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:14:31 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 11:43:26 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
    public:
        virtual ~Base();
};

class A: public Base {
    public:
        A();
        ~A();
};

class B: public Base {
    public:
        B();
        ~B();
};

class C: public Base {
    public:
        C();
        ~C();
};

#endif
