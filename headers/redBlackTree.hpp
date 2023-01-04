/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:25 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/05 00:13:03 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include "./includes.hpp"

template <typename K, typename V>
class	redBlackTree
{
	private:
		struct Node {
			K		key;
			V		value;
			bool	red;
			Node *left, *right, *parent;

			Node(K key, V value, bool red, Node *parent) :
				key(key), value(value), red(red), left(nullptr), right(nullptr), parent(parent) {}
		};
		Node	*root;
	public:
		redBlackTree():root(NULL){};
		//this function is used to insert data as BST for now
		void	insert(K key, V value)
		{
			Node	*tmp = root;
			if (!tmp)//initialising the rootNode
			{
				root = new Node(key, value, false, NULL);
				return ;
			}
			while (tmp)//looping on the current node
			{
				if (key >= tmp->key)//insertion in the right nodes
				{
					if (!tmp->right)
					{
						tmp->right = new Node(key, value, true, tmp);
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
						tmp->left = new Node(key, value, true, tmp);
						std::cout << "left insertion\n";
						rotateAndRecolor(tmp->left);
						break;
					}
					tmp = tmp->left;
				}
			}
		}
		//this function to recheck
		void	rotateAndRecolor(Node *tmp_node)
		{
			Node *parent = tmp_node->parent;
			if (tmp_node != root && parent->red)
			{
				Node *grandParent = parent->parent;
				Node *uncle = (parent == grandParent->left) ? grandParent->right : grandParent->left;
				if (uncle && uncle->red)
				{
					changeColor(parent);
					changeColor(uncle);	
					changeColor(grandParent);
					rotateAndRecolor(grandParent);
				}
				else if (parent == grandParent->left)
				{
					if (tmp_node != parent->left)
						rotateLeft(parent);
					changeColor(parent);
					changeColor(grandParent); 
					rotateRight(grandParent);
					rotateAndRecolor((tmp_node == parent->left) ? parent : grandParent);
				}
				else if (parent != grandParent->left)
				{
					if (tmp_node == parent->left)
						rotateRight(parent);
					changeColor(parent);
					changeColor(grandParent);
					rotateLeft(grandParent);
					rotateAndRecolor((tmp_node == parent->left) ? grandParent : parent);
				}
			}
		}
		
		void	rotateLeft(Node *tmp_node)
		{
			Node *rightNode = tmp_node->right;
			tmp_node->right = rightNode->left;
			if (tmp_node->right)
				tmp_node->right->parent = tmp_node;
			rightNode->left = tmp_node;
			rightNode->parent = tmp_node->parent;
			if (!tmp_node->parent)
				root = rightNode;
			else if (tmp_node->parent->left == tmp_node)
				tmp_node->parent->left = rightNode;
			else
				tmp_node->parent->right = rightNode;
			tmp_node->parent = rightNode;
		}

		void	rotateRight(Node *tmp_node)
		{
			Node *leftNode = tmp_node->left;
			tmp_node->left = leftNode->right;
			if (tmp_node->left)
				tmp_node->left->parent = tmp_node;
			leftNode->right = tmp_node;
			leftNode->parent = tmp_node->parent;
			if (!tmp_node->parent)
				root = leftNode;
			else if (tmp_node->parent->left == tmp_node)
				tmp_node->parent->left = leftNode;
			else
				tmp_node->parent->right = leftNode;
			tmp_node->parent = leftNode;
		}
		//this function just to test the insertion
		void	printFirstNode()
		{
			std::cout << "root:" << this->root->key << "| red?:" << this->root->red << std::endl;
			//std::cout << "root:" << this->root->right->key << "| red?:" << this->root->right->red << std::endl;
		}
		//this function to change the color of a node;
		void	changeColor(Node *node)
		{
			if (node != root)
				node->red? node->red = false : node->red = true;
		}
};

#endif
