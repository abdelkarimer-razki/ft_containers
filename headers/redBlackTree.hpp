/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:25 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 15:12:13 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include "./includes.hpp"

template <typename K, typename V>
class	redBlackTree
{
	private:
		K				key;
		V				value;
		bool			red;
		redBlackTree	*left;
		redBlackTree	*right;
	public:
		redBlackTree():key(), value(), right(nullptr), left(nullptr), red(true) {};
		redBlackTree(K key, V value, bool red):key(key), value(value), right(NULL), left(NULL), red(red) {};
		//this function is used to insert data as BST for now
		void	insert(K key, V value)
		{
			redBlackTree	*tmp = this;
			if (!tmp->key)
			{
				this->key = key;
				this->value = value;
				this->red = false;
				this->right = NULL;
				this->left = NULL;
				return ;
			}
			while (tmp)
			{
				if (value > tmp->value)
				{
					if (!tmp->right)
					{
						tmp->right = new redBlackTree(key, value, true);
						break;
					}
					tmp = tmp->right;
				}
				else
				{
					if (!tmp->left)
					{
						tmp->left = new redBlackTree(key, value, true);
						break;
					}
					tmp = tmp->left;
				}
			}
		}
		void	printFirstNode()
		{
			std::cout << this->value << std::endl;
			std::cout << this->right->value << std::endl;
		}
		//this function to change the color of a node;
		void	changeColor()
		{
			if (red == true)
				red = false;
			else
				red = true;
		}
};

#endif
