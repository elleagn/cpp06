/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getRealType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:21:32 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 23:13:38 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int checkFloating(std::string scalar, bool sign, size_t len) {

    bool dot = false;
    bool e = false;
    bool hasDigit = false;
    bool f = false;
    char current;

    for (size_t i = 0; i < len - sign; i++) {

        if (f)
            return (INVALID);
        current =  scalar[i + sign];
        if (current == '.' && !dot && !e)
            dot = true;
        else if (current == 'f' && (dot || e) && hasDigit)
            f = true;
        else if (!e && i != len - 1 && current == 'e' && hasDigit &&
                    (scalar[i + 1] == '+' || scalar[i + 1] == '-' || isdigit(scalar[i + 1]))) {
            i = isdigit(scalar[i+1]) ? i : i + 1;
            e = true;
            hasDigit = false;
        }
        else if (!isdigit(current))
            return (INVALID);
        else if (!hasDigit)
            hasDigit = true;

    }

    if (!hasDigit)
        return (INVALID);
    if (f)
        return (FLOAT);
    if (dot || e)
        return (DOUBLE);

    return (UNDEFINED);

}

int checkInt(std::string scalar, bool sign, size_t len) {

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

}

int getRealType(std::string scalar) {

    size_t len = scalar.length();

    if (scalar == "+inff" || scalar == "-inff" || scalar == "nanf")
        return (FLOAT);
    if (scalar == "+inf" || scalar == "-inf" || scalar == "nan")
        return (DOUBLE);

    // Check if the string represents a char
    if (scalar.size() == 1 && !isdigit(scalar[0]))
        return (CHAR);


    bool sign = false;

    // Handle the sign
    if (scalar[0] == '+' || scalar[0] == '-')
        sign = true;

    int type = checkFloating(scalar, sign, len);
    if (type != UNDEFINED)
        return (type);

    return (checkInt(scalar, sign, len));
}
