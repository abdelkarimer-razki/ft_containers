/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:52 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 09:45:05 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MAP_HPP
#define		MAP_HPP
#include	"./includes.hpp"
#include	"./redBlackTree.hpp"

template <typename K, typename V>
class	map: public	redBlackTree<map, V>
{
	private:
		K key;
	public:
		map();
		~map();
		V	&operator=(V const &value);	
		//modifiers
};

#endif