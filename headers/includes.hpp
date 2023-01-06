/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:32:11 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/06 09:17:24 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INCLUDES_HPP
#define		INCLUDES_HPP
#include	<iostream>
#include	<string>
#include	<fstream>
#include	<vector>

class errors:public std::exception
{
	private:
		const char *	message;
	public:
		errors(const char * message):message(message){}
		virtual const char * what() const throw()
		{
			return (this->message);
		}
};
#endif