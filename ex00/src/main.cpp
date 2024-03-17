/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:24:17 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/17 14:02:55 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bur("Ozkan", 4);
	bur << std::cout;
	bur.incrementGrade(3);
	bur << std::cout;
	bur.incrementGrade(3);
	bur << std::cout;
	bur.decrementGrade(148);
	bur << std::cout;
	bur.decrementGrade(148);
	bur << std::cout;
	return (0);
}
