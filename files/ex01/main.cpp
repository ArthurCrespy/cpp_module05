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
	Bureaucrat bureaucrat = Bureaucrat("Bob", 1);
	std::cout << &bureaucrat;

	try
	{
		bureaucrat.setGradeUp();
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat.setGrade(150);
		bureaucrat.setGradeDown();
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat.setGrade(-1);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat.setGrade(42);
		std::cout << &bureaucrat;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		Form form = Form("Form0", 155, 11);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	Form form = Form("Form1", 10, 11);
	std::cout << &form;

	try
	{
		form.beSigned(bureaucrat);
	}
	catch (std::exception & e)
	{
		std::cout << bureaucrat.getName() << " couldn’t sign " << form.getName() << " because : " << e.what() << std::endl;
	}

	bureaucrat.setGrade(11);

	try
	{
		form.beSigned(bureaucrat);
	}
	catch (std::exception & e)
	{
		std::cout << bureaucrat.getName() << " couldn’t sign " << form.getName() << " because : " << e.what() << std::endl;
	}

	bureaucrat.setGrade(10);

	try
	{
		form.beSigned(bureaucrat);
		std::cout << &form;
	}
	catch (std::exception & e)
	{
		std::cout << bureaucrat.getName() << " couldn’t sign " << form.getName() << " because : " << e.what() << std::endl;
	}

	return (0);
}
