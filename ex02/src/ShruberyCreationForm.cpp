/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan < seozkan@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:55:52 by seozkan           #+#    #+#             */
/*   Updated: 2024/03/24 12:55:52 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include <fstream>

ShruberyCreationForm::ShruberyCreationForm() : AForm("Default", 145, 137)
{
	_target = _target;
}

ShruberyCreationForm::ShruberyCreationForm(std::string target): AForm("Shrubery", 145, 137)
{
	_target = target;
}

void ShruberyCreationForm::execute(Bureaucrat const & executor) const
{
	try 
	{
		checkToExec(executor, *this);
		action(executor);
	}catch(std::exception& e)
	{
		std::cout<< e.what() << '\n';
	}
}

void ShruberyCreationForm::action(Bureaucrat const & executor) const 
{
		std::string outputFileName = _target; 
		outputFileName += "_shrubery.txt";
		std::ofstream outputFile(outputFileName.c_str());
		if (!outputFile.is_open()) {
			std::cerr << "Error opening the file." << std::endl;
		}

		outputFile << "    *\n";
		outputFile << "   / \\\n";
		outputFile << "  /   \\\n";
		outputFile << " /     \\\n";
		outputFile << "/  ___  \\\n";
		outputFile << "\nSigned by: " << executor.getName()<<std::endl;
		outputFile.close();
		std::cout << GREEN << "EXEC " << _target << " created successfully." << RST << std::endl;
}

ShruberyCreationForm::~ShruberyCreationForm()
{
	return ;
}

ShruberyCreationForm::ShruberyCreationForm(const ShruberyCreationForm& toCopy): AForm("Shrubery", 145, 137)
{
	_target = toCopy._target;
}

ShruberyCreationForm& ShruberyCreationForm::operator=(const ShruberyCreationForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
	}
	return(*this);
}
