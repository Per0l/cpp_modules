/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:28 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 15:32:28 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe
{
private:

public:
    PmergeMe();
    PmergeMe(PmergeMe const &copy);
    ~PmergeMe();

    PmergeMe const &operator=(PmergeMe const &copy);
};

#endif
