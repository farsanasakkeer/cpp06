/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:22:19 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/08/05 08:35:01 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "serialize.hpp"

int main()
{
    Data myData = {42, "fars"};
	std::cout << GREEN << "Data:-\n   Id: " << myData.id << "  Name: " << myData.name << RESET  << std::endl;
	std::cout << GREEN << "   Data Address:  " << &myData << RESET << std::endl;

	std::cout << CYAN << "\nSerializing Data " << RESET << std::endl;
    std::cout << CYAN << "---------------- " << RESET << std::endl;
	uintptr_t serializedPtr = Serializer::serialize(&myData);
	std::cout << GREEN "Data serialized to uintptr_t: " << serializedPtr << RESET << std::endl;

	
	std::cout << CYAN << "\nDeserializing Data " << RESET << std::endl;
    std::cout << CYAN << "------------------ " << RESET << std::endl;
	Data *deserializedPtr = Serializer::deserialize(serializedPtr);
	std::cout << GREEN << "*Deserialized Data:-\n   Id: " << myData.id << "  Name: " << myData.name << RESET  << std::endl;
	std::cout << GREEN << "    Deserialized Data Address: " << deserializedPtr << RESET << std::endl;
	
	if (&myData == deserializedPtr)
		std::cout << YELLOW << "\nSerialization and Deserialization successful.\n" << RESET << std::endl;
	else
		std::cout << RED << "\nSerialization and Deserialization Failed.\n" << RESET << std::endl;
}