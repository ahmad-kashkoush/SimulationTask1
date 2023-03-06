
#include "Date.h"

double Principal, AnnualRate, MonthlyRate;
/*
 240000
 0.0425
 30
 */
double Term;// number of years
double NumberOfPayment;
Date d;
double Pow(double a, double b){
    double k=1;
    while(b--){
        k*=a;
    }
    return k;
}
void TakeInput(){
//    cout<<"Enter Principal:";
    cin>>Principal;
//    cout<<"Enter Annual Rate :";
    cin>>AnnualRate;
//    cout<<"Enter on How many Years: ";
    cin>>Term;
    d.Enter();
}
void DoProcess(){
    NumberOfPayment=Term*12;
    MonthlyRate=AnnualRate/12;
}
void PrintOutput(){
        double I=MonthlyRate,N=NumberOfPayment,P=Principal;
        double M=P*(I*Pow(I+1, N))/(Pow(1+I, N)-1);
        double BeginningBalance=Principal;
        cout<<"Month\tBeginning Balance\tPayment\tInterest\tPrincipal\tEnding Balance\n";
        for(int Month=1;BeginningBalance>0;Month++){
            // interest, principal
            double Interest=BeginningBalance*MonthlyRate;
            double MonthlyPrincipal=M-Interest;
            cout<<Month<<"\t ";
            d.Print();
            cout<<"\t"<<BeginningBalance<<"\t\t\t "<<M<<"\t"<<Interest<<"\t\t"<<MonthlyPrincipal<<"\t";
             if(BeginningBalance<M){
                 cout<<0;
                 BeginningBalance=0;
                 continue;
             }
             d.next();
              BeginningBalance=BeginningBalance-MonthlyPrincipal;
             // Now Beginning =Endiing
             cout<<BeginningBalance<<"\n";
        }
}
int main(){
    freopen("input.txt","rt", stdin);
    freopen("output.txt","w", stdout);
    TakeInput();
    DoProcess();
    PrintOutput();
    return 0;
}