/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:54:32 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:54:32 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
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
		{
			throw Bureaucrat::GradetooHighException();
		}else
		{
			_grade -= toInc;
			std::cout <<"Incremented "<<_name<<" grade by: "<< toInc <<std::endl;
		}
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
		{
			_grade += toDec;
			std::cout <<"Decrement " << _name << " grade by: "<< toDec <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream& Bureaucrat::operator<<(std::ostream& cout)
{
	cout << this->getName() << ", bureaucrat grade " << this->getGrade() << std::endl;
	return (cout);
}

const char* Bureaucrat::GradetooHighException::what() const throw()
{
	return (RED "Bureaucrat::GradeTooHighException" RST);
}

const char* Bureaucrat::GradetooLowException::what() const throw()
{
	return (RED "Bureaucrat::GradeTooLowException" RST);
}

void Bureaucrat::signForm(Form& f)
{
	f.beSigned(*this);
	if (f.getSignedStatus() == false)
		std::cout << this->_name << " couldn't sign '" << f.getName()<<"' because is not worthy"<< std::endl;
}
