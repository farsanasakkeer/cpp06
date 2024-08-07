/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farsana <farsana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:18:54 by fvaliyak          #+#    #+#             */
/*   Updated: 2024/08/05 08:26:55 by farsana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

Serializer::Serializer(){}
Serializer::Serializer(Serializer &copy){
	(void)copy;
}
Serializer::~Serializer(){}

Serializer &Serializer::operator=(const Serializer &overload)
{
	(void)overload;
	return(*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}