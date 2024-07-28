/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:10:12 by farsana           #+#    #+#             */
/*   Updated: 2024/07/27 00:29:19 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"

ScalarConverter::ScalarConverter(){}
		
ScalarConverter::ScalarConverter(const ScalarConverter &copy){ (void)copy; }

ScalarConverter::~ScalarConverter(){}

ScalarConverter ScalarConverter::&operator=(ScalarConverter overload)
{
    (void)overload;
	return (*this);
}

void validate_string(std::string &str)
{
    
}

static void ScalarConverter::convert(std::string &str)
{
    validate_string(str);
}