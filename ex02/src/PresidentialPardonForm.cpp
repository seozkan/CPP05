/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:32 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:32 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
	_target = _target;
	_executed = false;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardon", 25, 5)
{
	_target = target;
	_executed = false;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try 
	{
		checkToExec(executor, *this);
		action(executor);
	}catch(std::exception& e)
	{
		std::cout<< e.what() << '\n';
	}
}

void PresidentialPardonForm::action(Bureaucrat const & executor) const 
{
	executor.getName();
	std::cout << GREEN << "EXEC " << _target << " has been pardoned by Zaphod Beeblebrox." RST << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy): AForm("PresidentialPardon", 25, 5)
{
	_target = toCopy._target;
	_executed = toCopy._executed;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
}