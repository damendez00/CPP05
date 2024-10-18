/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/18 17:38:16 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Alice", 1);

        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("human");
        PresidentialPardonForm pardon("obama");

        bureaucrat.signForm(shrubbery);
        shrubbery.execute(bureaucrat);

        bureaucrat.signForm(robotomy);
        robotomy.execute(bureaucrat);

        bureaucrat.signForm(pardon);
        pardon.execute(bureaucrat);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}