/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:32:57 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/04 16:39:59 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/includes.hpp"
#include "./headers/map.hpp"
#include "./headers/redBlackTree.hpp"
#include <map>

int main()
{
	ft::map<int, std::string> karim;
	karim.insert(std::pair<int, std::string>(10, "ten"));
	karim.insert(std::pair<int, std::string>(7, "seven"));
	karim.insert(std::pair<int, std::string>(18, "eighteen"));
	karim.insert(std::pair<int, std::string>(15, "eighteen"));
	karim.getFirstNode();
}
