/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:32:57 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/07 09:27:45 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/includes.hpp"
#include "./headers/map.hpp"
#include "./headers/redBlackTree.hpp"
#include <map>

int main()
{
	ft::map<int, std::string> karim;
	/*karim.insert(std::pair<int, std::string>(10, "ten"));
	karim.insert(std::pair<int, std::string>(18, "seven"));
	karim.insert(std::pair<int, std::string>(7, "eighteen"));
	karim.insert(std::pair<int, std::string>(15, "eighteen"));
	karim.insert(std::pair<int, std::string>(16, "eighteen"));
	karim.insert(std::pair<int, std::string>(30, "eighteen"));
	karim.insert(std::pair<int, std::string>(25, "eighteen"));
	karim.insert(std::pair<int, std::string>(40, "eighteen"));
	karim.insert(std::pair<int, std::string>(60, "eighteen"));
	karim.insert(std::pair<int, std::string>(2, "eighteen"));
	karim.insert(std::pair<int, std::string>(1, "eighteen"));
	karim.insert(std::pair<int, std::string>(70, "eighteen"));
	karim.insert(std::pair<int, std::string>(19, "eighteen"));*/
	/*karim.getFirstNode();
	karim.erase(19);*/
	karim.insert(std::pair<int, std::string>(10, "eighteen"));
	karim.insert(std::pair<int, std::string>(5, "eighteen"));
	karim.insert(std::pair<int, std::string>(30, "eighteen"));
	karim.insert(std::pair<int, std::string>(-5, "eighteen"));
	karim.insert(std::pair<int, std::string>(7, "eighteen"));
	karim.insert(std::pair<int, std::string>(20, "eighteen"));
	karim.insert(std::pair<int, std::string>(38, "eighteen"));
	karim.insert(std::pair<int, std::string>(35, "eighteen"));
	karim.getFirstNode();
	karim.erase(30);
	std::cout << "=======after erase========\n";
	karim.getFirstNode();
while(1);


}
