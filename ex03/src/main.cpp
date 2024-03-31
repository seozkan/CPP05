/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:56:30 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:56:30 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

static void testOk()
{
	std::cout << YELLOW "TEST OK START" RST << std::endl;
	Bureaucrat b("SEO", 1);
	Intern intern;
	AForm* f = intern.makeForm("robotomy request", "sform");
	f->beSigned(b);
	f->execute(b);
	b.signForm(*f);
	b.executeForm(*f);
	std::cout << YELLOW "TEST OK END" RST << std::endl;
}

static void testException()
{
	std::cout << YELLOW "TEST EXCEPTION START" RST << std::endl;
	Bureaucrat b("SEO", 123);
	Intern intern;
	AForm* f = intern.makeForm("robotomy request", "rform");
	f->execute(b);
	b.signForm(*f);
	b.executeForm(*f);
	std::cout << YELLOW "TEST EXCEPTION END" RST << std::endl;
}

int main(void)
{
	testOk();
	testException();
	return (0);
}