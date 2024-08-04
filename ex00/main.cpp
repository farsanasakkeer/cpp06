/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:00:44 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/08/04 15:38:06 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << RED << "Error\nThe program should have only 1 argument.\nUsage: ./scalar_converter <value>" << RESET << std::endl;
		return 1;
	}

	if (av[1][0] == '\0')
	{
		std::cout << RED << "Error\nThe arguments should not be empty" << RESET << std::endl;
		return 1;
	}

    std::string str(av[1]);  // argument into a std::string object named str.
	ScalarConverter::convert(str);
}