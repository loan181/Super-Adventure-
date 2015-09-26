//
//  Parsing.cpp
//  Super Adventure
//
//  Created by Loan SENS on 25/09/15.
//  Copyright © 2015 Loan SENS. All rights reserved.
//

#include "Parsing.hpp"
#include "functions.hpp"
#include <iostream>
#include <string>

std::string TextLine::getLabel(void)
{
    return _line.substr(0,_line.find(':'));
}

std::string TextLine::getText(void)
{
    return _line.substr(_line.find(':')+1,_line.length());
}

void TextLine::readLine(void)
{
    std::string text = getText();
    if(text.find('{') != std::string::npos)
    {
        size_t ind_start = text.find('{');
        std::cout << text.substr(0,text.find('{')) << std::endl;
        size_t ind_end = text.find('}');
        std::string choices = text.substr(ind_start+1,ind_end-ind_start-1);
        printChoices(choices);
        std::cout << text.substr(ind_end+1,text.length());
        int reponse;
        std::cout << std::endl << "Réponse : ";
        std::cin >> reponse;
            while(reponse>countCharacter(choices,"|"))
            {
                std::cout << "Veuillez donner une autre valeur : ";
                std::cin >> reponse;
            }
        std::cout << reponse;
        std::cout << "Label d'arrivé : " << findNextLabelDirection(choices, reponse);
    }
}
