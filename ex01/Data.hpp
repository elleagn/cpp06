/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:32:28 by gozon             #+#    #+#             */
/*   Updated: 2025/07/20 09:23:40 by gozon            ###   ########.fr       */
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
        virtual ~Data();

        Data& operator=(const Data& src);
        const std::string& getString() const;


};

#endif
