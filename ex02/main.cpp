/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/08 17:44:15 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try {
        Bureaucrat a("a", 2);
        Bureaucrat b("b", 150);
        ShrubberyCreationForm sForm("Shrubbery");
        RobotomyRequestForm rForm("Robotomy");
        PresidentialPardonForm pForm("President");
        
        std::cout << "Shrubbery tests:" << std::endl;
        b.signForm(sForm);
    }
}