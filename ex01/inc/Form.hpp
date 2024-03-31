/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:05:53 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 13:05:53 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	Form(void);
	Form(std::string name, int grade2sign, int grade2exec);
	~Form(void);
	Form(const Form& toCopy);
	Form& operator=(const Form& toCopy);

	std::string			getName(void);
	bool				getSignedStatus(void);
	int					getGradeSign(void);
	int					getGradeExec(void);
	void				beSigned(Bureaucrat& bureaucrat);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExec;
};

std::ostream& operator<<(std::ostream& cout, Form& toPrint);
#endif