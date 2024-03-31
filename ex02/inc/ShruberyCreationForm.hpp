/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:56 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:56 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERYCREATIONFORM_HPP
# define SHRUBERYCREATIONFORM_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShruberyCreationForm : public AForm 
{
	public:
		ShruberyCreationForm();
		~ShruberyCreationForm();
		ShruberyCreationForm(std::string target);
		ShruberyCreationForm(const ShruberyCreationForm& toCopy);
		ShruberyCreationForm& operator=(const ShruberyCreationForm& toCopy);

		void execute(Bureaucrat const & executor) const;
		void action(Bureaucrat const & executor) const;

	private:
		std::string _target;
};
#endif