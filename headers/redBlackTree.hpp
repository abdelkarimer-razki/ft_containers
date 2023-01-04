/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:25 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 19:59:28 by aer-razk         ###   ########.fr       */
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
		redBlackTree	*parent;
		redBlackTree	*left;
		redBlackTree	*right;
	public:
		redBlackTree():key(), value(), right(nullptr), left(nullptr), parent(NULL), red(true) {};
		redBlackTree(K key, V value, bool red, redBlackTree *parent):key(key), value(value), parent(parent), right(NULL), left(NULL), red(red) {};
		//this function is used to insert data as BST for now
		void	insert(K key, V value)
		{
			redBlackTree	*tmp = this;
			if (!tmp->key)//initialising the rootNode
			{
				this->key = key;
				this->value = value;
				this->red = false;
				this->parent = NULL;
				this->right = NULL;
				this->left = NULL;
				return ;
			}
			while (tmp)//looping on the current node
			{
				if (key >= tmp->key)//insertion in the right nodes
				{
					if (!tmp->right)
					{
						tmp->right = new redBlackTree(key, value, true, this);
						break;
					}
					/*else
					{
						if (((key >= tmp->right->key && !tmp->right->right) || (key < tmp->right->key && !tmp->right->left)) && tmp->right->red)
						{
							//if parent of new node is red and the uncle is red
							if (tmp->left && tmp->left->red)
							{
								changeColor(tmp->left);
								changeColor(tmp->right);
								if (tmp != this)//if the grandParentNode isn't the root
									changeColor(tmp);
							}
						}
					}*/
					tmp = tmp->right;
				}
				else//insertion in the left nodes
				{
					if (!tmp->left)
					{
						tmp->parent = this;
						tmp->left = new redBlackTree(key, value, true, this);
						break;
					}
					/*else
					{
						if (((key >= tmp->left->key && !tmp->left->right) || (key < tmp->left->key && !tmp->left->left)) && tmp->left->red)
						{
							//if parent of new node is red and the uncle is red
							if (tmp->right && tmp->right->red)
							{
								changeColor(tmp->left);
								changeColor(tmp->right);
								if (tmp != this)//if the grandParentNode isn't the root
									changeColor(tmp);
							}
						}
					}*/
					tmp = tmp->left;
				}
			}
		}

		//this function to recheck
		void	rechecking()
		{
			
		}
		//this function just to test the insertion
		void	printFirstNode()
		{
			std::cout << "root:" << this->key << "| red?:" << this->red << std::endl;
			std::cout << "left:" << this->left->key << "| red?:" << this->left->red  << std::endl;
			std::cout << "right:" << this->right->key << "| red?:" << this->right->red  << std::endl;
			std::cout << "right-left:" << this->right->left->key << "| red?:" << this->right->left->red  << std::endl;
		}
		//this function to change the color of a node;
		void	changeColor(redBlackTree *node)
		{
			node->red? node->red = false : node->red = true;
		}
};

#endif
