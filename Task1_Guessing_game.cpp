#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    cout<<"Let's Start Number Guessing Game--->"<<endl;
    srand(time(0));

    int Generated_Number=rand()%(101);
    int User_Entered_Number;
cout<<"Enter number your number from 0 to 100: "<<endl;
cin>>User_Entered_Number;
while(true){
if( User_Entered_Number==Generated_Number){
    cout<<"Congratulation! You won."<<endl; break;
}
else{
    if( User_Entered_Number>Generated_Number) cout<<"too high "<<endl;

else{cout<<"too low"<<endl;}}

cout<<"Enter again: "<<endl;
cin>>User_Entered_Number;
}


    return 0;
}