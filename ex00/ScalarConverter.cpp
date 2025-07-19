/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:51:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/19 16:08:31 by gozon            ###   ########.fr       */
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
    bool sign = false;
    bool f = false;
    char current;

    // Handle the sign
    if (scalar[0] == '+' || scalar[0] == '-')
        sign = true;

    // Check for invalid characters inside the string
    for (size_t i = 0; i < scalar.length() - sign; i++) {

        if (f)
            return (INVALID);
        current =  scalar[i + sign];
        if (current == '.' && !dot)
            dot = true;
        else if (current == 'f' && dot)
            f = true;
        else if (!isdigit(current))
            return (INVALID);

    }

    // Determine the type depending on the presence of a dot or a final f
    if (dot && f)
        return (FLOAT);
    if (dot)
        return (DOUBLE);

    // Deal with int overflow
    size_t len = scalar.length();
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
    // .f +f -f
    // Check cpp reference litterals
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
    else if (isprint(i)) {
        c = i;
        std::cout << "char: " << c << std::endl;
    }
    else
        std::cout << "char: non displayable" << std::endl;

    // Upcast so no checks are needed
    f = static_cast<float>(i);
    d = static_cast<double>(i);

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;

}

void castFromFloat(std::string scalar) {

    (void)scalar;
    std::cout << "float" << std::endl;

}

void castFromDouble(std::string scalar) {
    (void)scalar;
    std::cout << "double" << std::endl;
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
