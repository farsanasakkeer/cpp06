/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:08:28 by farsana           #+#    #+#             */
/*   Updated: 2024/07/31 13:29:21 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cfloat>
#include <stdlib.h>
#include <limits>
#include <cstdlib> // for atoll
#include <cctype>  // for isdigit
#include <string>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define PURPLE			"\033[35m"
# define CYAN           "\033[36m"

class ScalarConverter
{
	public:
		static void convert(std::string str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter overload);	

};

bool validate_string(std::string str);
		
#endif