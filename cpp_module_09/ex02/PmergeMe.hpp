/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:28 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/19 03:05:18 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
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
    void    _insertionSort(T &c);

    template <typename T>
    void    _mergeSort(T &c);
    
    template <typename T>
    void    _sort(T &c, std::string input);

public:
    PmergeMe();
    PmergeMe(PmergeMe const &copy);
    ~PmergeMe();

    PmergeMe const &operator=(PmergeMe const &copy);

    class NegativeNumberErrorException: public std::exception {
        public: const char *what() const throw();
    };

    class InvalidArgumentErrorException: public std::exception {
        public: const char *what() const throw();
    };

    void vectorSort(std::string input);
    void dequeSort(std::string input);

    void printVector();
    void printDeque();

    template <typename T>
    size_t    _printContainer(T &c);

    template <typename T>
    void	_parse(T &c, std::string input);

    std::chrono::microseconds time_elpased;
};

#endif
