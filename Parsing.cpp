//
//  Parsing.cpp
//  Super Adventure
//
//  Created by Loan SENS on 25/09/15.
//  Copyright © 2015 Loan SENS. All rights reserved.
//

#include "Parsing.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int testReadline(void) {
    std::cout << "Hello, World! Holaaa \n";
    string line;
    ifstream myfile ("test_text.txt");
    TextLine cur_line;
    while ( getline (myfile,line) )  // Lis tout le fichier
    {
        std::cout << line <<" the end\n";
        //stringstream iss(line); // Converssions ou je sais pas trop quoi
        cur_line.setLine(line); // NECESSAIRE POUR CONNAITRE LA LIGNE
        //cur_line.printLine();
        cur_line.readLine();
        /*
         string label;
         getline(iss,label,':'); // Trouver le label qui se situe juste avant le ':'
         if (iss.good()) // Le texte continue sur la ligne courante
         {
         string rest;
         getline(iss, rest);
         cout << "Apres label:" << rest << endl;
         }
         cout << "Label:" << label << '\n';
         */
    }
    myfile.close();
    
    return 1;
}
