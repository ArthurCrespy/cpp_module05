/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:47:56 by acrespy           #+#    #+#             */
/*   Updated: 2023/09/13 13:47:57 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShubberyCreationForm name constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
	std::cout << "ShubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShubberyCreationForm assignation operator called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string     line;
	std::ifstream   infile;
	std::ofstream   outfile;

	if (checkExec(executor))
	{
		outfile.open(this->_target + "_shrubbery");
		if (outfile.fail() || !outfile.is_open())
			throw std::runtime_error("Error while opening outfile");
		infile.open("tree.ascii");
		if (infile.fail() || !infile.is_open())
		{
			infile.close();
			throw std::runtime_error("Error while opening infile");
		}
		while (std::getline(infile, line))
			outfile << line << std::endl;
		infile.close();
		outfile.close();
		std::cout << "Shrubbery has been created in " << this->_target << "_shrubbery" << std::endl;
	}
}
