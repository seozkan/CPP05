/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:56:03 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:56:03 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("Default"),
_isSigned(false),
_gradeSign(1),
_gradeExec(1)
{
	return ;
}

AForm::AForm(std::string name, int grade2sign, int grade2exec): _name(name),
_gradeSign(grade2sign),
_gradeExec(grade2exec)
{
	_isSigned = false;
	if (grade2exec < 1 || grade2sign < 1)
		throw AForm::GradeTooHighException();
	if (grade2exec > 150 || grade2sign > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(void)
{
	return ;
}

AForm::AForm(const AForm& toCopy): _name(toCopy._name),
_isSigned(false),
_gradeSign(toCopy._gradeSign),
_gradeExec(toCopy._gradeExec)
{
	return ;
}

AForm& AForm::operator=(const AForm& toCopy)
{
	if (this != &toCopy)
		_isSigned = toCopy._isSigned;
	return (*this);
}

std::string AForm::getName(void) const
{
	return(_name);
}

bool AForm::getSignedStatus(void)
{
	return(_isSigned);
}

int AForm::getGradeSign(void)
{
	return(_gradeSign);
}

int AForm::getGradeExec(void)
{
	return(_gradeExec);
}

void AForm::beSigned(Bureaucrat& bure)
{
	try
	{
		if (bure.getGrade() <= _gradeSign)
		{
			_isSigned = true;
			std::cout << "'"<< _name<<"' Signed by: "
			<< bure.getName() << std::endl; 
		}
		else
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return(RED "AForm::GradeTooHighException" RST);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return(RED "AForm::GradeTooLowException" RST);
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return(RED "AForm::UnsignedFormException" RST);
}

std::ostream& operator<<(std::ostream& cout, AForm& toPrint)
{
	cout << "AForm(Name: " << toPrint.getName()
	<< ", Grade to Execute: " << toPrint.getGradeExec()
	<< ", Grade to Sign: " << toPrint.getGradeSign()
	<< ", Signed status: " << toPrint.getSignedStatus() << ") " << std::endl;	
	return(cout);
}

bool AForm::checkToExec(Bureaucrat const & exec, AForm const & f) const
{
	if (exec.getGrade() > f._gradeExec)
		throw GradeTooLowException();
	if (f._isSigned == false)
		throw UnsignedFormException();
	return(true);
}