/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/09/13 10:07:35 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bob", 1);
	std::cout << bureaucrat;

	try
	{
		bureaucrat->setGradeUp();
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat->setGrade(150);
		bureaucrat->setGradeDown();
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat->setGrade(-1);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	Form *form = new Form("Form1", 10, 11);
	std::cout << form;

	try
	{
		form->beSigned(*bureaucrat);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	bureaucrat->setGrade(11);

	try
	{
		form->beSigned(*bureaucrat);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	delete bureaucrat;
	return (0);
}
