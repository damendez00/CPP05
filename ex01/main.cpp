/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/07 15:42:40 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void    createObject(std::string name, int grade) {
    try {
        Bureaucrat a(name, grade);
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl << std::endl;
    }
}

void    incrementGradeTest(Bureaucrat& bureaucrat) {
    try {
      bureaucrat.incrementGrade();  
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void    decrementGradeTest(Bureaucrat& bureaucrat) {
    try {
      bureaucrat.decrementGrade();  
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main( void )
{
    try {
        Bureaucrat bureaucrat("Robert", 11);
        // Form parameters are (name, gradeToSign, gradeToExecute)
        Form form("formName", 10, 15);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}