//
//  Parsing.hpp
//  Super Adventure
//
//  Created by Loan SENS on 25/09/15.
//  Copyright © 2015 Loan SENS. All rights reserved.
//

#ifndef PARSING_HPP
#define PARSING_HPP

#include <string>
#include <iostream>

class TextLine
{
public:
    TextLine(std::string line="*vide*") {_line=line;};
    void setLine(std::string line) {_line=line;};
    void printLine(void) {std::cout << _line << " (Fin de la ligne)" << std::endl;};
    std::string getLabel(void);
    std::string getText(void);
    void readLine(void);
private:
    std::string _line;
};

#endif /* PARSING_HPP */
