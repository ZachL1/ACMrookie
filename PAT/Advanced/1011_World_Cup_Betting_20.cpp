//
//  1011_World_Cup_Betting_20.cpp
//  workspace
//
//  Created by Zach Duan on 2022/5/5 11:03 AM.
//  GitHub: https://github.com/zachL1
//  Copyright © 2022 CSUFT. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    char namely[] = {'W', 'T', 'L'};
    double sum = 1;
    
    for (int i = 0; i < 3; ++i){
        double bet = -1, temp;
        int bet_namely = 0;
        for (int j = 0; j < 3; ++j){
            cin >> temp;
            if (bet < temp) {
                bet = temp;
                bet_namely = j;
            }
        }
        printf("%c ", namely[bet_namely]);
        sum *= bet;
    }
    printf("%.2f\n", (sum*0.65-1)*2);
    
    return 0;
}
