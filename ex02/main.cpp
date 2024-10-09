/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/09 17:36:15 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Alice", 1);  // Create a bureaucrat with the highest grade

        // Create forms
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod");

        // Sign and execute the forms
        bureaucrat.signForm(shrubbery);
        shrubbery.execute(bureaucrat);

        bureaucrat.signForm(robotomy);
        robotomy.execute(bureaucrat);

        bureaucrat.signForm(pardon);
        pardon.execute(bureaucrat);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Handle any exceptions
    }

    return 0;
}