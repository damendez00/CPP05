/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/18 17:28:22 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    try {
        Bureaucrat bureaucrat1("Alice", 1);
        Bureaucrat bureaucrat2("Bob", 150);
        Form form("Form 1", 50, 100);

        std::cout << form << std::endl;
        
        std::cout << std::endl << "signForm() tests:" << std::endl;
        bureaucrat2.signForm(form);
        std::cout << form << std::endl;
        
        bureaucrat1.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
