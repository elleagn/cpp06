/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:51:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 23:18:37 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int getRealType(std::string scalar);

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {

    (void)src;

}

/* ************************************************************************** */

/* ************************** OPERATORS ************************************* */

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {

    (void)src;
    return (*this);

}

/* ************************************************************************** */

/* ********************************** UTILS ********************************* */


void castFromChar(std::string scalar) {

    char c;
    int i;
    float f;
    double d;

    c = scalar[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;

}

void castFromInt(std::string scalar) {

    char c;
    int i;
    float f;
    double d;

    i = atoi(scalar.c_str());

    // Checks for char because it is a downcast and static cast does not perform checks

    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else {
        c = static_cast<char>(i);
        if (isprint(c))
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }

    // Upcast so no checks are needed
    f = static_cast<float>(i);
    d = static_cast<double>(i);

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << (i < 100000 && i > -1000000 ? ".0" : "") << "f" << std::endl;
    std::cout << "double: " << d << (i < 100000 && i > -1000000 ? ".0" : "") << std::endl;

}

void castFromFloat(std::string scalar) {

    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;

    f = strtof(scalar.c_str(), NULL);

    bool overflow = false;
    if (f > -2147483648.0f && f < 2147483647.0f)
        i = static_cast<int>(f);
    else
        overflow = true;

    // Checks for char because it is a downcast and static cast does not perform checks

    if (i != f || i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else {
        c = static_cast<char>(f);
        if (isprint(c))
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }

    // Upcast so no checks are needed
    d = static_cast<double>(f);

    std::cout << "int: ";
    if (f != f)
        std::cout << "impossible";
    else if (overflow)
        std::cout << "overflow";
    else
        std::cout << i;
    std::cout << std::endl;
    std::cout << "float: " << f << (i == f && i < 100000 && i > -1000000 ? ".0" : "") << "f" << std::endl;
    std::cout << "double: " << d << (i == f && i < 100000 && i > -1000000 ? ".0" : "") << std::endl;

}

void castFromDouble(std::string scalar) {
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;

    d = strtod(scalar.c_str(), NULL);

    bool overflow = false;
    if (d > -2147483648.0 && d < 2147483647.0)
        i = static_cast<int>(d);
    else
        overflow = true;

    // Checks for char because it is a downcast and static cast does not perform checks

    if (i != d || i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else {
        c = static_cast<char>(d);
        if (isprint(c))
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }

    // Upcast so no checks are needed
    f = static_cast<double>(d);

    std::cout << "int: ";
    if (d != d)
        std::cout << "impossible";
    else if (overflow)
        std::cout << "overflow";
    else
        std::cout << i;
    std::cout << std::endl;
    std::cout << "float: " << f << (i == f && i < 100000 && i > -1000000 ? ".0" : "") << "f" << std::endl;
    std::cout << "double: " << d << (i == f && i < 100000 && i > -1000000 ? ".0" : "") << std::endl;
}

void castInvalid(std::string scalar) {

    (void)scalar;
    std::cout <<    "char: impossible\n"
                    "int: impossible\n"
                    "float: nanf\n"
                    "double: nan" << std::endl;

}

/* ************************************************************************** */

/* ********************************** METHODS ******************************* */

void ScalarConverter::convert(std::string scalar) {

    void (*cast[5])(std::string scalar) = {castFromChar, castFromInt,
        castFromFloat, castFromDouble, castInvalid};

    cast[getRealType(scalar)](scalar);
}

/* ************************************************************************** */
