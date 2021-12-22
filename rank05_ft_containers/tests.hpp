/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-louie <mdesfont@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:06:28 by mel-louie         #+#    #+#             */
/*   Updated: 2021/12/22 13:58:25 by mel-louie        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

void    vectorConstructors()
{
    TESTED_NAMESPACE::vector<int>   first;
    TESTED_NAMESPACE::vector<int>   second(5, 42);
    TESTED_NAMESPACE::vector<int>   third(second.begin(), second.end());
    TESTED_NAMESPACE::vector<int>   forth(third);
}

void    testVector()
{
    vectorConstructors();
}