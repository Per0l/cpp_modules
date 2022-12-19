/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:29:47 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/19 21:59:43 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <cstddef>

template <class T>
class Array
{
private:
    T *_array;
    unsigned int _n;
public:
    Array(): _n(0) {
        this->_array = new T[this->_n];
    };
    Array(unsigned int n): _n(n) {
        this->_array = new T[this->_n];
    };

    Array(Array const &copy): _n(copy._n) {
        this->_array = NULL;
		*this = copy;
    };

    ~Array() {
        delete[] this->_array;
    };

    Array const &operator=(Array const &copy) {
        if (this->_array != NULL)
            delete[] this->_array;
        this->_n = copy._n;
        this->_array = new T[this->_n];
        for (unsigned int i = 0; i < this->_n; i++)
            this->_array[i] = copy._array[i];
        return *this;
    };
    
    class ArrayIndexOutOfBoundsException: public std::exception {
        public: const char *what() const throw() {return "Index out of bounds";};
    };

    T &operator[](unsigned int idx) {
        if (idx >= _n || this->_array == NULL)
            throw ArrayIndexOutOfBoundsException();
        return this->_array[idx];
    };

    T const &operator[](unsigned int idx) const {
        if (idx >= _n || this->_array == NULL)
            throw ArrayIndexOutOfBoundsException();
        return this->_array[idx];
    };

    unsigned int size() const {
        return _n;
    };

};

#endif
