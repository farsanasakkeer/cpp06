/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:10:12 by farsana           #+#    #+#             */
/*   Updated: 2024/07/31 13:51:21 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"

ScalarConverter::ScalarConverter(){}
		
ScalarConverter::ScalarConverter(const ScalarConverter &copy){ (void)copy; }

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter overload)
{
    (void)overload;
	return (*this);
}

void check_spcl_char(std::string str)
{
	int sign_count = 0;
	int dot_count = 0;
	int f_count = 0;

    for (size_t i = 0; i < str.length(); i++)
	{
        
		if (str[i] == '+' || str[i] == '-')
			sign_count++;

		if (str[i] == '.')
			dot_count++;

		if (str[i] == 'f' || str[i] == 'F')
			f_count++;

		if (sign_count > 1 || dot_count > 1 || f_count > 1)
		{
			std::cout << RED << "Error\nThe argument contains special charcter more than 1 times (+-.fF)" << RESET << std::endl;
			exit(1);
		}
	}
    if ((str.find('+') != str.npos && str[0] != '+') || (str.find('-') != str.npos && str[0] != '-'))
	{
		std::cout << RED << "Error\nThe sign of the argument must be at the begining." << RESET << std::endl;
		exit(1);
	}

    if ((str.find('f') != str.npos && str[str.length() - 1] != 'f') || (str.find('F') != str.npos && str[str.length() - 1] != 'F'))
	{
		std::cout << RED << "Error\nIf the argument is float the f or F character must be at the end." << RESET << std::endl;
		exit(1);
	}

	
}

bool is_num(std::string str)
{
	if ((str.find_first_not_of("0123456789") == std::string::npos)
		|| (str.find_first_not_of("-0123456789") == std::string::npos && str[0] == '-'))
		return (true);
	return (false);
}

bool is_float(std::string str)
{
	if ((str.find_first_not_of("0123456789.f") == std::string::npos)
		|| (str.find_first_not_of("-0123456789.f") == std::string::npos && str[0] == '-'))
		return (true);
	return (false);
}

bool is_double(std::string str)
{
	if ((str.find_first_not_of("0123456789.") == std::string::npos)
		|| (str.find_first_not_of("-0123456789.") == std::string::npos && str[0] == '-'))
		return (true);
	return (false);
}

bool is_char(std::string str)
{
    if (str.length() ==  1)
            return(true);
	return (false);
}

bool validate_string(std::string str)
{
    if (str == "-inff" || str == "-inf")
    {
        std::cout << RED << "Char   : Impossible" << RESET << std::endl;
        std::cout << RED << "int    : Impossible" << RESET << std::endl;
		std::cout << GREEN << "float  : " << "-inff" << RESET << std::endl;
        std::cout << GREEN << "double : " << "-inf" << RESET << std::endl;
        return(true);
    }
	else if (str == "+inff" || str == "+inf")
    {
        std::cout << RED << "Char   : Impossible" << RESET << std::endl;
        std::cout << RED << "int    : Impossible" << RESET << std::endl;
		std::cout << GREEN << "float  : " << "+inff" << std::endl;
        std::cout << GREEN << "double : " << "+inf" << RESET << std::endl;
        return(true);
    }
	else if (str == "nanf" || str == "nan")
    {
        std::cout << RED << "Char   : Impossible" << RESET << std::endl;
        std::cout << RED << "int    : Impossible" << RESET << std::endl;
		std::cout << GREEN << "float  : " << "nanf" << RESET << std::endl;
        std::cout << GREEN << "double : " << "nan" << RESET << std::endl; 
        return(true);      
    }
    
    return(false);
}

void    print_int(std::string str)
{
    long long longValue = atoll(str.c_str());

    // Check if the converted value fits into an int
    if (longValue < std::numeric_limits<int>::min() || longValue > std::numeric_limits<int>::max())
    {
        std::cout << YELLOW << "int: Impossible" << RESET << std::endl;
        return;
    }

    // Cast to int and output
    int intValue = static_cast<int>(longValue);
    std::cout << GREEN << "int: " << intValue << RESET << std::endl;
}

void ScalarConverter::convert(std::string str)
{    
    if (validate_string(str) == 1)
        return ;
    if (is_num(str) || is_double(str) || is_float(str) || is_char(str))
    {
        check_spcl_char(str);
        print_int(str);
    }
    else
        std::cout << RED << "Error input" << RESET << std::endl;
    
		
}


/*std::string::npos is a constant that holds the largest possible value of size_t type ( 18446744073709551615 on 64-bit systems ), 
which is an unsigned integer type. 
Hence, -1 corresponds to the actual value of std::string::npos.

str.find_first_not_of():Index of first unmatched character when successful or string::npos if no such character found.
return value of find_first_not_of() :The position of the first character that does not match.
If no such characters are found, the function returns string::npos.

*/