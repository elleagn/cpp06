/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:15:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/16 08:29:43 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {

    public:

        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        virtual ~ScalarConverter() = 0;

        ScalarConverter& operator=(const ScalarConverter& src);

        static void convert(std::string scalar);

};

#endif
