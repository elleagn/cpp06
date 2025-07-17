/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:51:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/17 22:35:33 by gozon            ###   ########.fr       */
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

    bool dot = false;
    size_t i = 0;

    // Handle the sign
    if (scalar[0] == '+' && scalar[0] == '-')
        i++;

    // Check for invalid characters inside the string
    while (i < scalar.length() - 1) {
        if (scalar[i] == '.' && !dot)
            dot = true;
        else if (!isdigit(scalar[i]))
            return (INVALID);
        i++;
    }

    // Determine the type depending on the presence of a dot or a final f
    if (scalar[i] == 'f')
        return (FLOAT);
    else if (!isdigit(scalar[i]))
        return (INVALID);
    else if (dot)
        return (DOUBLE);
    return (INT);

    // To do: nan inf etc
    // .f +f -f
}

bool castFromChar(std::string scalar) {

    char c;
    int i;
    float f;
    double d;

    // Check if the string represents a char
    if (scalar.size() != 1 || isdigit(scalar[0]))
        return (false);

    c = scalar[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;

    return (true);
}

bool castFromInt(std::string scalar) {

    char c;
    int i;
    float f;
    double d;

    // Check overflow forst to avoid atoi segfault
    if (scalar.length() > 11 || scalar > "2147483647" || scalar > "-2147483648" || scalar > "+2147483647")
        return (false);

    i = atoi(scalar.c_str());

    // Check invalid int represntation
    if (i == 0 && scalar.find_first_not_of('0') != std::string::npos)
        return (false);

    // Checks for char because it is a downcast and static cast does not perform checks
    if (isprint(i)) {
        c = i;
        std::cout << "char: " << c << std::endl;
    }
    else if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;

    // Upcast so no checks are needed
    f = static_cast<float>(i);
    d = static_cast<double>(i);

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;

    return (true);

}

bool castFromFloat(std::string scalar) {

    (void)scalar;
    return (false);

}

bool castFromDouble(std::string scalar) {
    (void)scalar;
    return (false);
}

bool castInvalid(std::string scalar) {

    (void)scalar;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;

    return (true);

}

/* ************************************************************************** */

/* ********************************** METHODS ******************************* */

void ScalarConverter::convert(std::string scalar) {

    bool (*cast[5])(std::string scalar) = {castFromChar, castFromInt,
        castFromFloat, castFromDouble, castInvalid};

    for (int i = 0; i < 5; i++) {
        if (cast[i](scalar))
            return ;
    }
}

/* ************************************************************************** */
