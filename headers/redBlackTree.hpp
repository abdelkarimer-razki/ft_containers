/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:07:25 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/06 14:23:55 by aer-razk         ###   ########.fr       */
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
			bool isLeftChild()
			{
				return (this == parent->left);
			}
		};
		Node	*root;
	public:
		redBlackTree():root(NULL){};
		//this function is used to insert data as BST for now
		void	insertNode(K key, V value)
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
						insertRotateAndRecolor(tmp->right);//this is the function where i rotate and recolor so i can turn this BST INTO RBT
						root->red = false;
						break;
					}
					tmp = tmp->right;
				}
				else//insertion in the left nodes
				{
					if (!tmp->left)
					{
						tmp->left = new Node(key, value, true, tmp);
						insertRotateAndRecolor(tmp->left);//this is the function where i rotate and recolor so i can turn this BST INTO RBT
						root->red = false;
						break;
					}
					tmp = tmp->left;
				}
			}
		}
		//this function to recheck
		void	insertRotateAndRecolor(Node *tmp_node)
		{
			Node *parent = tmp_node->parent;
			if (tmp_node != root && parent->red)
			{
				Node *grandParent = parent->parent;
				Node *uncle = (parent->isLeftChild()) ? grandParent->right : grandParent->left;
				if (uncle && uncle->red)
				{
					changeColor(parent);
					changeColor(uncle);
					changeColor(grandParent);
					rotateAndRecolor(grandParent);
				}
				else if (!uncle || !uncle->red)
				{
					changeColor(grandParent);
					if (!tmp_node->isLeftChild() && !parent->isLeftChild())
					{
						changeColor(parent);
						rotateLeft(grandParent);
					}
					else if (!tmp_node->isLeftChild() && parent->isLeftChild())
					{
						changeColor(tmp_node);
						rotateLeft(parent);
						rotateRight(grandParent);
					}
					else if ((tmp_node->isLeftChild() && !parent->isLeftChild()))
					{
						changeColor(tmp_node);
						rotateRight(parent);
						rotateLeft(grandParent);
					}
					else if (tmp_node->isLeftChild() && parent->isLeftChild())
					{
						changeColor(parent);
						rotateRight(grandParent);
					}
				}
			}
		}

		void printTree(Node* node, std::string indent, bool last) {
				if (node == NULL) return;

				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = node->red == true ? "RED" : "BLACK";
				std::cout << node->key << "(" << sColor << ")" << std::endl;

				printTree(node->left, indent, false);
				printTree(node->right, indent, true);
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
			else if (tmp_node->isLeftChild())
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
			else if (tmp_node->isLeftChild())
				tmp_node->parent->left = leftNode;
			else
				tmp_node->parent->right = leftNode;
			tmp_node->parent = leftNode;
		}
		//this function just to test the insertion
		void	printFirstNode()
		{
			printTree(root, "", true);
		}
		//this function to change the color of a node;
		void	changeColor(Node *node)
		{
			node->red? node->red = false : node->red = true;
		}

		V	findNode(K key)
		{
			Node	*tmp = root;
			while (tmp)
			{
				if (key > tmp->key)
				{
					if (!tmp->right)
						break ;
					tmp = tmp->right;
				}
				else if (key < tmp->key)
				{
					if (!tmp->left)
						break ;
					tmp = tmp->left;
				}
				else
					return tmp->value;
			}
			throw errors("key not found");
		}

		void	transplantNode(Node *nodeToDelete, Node *nodeToTakePlace)
		{
			if (nodeToDelete == root)
				root = nodeToTakePlace;	
			else if (nodeToDelete->isLeftChild())
				nodeToDelete->parent->left = nodeToTakePlace;
			else if (!nodeToDelete->isLeftChild())
				nodeToDelete->parent->right = nodeToTakePlace;
			if (nodeToTakePlace)
			{
				nodeToTakePlace->right = nodeToDelete->right;
				nodeToTakePlace->left = nodeToDelete->left;
				nodeToTakePlace->parent = nodeToDelete->parent;
			}
		}

		void	deleteRotateAndRecolor(Node *parentNode)
		{
			if (nodeToFixFrom && nodeToFixFrom->red)
			{

			}
			else if (!nodeToFixFrom && )
		}

		void	deleteNode(K key)
		{
			Node	*tmp = root;
			Node	*nodeToSearchFrom;
			while (tmp)
			{
				if (key > tmp->key)
				{
					if (!tmp->right)
						break ;
					tmp = tmp->right;
				}
				else if (key < tmp->key)
				{
					if (!tmp->left)
						break ;
					tmp = tmp->left;
				}
				else
				{
					if (!tmp->left)
						transplantNode(tmp, tmp->right);
					else if (!tmp->right)
						transplantNode(tmp, tmp->left);
					else if (tmp->right && tmp->left)
					{
						Node *tmpLoop = tmp;
						while (tmpLoop)
						{
							if (tmpLoop == tmp)
								tmpLoop = tmpLoop->left;
							else if (tmpLoop->left)
								tmpLoop = tmpLoop->right;
							else if (tmpLoop->right)
								tmpLoop = tmpLoop->left;
							else
							{
								nodeToSearchFrom = tmpLoop->left;
								transplantNode(tmpLoop, tmpLoop->left);
								transplantNode(tmp, tmpLoop);
								break ;
							}
						}
					}
					delete tmp;
					break ;
				}
			}
			
			//rotateAndRecolor(nodeToSearchFrom);
		}
};

#endif
