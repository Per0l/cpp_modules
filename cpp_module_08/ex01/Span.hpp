/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:32:05 by aperol-h          #+#    #+#             */
/*   Updated: 2022/12/19 22:56:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
private:
    std::vector<int> _vec;
    unsigned int _n;
public:
    Span();
    Span(unsigned int n);
    Span(Span const &copy);
    ~Span();

    Span const &operator=(Span const &copy);

    void addNumber(int x);
    int shortestSpan();
    int longestSpan();

    class StorageFullException: public std::exception {
        public: const char *what() const throw();
    };
    class NoSpanException: public std::exception {
        public: const char *what() const throw();
    };

    template <typename T> void insert(T first, T last) {
        if ((last - first) + _vec.size() > _n)
            throw StorageFullException();
        _vec.insert(_vec.end(), first, last);
    }

    void insert(int *first, int *last);

    void debug();
};

#endif
