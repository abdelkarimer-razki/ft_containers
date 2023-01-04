/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:52 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 13:58:06 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MAP_HPP
#define		MAP_HPP
#include	"./includes.hpp"
#include	"./redBlackTree.hpp"

template <typename K, typename V, class rbt=redBlackTree<K, V> >
class	map
{
	private:
		rbt	redBlack;
	public:
		map()
		{
			std::cout << "hey\n";
		};
		map(std::pair<K, V> data){};
		~map(){};
		V	&operator=(V const &value);	
		//modifiers
		void	insert(std::pair<K, V> data)
		{
			this->redBlack.insert(data.first, data.second);
		}
};

#endif