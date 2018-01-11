//
//  happyke.cpp
//  snake
//
//  Created by Jiyang Wang on 2018/1/1.
//  Copyright © 2018 Jiyang Wang. All rights reserved.
//

#include "happyke.hpp"
#include "Pickpng.hpp"

void printfilmstream(const string& filename){
    ifstream input(filename);
    string s;
    while(getline(input,s)){
        if(s == "end"){
            Delay(44);
            cout<<s<<endl;
            system("clear");
        }
        cout<<s<<endl;
    }}
