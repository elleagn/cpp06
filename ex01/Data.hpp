/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:32:28 by gozon             #+#    #+#             */
/*   Updated: 2025/07/19 19:35:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {

    private:
        std::string str;

    public:

        Data();
        Data(const Data& src);
        Data(const std::string& str);
        virtual ~Data() = 0;

        Data& operator=(const Data& src);
        const std::string& getString() const;


};

#endif
