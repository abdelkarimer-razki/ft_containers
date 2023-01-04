/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:52:41 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 09:57:11 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/redBlackTree.hpp"

template <class T, typename V>
redBlackTree<T, V>::redBlackTree(V value):value(value), right(nullptr), left(nullptr)
{
	if (size == 0)
		red = false;
	else
		red = true;
	size++;
}

template <class T, typename V>
void	redBlackTree<T, V>::insert()