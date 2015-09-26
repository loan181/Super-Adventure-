//
//  Parsing.hpp
//  Super Adventure
//
//  Created by Loan SENS on 25/09/15.
//  Copyright © 2015 Loan SENS. All rights reserved.
//

#ifndef Parsing_hpp
#define Parsing_hpp

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

int countCharacter(std::string s, std::string c);
void printChoices(std::string choices);
std::string findNextLabelDirection(std::string choices, int reponse);



std::string TextLine::getLabel(void)
{
    return _line.substr(0,_line.find(':'));
}

std::string TextLine::getText(void)
{
    return _line.substr(_line.find(':')+1,_line.length());
}

int countCharacter(std::string s, std::string c) // remplacer par un char
{
    int count = 0;
    
    for (int i = 0; i < s.size(); i++)
        if (s[i] == c[0]) count++;
    
    return count;
}

void printChoices(std::string choices)
{
    int choice_nbr = countCharacter(choices,"|");
    size_t index_char = 0; // Pour passer l'acolade
    size_t index_next_label = choices.find('@');
    size_t index_next_choice = choices.find('|');
    std::string text;
    for (int i=0; i<=choice_nbr; ++i)
    {
        std::cout << '\t' << i << " : " << text;
        if(index_next_label < index_next_choice // S'il y à un avis de redirection
           or index_next_choice == std::string::npos)
        {
            std::cout << choices.substr(index_char,index_next_label-index_char);
            index_next_label = choices.find('@', index_next_label+1);
            if(index_next_label == std::string::npos)
                index_next_label = choices.length();
        }
        else
            std::cout << choices.substr(index_char,index_next_choice-index_char);
        std::cout << std::endl;
        index_char = index_next_choice+1;
        index_next_choice = choices.find('|', index_next_choice+1);
    }
}

std::string findNextLabelDirection(std::string choices, int reponse)
{
    size_t index_next_choice = 0;
    size_t lab_index;
    std::string lab;
    for(int i=0; i<reponse; ++i)
    {
        index_next_choice = choices.find('|',index_next_choice+1);
    }
    lab_index = choices.find('@',index_next_choice+1);
    if (lab_index == std::string::npos or lab_index > choices.find('|',index_next_choice+1))
        lab = "None";
    else
        lab = choices.substr(lab_index+1, choices.find('|',index_next_choice+1)-lab_index-1);
    return lab;
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

#endif /* Parsing_hpp */
