/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:23:30 by gozon             #+#    #+#             */
/*   Updated: 2025/07/19 19:32:50 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "stdint.h"

class Data;

class Serializer {

    public:

        Serializer();
        Serializer(const Serializer& src);
        virtual ~Serializer() = 0;

        Serializer& operator=(const Serializer& src);

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);

};

#endif
