/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:28 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 01:40:39 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <chrono>
# include <string>
# include <sstream>
# include <iostream>

class PmergeMe
{
private:
    std::vector<int> _v;
    std::deque<int>  _d;
    void    _vectorParse(std::string input);
    void    _dequeParse(std::string input);
    template <typename T>
    void	_parse(T &c, std::string input);
    template <typename T>
    void    _insertionSort(T &c);

    template <typename T>
    void    _printContainer(T begin, T end);

    template <typename T>
    void    _sort(T &c, std::string input);
public:
    PmergeMe();
    PmergeMe(PmergeMe const &copy);
    ~PmergeMe();

    PmergeMe const &operator=(PmergeMe const &copy);


    void vectorSort(std::string input);
    void dequeSort(std::string input);

    void printVector();
    void printDeque();

    template <typename T>
    void swap(T &a, T &b) {
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    std::chrono::microseconds time_elpased;
};

#endif
