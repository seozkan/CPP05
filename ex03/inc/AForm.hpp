/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:56:09 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:56:09 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
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

		class UnsignedFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		AForm(void);
		AForm(std::string name, int grade2sign, int grade2exec);
		virtual ~AForm(void);
		AForm(const AForm& toCopy);
		AForm& operator=(const AForm& toCopy);

		std::string			getName(void) const;
		bool				getSignedStatus(void);
		int					getGradeSign(void);
		int					getGradeExec(void);
		void				beSigned(Bureaucrat& bure);
		virtual void 		execute(Bureaucrat const & executor) const = 0; 
		virtual void 		action(Bureaucrat const & executor) const = 0; 
		bool				checkToExec(Bureaucrat const & exec, AForm const & f) const;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExec;
};

std::ostream& operator<<(std::ostream& cout, AForm& toPrint);
#endif