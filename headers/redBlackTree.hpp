/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:25 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 23:22:00 by aer-razk         ###   ########.fr       */
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
		redBlackTree	*parent;//using parent pointer so we can recheck
		redBlackTree	*left;
		redBlackTree	*root;
		redBlackTree	*right;
	public:
		redBlackTree():key(), value(), right(nullptr), left(nullptr), parent(NULL), red(true){};
		redBlackTree(K key, V value, bool red, redBlackTree *parent):key(key), value(value), parent(parent), right(NULL), left(NULL), red(red) {
			if (parent != NULL)
				root = parent->root;
		};
		//this function is used to insert data as BST for now
		void	insert(K key, V value)
		{
			redBlackTree	*tmp = root;
			if (!tmp->key)//initialising the rootNode
			{
				root = new redBlackTree(key, value, false, NULL);
				return ;
			}
			while (tmp)//looping on the current node
			{
				if (key >= tmp->key)//insertion in the right nodes
				{
					if (!tmp->right)
					{
						tmp->right = new redBlackTree(key, value, true, tmp);
						std::cout << "right insertion\n";
						rotateAndRecolor(tmp->right);
						break;
					}
					tmp = tmp->right;
				}
				else//insertion in the left nodes
				{
					if (!tmp->left)
					{
						tmp->left = new redBlackTree(key, value, true, tmp);
						std::cout << "left insertion\n";
						rotateAndRecolor(tmp->left);
						break;
					}
					tmp = tmp->left;
				}
			}
		}
		//this function to recheck
		void	rotateAndRecolor(redBlackTree *node)
		{
			redBlackTree *parent = node->parent;
			if (node != root && parent->red)
			{
				redBlackTree *grandParent = parent->parent;
				redBlackTree *uncle = (parent == grandParent->left) ? grandParent->right : grandParent->left;
				if (uncle && uncle->red)
				{
					std::cout << "here\n";
					changeColor(parent);
					changeColor(uncle);	
					changeColor(grandParent);
					rotateAndRecolor(grandParent);
				}
				else if (parent == grandParent->left)
				{
					if (node != grandParent->left)
						rotateLeft(parent);
					changeColor(parent);
					changeColor(grandParent); 
					rotateRight(grandParent);
					rotateAndRecolor((node == grandParent->left) ? parent : grandParent);
				}
				else if (parent != grandParent->left)
				{
					if (node == grandParent->left)
						rotateRight(parent);
					changeColor(parent);
					changeColor(grandParent);
					rotateLeft(grandParent);
					rotateAndRecolor((node == grandParent->left) ? grandParent : parent);
				}
			}
		}
		
		void	rotateLeft(redBlackTree *node)
		{
			redBlackTree *rightNode = node->right;
			node->right = rightNode->left;
			if (node->right)
				node->right->parent = node;
			rightNode->left = node;
			rightNode->parent = node->parent;
			if (!node->parent)
				root = rightNode;
			else if (node->parent->right == node)
				node->parent->right = rightNode;
			else
				node->parent->left = rightNode;
			node->parent = rightNode;
		}

		void	rotateRight(redBlackTree *node)
		{
			redBlackTree *leftNode = node->left;
			node->left = leftNode->right;
			if (node->left)
				node->left->parent = node;
			leftNode->right = node;
			leftNode->parent = node->parent;
			if (!node->parent)
				root = leftNode;
			else if (node->parent->left == node)
				node->parent->left = leftNode;
			else
				node->parent->right = leftNode;
			node->parent = leftNode;
		}
		//this function just to test the insertion
		void	printFirstNode()
		{
			std::cout << "root:" << this->root->key << "| red?:" << this->root->red << std::endl;
			std::cout << "root:" << this->root->right->key << "| red?:" << this->root->right->red << std::endl;
			/*std::cout << "left:" << this->left->key << "| red?:" << this->left->red  << std::endl;
			std::cout << "right:" << this->right->key << "| red?:" << this->right->red  << std::endl;
			std::cout << "right-left:" << this->right->left->key << "| red?:" << this->right->left->red  << std::endl;*/
		}
		//this function to change the color of a node;
		void	changeColor(redBlackTree *node)
		{
			node->red? node->red = false : node->red = true;
		}
};

#endif
