/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:28 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 23:44:57 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <vector>
# include <deque>
# include <chrono>
# include <string>
# include <sstream>

class PmergeMe
{
private:
    std::vector<int> _v;
    std::deque<int>  _d;
    void    _vectorParse(std::string input);
    void    _dequeParse(std::string input);
public:
    PmergeMe();
    PmergeMe(PmergeMe const &copy);
    ~PmergeMe();

    PmergeMe const &operator=(PmergeMe const &copy);

    void vectorSort(std::string input);
    void dequeSort(std::string input);

    std::chrono::microseconds last_vector_time;
    std::chrono::microseconds last_deque_time;
};

#endif
