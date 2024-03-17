/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:23:54 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/17 14:01:18 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP	
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{	
	private:
		const std::string 	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& original);
		Bureaucrat& operator=(const Bureaucrat& toCopy);

		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade(int toInc);
		void			decrementGrade(int toDec);
		std::ostream&	operator<<(std::ostream& o);

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

};
#endif