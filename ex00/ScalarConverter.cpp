/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:51:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 22:14:04 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

int getRealType(std::string scalar) {

    // Check if the string represents a char
    if (scalar.size() == 1 && !isdigit(scalar[0]))
        return (CHAR);

    bool dot = false;
    bool e;
    bool hasDigit = false;
    bool sign = false;
    bool f = false;
    char current;
    size_t len = scalar.length();

    // Handle the sign
    if (scalar[0] == '+' || scalar[0] == '-')
        sign = true;

    // Check for invalid characters inside the string
    for (size_t i = 0; i < len - sign; i++) {

        if (f)
            return (INVALID);
        current =  scalar[i + sign];
        if (current == '.' && !dot)
            dot = true;
        else if (current == 'f' && dot && hasDigit)
            f = true;
        else if (!e && i != len - 1 && current == 'e' && (scalar[i + 1] == '+' || scalar[i + 1] == '-')) {
            i++;
            e = true;
        }
        else if (!e && i != len - 1 && isdigit(scalar[i + 1]) && current == 'e')
            e = true;
        else if (!isdigit(current))
            return (INVALID);
        else if (!hasDigit)
            hasDigit = true;

    }

    // Determine the type depending on the presence of a dot or a final f
    if (f)
        return (FLOAT);
    if (dot || e)
        return (DOUBLE);

    // Deal with int overflow
    size_t firstSignificant = scalar.find_first_not_of('0', sign);
    size_t significantDigits = len - firstSignificant;

    if (significantDigits < 10)
        return (INT);
    if (significantDigits > 10)
        return (INVALID);
    if ((!sign || scalar[0] == '+') && scalar.compare(firstSignificant, 10, "2147483647") > 0)
        return (INVALID);
    if (scalar[0] == '-' && scalar.compare(firstSignificant, 10, "2147483648") > 0)
        return (INVALID);

    return (INT);
    // To do: nan inf etc
    // Check cpp reference litterals
    // add e+ e-
}

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
    if (overflow)
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
    if (overflow)
        std::cout << "overflow";
    else
        std::cout << i;
    std::cout << std::endl;
    std::cout << "float: " << f << (i == f && i < 100000 && i > -1000000 ? ".0" : "") << "f" << std::endl;
    std::cout << "double: " << d << (i == f && i < 100000 && i > -1000000 ? ".0" : "") << std::endl;
}

void castInvalid(std::string scalar) {

    (void)scalar;
    std::cout << scalar << " is not a valid char literal" << std::endl;

}

/* ************************************************************************** */

/* ********************************** METHODS ******************************* */

void ScalarConverter::convert(std::string scalar) {

    void (*cast[5])(std::string scalar) = {castFromChar, castFromInt,
        castFromFloat, castFromDouble, castInvalid};

    cast[getRealType(scalar)](scalar);
}

/* ************************************************************************** */
