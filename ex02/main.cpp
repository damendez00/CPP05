/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/08 14:24:19 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void    formExecuteTest(Bureaucrat& bureaucrat) {
    try {
        // Form parameters: name, gradeToSign, gradeToExecute
        Form form("ExecutingForm", 10, 10);
        bureaucrat.executeForm(form);
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void    formSignTest(Bureaucrat& bureaucrat) {
    try {
        // Form parameters: name, gradeToSign, gradeToExecute
        Form form("SigningForm", 10, 10);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

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
    std::cout << "Correct parameters test:" << std::endl << std::endl;
    createObject("a", 1);
    createObject("b", 150);
    std::cout << "Incorrect parameters test:" << std::endl << std::endl;
    createObject("c", 1);
    createObject("d", 0);
    createObject("e", 151);
    std::cout << "Increment grade test:" << std::endl;
    try {
        Bureaucrat a("Incrementing Bcrt", 3);
        std::cout << a << std::endl;
        incrementGradeTest(a);
        std::cout << a << std::endl;
        incrementGradeTest(a);
        std::cout << a << std::endl;
        incrementGradeTest(a);
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Decrement grade test:" << std::endl;
    try {
        Bureaucrat b("Decrementing Bcrt", 148);
        std::cout << b << std::endl;
        decrementGradeTest(b);
        std::cout << b << std::endl;
        decrementGradeTest(b);
        std::cout << b << std::endl;
        decrementGradeTest(b);
        std::cout << b << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Sign form test:" << std::endl;
    try {
        Bureaucrat c("Signing Bcrt", 10);
        std::cout << c << std::endl;
        formSignTest(c);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Execute form test:" << std::endl;
    try {
        Bureaucrat d("Executing Bcrt", 10);
        std::cout << d << std::endl;
        formExecuteTest(d);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}