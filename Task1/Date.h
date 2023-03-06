//
// Created by ahmed-kashkoush on 3/6/23.
//

#ifndef TASK1_DATE_H
#define TASK1_DATE_H
#include<bits/stdc++.h>
using namespace std;
class Date{
private:
    int day, month, Year;
public:
    Date(){}
    void Print(){
        cout<<day<<"/" <<month<<"/"<<Year;
    }
    void Enter(){
        char s1, s2;
//        cout<<"Enter Date:";
        cin>>day>>s1>>month>>s2>>Year;
    }
    void next(){
        if(month<12){
            month;
        }
        else if(month==12){
            Year++;
            month=1;
        }
    }

};
#endif //TASK1_DATE_H
