#include<bits/stdc++.h>
using namespace std;
//ofstream table;


void INSERT(string tablename,vector <string> values)
{
    table.open("db/"+tablename+".txt", ios::app);
    
    for(int i = 4; i < values.size(); i++)
    {
        
        table<<values[i]<<"#";
    }
    table<<"\n";
    table.close();

    
}