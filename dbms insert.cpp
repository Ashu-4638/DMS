#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<stdbool.h>
#include <iomanip>
#include<fstream>
using namespace std;

int main()
{
    string column1, column2, column3, column4;
    system("cls");
    fstream file;
    cout<<"\n";
    cout<<"insert a new record"<<endl;
    cout<<"Enter column1: ";
    cin>>column1;
    cout<<"\n";

    cout<<"Enter column2: ";
    cin>>column2;
    cout<<"\n";

    cout<<"Enter column3: ";
    cin>>column3;
    cout<<"\n";

    cout<<"Enter column4: ";
    cin>>column4;

    file.open("record.txt" , ios::app | ios::out);
    file<<" "<<column1<<" "<<column2<<" "<<column3<<" "<<column4<<" "<<"\n";
    file.close();

}
