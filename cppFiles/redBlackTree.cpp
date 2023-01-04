/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:52:41 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 13:46:13 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/redBlackTree.hpp"

template <typename K, typename V>
redBlackTree<K, V>::redBlackTree(K key, V value, bool red):key(key), value(value), right(nullptr), left(nullptr), red(red)
{
}

template <typename K, typename V>
redBlackTree<K, V>::redBlackTree():key(0), value(0), right(nullptr), left(nullptr), red(true), size(0), root(nullptr) 
{
}
