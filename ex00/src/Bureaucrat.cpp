/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:23:47 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/17 14:01:29 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
	std::cout << "Default Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat "<< _name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy)
{
    if (this != &toCopy) {
        _grade = toCopy._grade;
    }
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original): _name(original._name)
{
	_grade = original._grade;
	std::cout << "Copy constructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(int toInc)
{
	try
	{
		if (_grade - toInc < 1)
			throw Bureaucrat::GradetooHighException();
		else
			_grade -= toInc;
	} 
	catch (const Bureaucrat::GradetooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decrementGrade(int toDec)
{
	try
	{
		if (_grade + toDec > 150)
			throw Bureaucrat::GradetooLowException();
		else
			_grade += toDec;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::ostream& Bureaucrat::operator<<(std::ostream& o)
{
	o <<this->getName()<<", bureaucrat grade " << this->getGrade()<<std::endl;
	return (o);
}

const char* Bureaucrat::GradetooHighException::what() const throw()
{
	return ("\033[31mBureaucrat::Exception -> GradetooHigh\033[0m");
}

const char* Bureaucrat::GradetooLowException::what() const throw()
{
	return ("\033[31mBureaucrat::Exception -> GradetooLow\033[0m");
}