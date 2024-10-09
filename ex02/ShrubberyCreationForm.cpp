/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:06:06 by damendez          #+#    #+#             */
/*   Updated: 2024/10/09 17:06:33 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ), _target( src._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& rhs ) {
    (void)rhs;
    return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
    if ( this->isSigned() == false )
        throw AForm::FormNotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }

    // std::ofstream file( this->getName() + "_shrubbery" );
    // file << "                      ___" << std::endl;
    // file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    // file << "             ,-'          __,,-- \\" << std::endl;
    // file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    // file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    // file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    // file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    // file << "     (     ,-'                  `." << std::endl;
    // file << "      `._,'     _   _             ;" << std::endl;
    // file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    // file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    // file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    // file << "                \"Hb HH dF" << std::endl;
    // file << "                 \"HbHHdF" << std::endl;
    // file << "                  |HHHF" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  |HHH|" << std::endl;
    // file << "                  dHHHb" << std::endl;
    // file << "                .dFd|bHb.               o" << std::endl;
    // file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    // file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    // file << "##########################################" << std::endl;
    // file.close();
}