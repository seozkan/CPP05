/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:46 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:46 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm 
{
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& toCopy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& toCopy);

		void execute(Bureaucrat const & executor) const;
		void action(Bureaucrat const & executor) const;

	private:
		std::string _target;
		bool		_executed;
};
#endif