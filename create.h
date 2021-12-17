#include<bits/stdc++.h>
using namespace std;
ofstream table, schema;

void CREATE(string tablename,vector <pair<string, string>> attributes)
{

    table.open("db/"+tablename+".txt");
    schema.open("db/schema.txt", ios::app);
    schema<<endl<<tablename<<"#";
    
    for(int i = 0; i < attributes.size(); i++)
    {
        cout<<attributes[i].first<<"#"<<attributes[i].second<<"#"<<endl;
        schema<<attributes[i].first<<"#"<<attributes[i].second<<"#";
    }
   
    
    table.close();
    schema.close();





}