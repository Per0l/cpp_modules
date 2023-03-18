/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:21 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 15:32:21 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

class RPN
{
private:

public:
    RPN();
    RPN(RPN const &copy);
    ~RPN();

    RPN const &operator=(RPN const &copy);
};

#endif
