/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:15:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/17 22:07:36 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define INVALID 4

class ScalarConverter {

    public:

        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        virtual ~ScalarConverter() = 0;

        ScalarConverter& operator=(const ScalarConverter& src);

        static void convert(std::string scalar);

};

#endif
