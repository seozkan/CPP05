/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:54:24 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:54:24 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("SEO", 4);
	b1<< std::cout;
	b1.incrementGrade(3);
	b1<< std::cout;
	b1.incrementGrade(3);
	b1<< std::cout;
	b1.decrementGrade(148);
	b1<< std::cout;
	b1.decrementGrade(148);
	b1<< std::cout;
	return (0);
}