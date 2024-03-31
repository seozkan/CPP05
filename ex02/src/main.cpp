/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:26 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:26 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

static void ShruberyTest()
{
	Bureaucrat b("SEO_Shrubery", 137);
	ShruberyCreationForm f("sform");
	f.beSigned(b);
	f.execute(b);
	std::cout << YELLOW << "ShruberyTest EXCEPTION START HERE" << RST << std::endl;	
	b.decrementGrade(1);
	b.signForm(f);
	b.executeForm(f);
	std::cout << YELLOW << "ShruberyTest EXCEPTION END HERE" << RST << std::endl;	
}

static void RobotomyTest()
{
	Bureaucrat b("SEO_Robotomy", 45);
	RobotomyRequestForm f("rform");
	f.beSigned(b);
	f.execute(b);
	std::cout << YELLOW << "RobotomyTest EXCEPTION START HERE" << RST << std::endl;	
	b.decrementGrade(1);
	b.signForm(f);
	b.executeForm(f);
	std::cout << YELLOW << "RobotomyTest EXCEPTION END HERE" << RST << std::endl;	
}

static void PresidentTest()
{
	Bureaucrat b("SEO_President", 5);
	PresidentialPardonForm f("pform");
	f.beSigned(b);
	f.execute(b);
	std::cout << YELLOW << "PresidentTest EXCEPTION START HERE" << RST << std::endl;	
	b.decrementGrade(1);
	b.signForm(f);
	b.executeForm(f);
	std::cout << YELLOW << "PresidentTest EXCEPTION END HERE" << RST << std::endl;	
}

int main(void)
{
	ShruberyTest();
	RobotomyTest();
	PresidentTest();
	return (0);
}