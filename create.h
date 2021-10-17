#include<bits/stdc++.h>
using namespace std;
ofstream table, schema;

void CREATE(string tablename,vector <pair<string, string>> attributes)
{

    table.open("db/"+tablename+".txt");
    schema.open("db/schema.txt", ios::app);
    schema<<tablename<<"#";
    for(int i = 0; i < attributes.size(); i++)
    {
        schema<<attributes[i].first<<"#"<<attributes[i].second<<"#";
    }
    schema<<"\n";
    table.close();
    schema.close();





}