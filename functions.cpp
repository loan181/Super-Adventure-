#include "functions.hpp"
#include "Parsing.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

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

int testReadline(void)
{
    std::cout << "Hello, World! Holaaa \n";
    std::string line;
    std::ifstream myfile ("test_text.txt");
    TextLine cur_line;
    while ( getline (myfile,line) )  // Lis tout le fichier
    {
        std::cout << line << " the end\n";
        //stringstream iss(line); // Converssions ou je sais pas trop quoi
        cur_line.setLine(line); // NECESSAIRE POUR CONNAITRE LA LIGNE
        //cur_line.printLine();
        cur_line.readLine();
        /*
         std::string label;
         getline(iss,label,':'); // Trouver le label qui se situe juste avant le ':'
         if (iss.good()) // Le texte continue sur la ligne courante
         {
         std::string rest;
         getline(iss, rest);
         cout << "Apres label:" << rest << endl;
         }
         cout << "Label:" << label << '\n';
         */
    }
    myfile.close();
    
    return 1;
}