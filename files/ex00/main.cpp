/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:00:55 by acrespy           #+#    #+#             */
/*   Updated: 2023/09/13 09:00:56 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bob", 1);
	std::cout << bureaucrat;

	try
	{
		bureaucrat->setGradeUp();
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat->setGrade(150);
		bureaucrat->setGradeDown();
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat->setGrade(-1);
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	try
	{
		bureaucrat->setGrade(42);
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	delete (bureaucrat);
	return (0);
}
