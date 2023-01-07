/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:52 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/07 10:14:04 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MAP_HPP
#define		MAP_HPP
#include	"./includes.hpp"
#include	"./redBlackTree.hpp"
namespace ft
{
	template <typename K, typename V, class rbt = redBlackTree<K, V> >
	class	map
	{
		private:
			rbt	redBlack;
		public:
			map(){};
			map(std::pair<K, V> data){};
			~map(){};
			V	&operator=(V const &value);	
			//modifiers
			void	insert(std::pair<K, V> data)
			{
				this->redBlack.insertNode(data.first, data.second);
			}
			void	getFirstNode()
			{
				this->redBlack.printDebug();
			}
			V	at(K key)
			{
				return this->redBlack.findNode(key);
			}

			void	erase(K key)
			{
				this->redBlack.deleteNode(key);
			}
	};
}

#endif