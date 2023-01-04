/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:58 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/03 13:47:42 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vector.hpp"

template <typename T>
T	&vector<T>::iterator::operator*(T &data_ptr)
{
	this->data_ptr *= data_ptr;
	return this;
}

template <typename T>
T	&vector<T>::iterator::operator++()
{
	this->data_ptr++;
	return this;	
}