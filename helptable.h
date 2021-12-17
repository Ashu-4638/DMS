#include<bits/stdc++.h>
using namespace std;
ifstream table_schema;
vector<string> HELP_TABLES()
{
    vector<string> tbs;
    table_schema.open("db/schema.txt", ios :: in);
    string tables;
    while (!(table_schema.eof()))
    {

        getline(table_schema, tables);
        cout<<tables<<endl;
        int loc =tables.find_first_of('#');
        tbs.push_back(tables.substr(0, loc));
    }
    table_schema.close();
    return tbs;
}