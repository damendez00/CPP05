/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/09 14:59:05 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        Bureaucrat b2("Bob", 150);
        Bureaucrat b3 = b1; // Testing the copy constructor
        //Bureaucrat b4("Jhon", -2);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << "Copy of b1 (b3): " << b3 << std::endl; //?

        // Test increment and decrement
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        b2.decrementGrade(); // This should throw an exception
        std::cout << "After decrement: " << b2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
