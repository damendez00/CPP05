/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/18 17:12:24 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        Bureaucrat b2("Bob", 150);

        std::cout << "Overload operator tests:" << std::endl;

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        std::cout << std::endl << "Increment/decrement handling tests:" << std::endl;
        
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        //b1.incrementGrade();
        //std::cout << "After increment: " << b1 << std::endl;

        b2.decrementGrade(); // This should throw an exception
        std::cout << "After decrement: " << b2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
