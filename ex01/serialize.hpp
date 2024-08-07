/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:16:01 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/08/05 08:17:07 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h> 

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define CYAN           "\033[36m"

struct Data 
{
	int id;
	std::string name;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &copy);
		~Serializer();

		Serializer &operator=(const Serializer &overload);

		public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);

};

#endif