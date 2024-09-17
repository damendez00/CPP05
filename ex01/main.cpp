/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/08/10 12:35:19 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

int main() {
    createObject("1", 20);
    Bureaucrat a ("increase", 5);
    std::cout << a;
    incrementGradeTest(a);
    std::cout << a;
    decrementGradeTest(a);
}