/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:57 by aer-razk          #+#    #+#             */
/*   Updated: 2023/01/03 13:44:21 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_HPP
#define		VECTOR_HPP
#include	"./includes.hpp"

template <typename T>
class vector
{
	public:
		vector();
		~vector();
		T	&operator=(T const &data);
		//iteretors
			//iterator class
		class iterator
		{
			private:
				T	*data_ptr;
			public:
				iterator(T *data_ptr);
				T&	operator*(T &data_ptr);
				T&	operator++();
				T&	operator+=(T &data_ptr);
				T&	operator+(T &data_ptr);
				T&	operator--();
				T&	operator-=(T &data_ptr);
				T*	operator->();
				T&	operator-(T &data_ptr);
				T&	operator[](unsigned int index);
				T	operator++(int);
				T	operator--(int);
		}
};

#endif