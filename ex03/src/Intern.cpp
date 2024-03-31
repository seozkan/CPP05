/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:56:25 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:56:25 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	_forms[0] = "presidential pardon";
	_forms[1] = "robotomy request";
	_forms[2] = "shrubery creation";
	_makeForm[0] = &Intern::makePresidentialPardonForm;
	_makeForm[1] = &Intern::makeRobotomyRequestForm;
	_makeForm[2] = &Intern::makeShruberyCreationForm;
}

Intern::~Intern()
{
	return ;
}

Intern::Intern(const Intern& toCopy)
{
	*this = toCopy;
}

Intern& Intern::operator=(const Intern& toCopy)
{
	(void)toCopy;
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm* form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == _forms[i])
			form = (this->*_makeForm[i])(target);
	}
	return (form);
}

AForm* Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShruberyCreationForm(std::string target)
{
	return (new ShruberyCreationForm(target));
}
