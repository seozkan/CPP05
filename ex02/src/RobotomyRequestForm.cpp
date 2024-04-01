/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:42 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:42 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
	_target = _target;
	_executed = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45)
{
	_target = target;
	_executed = false;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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

void RobotomyRequestForm::action(Bureaucrat const & executor) const 
{
	srand(time(0));
	std::cout << BLUE "...drilling noises..." RST << std::endl;
	executor.getName();
	if (rand() % 2 == 0)
		std::cout << GREEN << "EXEC " << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << GREEN << "EXEC " << _target << " has failed to be robotomized." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy): AForm("Robotomy", 72, 45)
{
	_target = toCopy._target;
	_executed = toCopy._executed;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
}
