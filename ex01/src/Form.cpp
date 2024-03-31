/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:54:47 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:54:47 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Default"), _isSigned(false), _gradeSign(1),
_gradeExec(1)
{
	return;
}

Form::Form(std::string name, int grade2sign, int grade2exec): _name(name),
_gradeSign(grade2sign), _gradeExec(grade2exec)
{
	_isSigned = false;
	if (grade2exec < 1 || grade2sign < 1)
		throw Form::GradeTooHighException();
	if (grade2exec > 150 || grade2sign > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
	return;
}

Form::Form(const Form& toCopy): _name(toCopy._name),
_isSigned(false),
_gradeSign(toCopy._gradeSign),
_gradeExec(toCopy._gradeExec)
{
	return;
}

Form& Form::operator=(const Form& toCopy)
{
	if (this != &toCopy)
	{
		_isSigned = toCopy._isSigned;
	}
	return (*this);
}

std::string Form::getName(void)
{
	return(_name);
}

bool Form::getSignedStatus(void)
{
	return(_isSigned);
}

int Form::getGradeSign(void)
{
	return(_gradeSign);
}

int Form::getGradeExec(void)
{
	return(_gradeExec);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= _gradeSign)
		{
			_isSigned = true;
			std::cout << "'"<< _name<<"' Signed by: "
			<< bureaucrat.getName() << std::endl; 
		}
		else
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const char* Form::GradeTooHighException::what() const throw()
{
	return(RED "Form::GradeTooHighException" RST);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return(RED "Form::GradeTooLowException" RST);
}

std::ostream& operator<<(std::ostream& cout, Form& toPrint)
{
	cout << "Form(Name: " << toPrint.getName()
	<< ", Grade to Execute: " << toPrint.getGradeExec()
	<< ", Grade to Sign: " << toPrint.getGradeSign()
	<< ", Signed status: " << toPrint.getSignedStatus() << ") " << std::endl;	
	return(cout);
}