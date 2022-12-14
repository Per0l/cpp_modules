/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperol-h <aperol-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:18:18 by aperol-h          #+#    #+#             */
/*   Updated: 2022/11/24 18:06:37 by aperol-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type::iterator				    iterator;
    typedef typename std::stack<T, Container>::container_type::const_iterator			const_iterator;
    typedef typename std::stack<T, Container>::container_type::reverse_iterator		    reverse_iterator;
    typedef typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;
    
    MutantStack <T, Container>() {};
    MutantStack <T, Container>(MutantStack<T, Container> const &copy): std::stack<T, Container>(copy) {};
    ~MutantStack<T, Container>() {};

    MutantStack<T, Container> &operator=(MutantStack<T, Container> const &copy) { 
        std::stack<T, Container>::operator=(copy);
        return *this;
    };

    iterator				begin()			{return this->c.begin();};
    const_iterator			begin() const	{return this->c.begin();};
    iterator				end()			{return this->c.end();};
    const_iterator			end()   const	{return this->c.end();};
    reverse_iterator		rbegin()		{return this->c.rbegin();};
    const_reverse_iterator	rbegin()const	{return this->c.rbegin();};
    reverse_iterator		rend()			{return this->c.rend();};
    const_reverse_iterator	rend()  const	{return this->c.rend();};
};

#endif
