/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:32:21 by aperol-h          #+#    #+#             */
/*   Updated: 2023/03/18 22:45:12 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <string>

class RPN
{
private:
    std::stack<long> _s;
    static const std::string _tokens;
public:
    RPN();
    RPN(RPN const &copy);
    ~RPN();

    RPN const &operator=(RPN const &copy);

    class SyntaxErrorException: public std::exception {
        public: const char *what() const throw();
    };
    class NotEnoughOperandsException: public std::exception {
        public: const char *what() const throw();
    };
    class TooManyOperandsException: public std::exception {
        public: const char *what() const throw();
    };

    long evaluate(std::string expr);
};

#endif
