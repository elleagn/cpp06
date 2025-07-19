/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:22:03 by gozon             #+#    #+#             */
/*   Updated: 2025/07/19 19:32:21 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& src) {

    (void)src;

}

/* ************************************************************************** */

/* ************************** OPERATORS ************************************* */

Serializer& Serializer::operator=(const Serializer& src) {

    (void)src;
    return (*this);

}

/* ************************************************************************** */

/* ********************* METHODS ****************************************** */

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}

/* ************************************************************************** */
