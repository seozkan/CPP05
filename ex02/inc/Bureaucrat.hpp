/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:21 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:21 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP	
# define BUREAUCRAT_HPP

# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define RST "\033[0m"

class AForm;
#include <iostream>

class Bureaucrat
{	
	public:
		class GradetooHighException : public std::exception 
		{
			public:
				const char * what() const throw();
		};
		class GradetooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& original);
	Bureaucrat& operator=(const Bureaucrat& toCopy);

	std::string		getName() const;
	int				getGrade() const;
	void			incrementGrade(int toInc);
	void			decrementGrade(int toDec);
	std::ostream&	operator<<(std::ostream& cout);
	void			signForm(AForm& f);
	void			executeForm(AForm const & form);

	private:
		const std::string 	_name;
		int					_grade;
};
#endif