/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:30:37 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 09:48:56 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(int ac, char** av) {

    if (ac != 2) {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }

    Data* data = new Data(av[1]);
    uintptr_t ptr = Serializer::serialize(data);
    Data* dataDeserialized = Serializer::deserialize(ptr);

    std::cout << "ptr original: " << data << std::endl;
    std::cout << "ptr serialized: " << std::hex <<"0x" << ptr << std::endl;
    std::cout << "data original: " << data->getString() << std::endl;
    std::cout << "data deserialized: " << dataDeserialized->getString() << std::endl;

    delete data;

    return (0);
}
