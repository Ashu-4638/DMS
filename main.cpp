#include<bits/stdc++.h>
#include "create.h"
using namespace std;


int main()
{
    string query;
    getline(cin, query);
    vector<string> command;
    vector<pair<string, string>> attributes;
    if(query.find("create table") != -1)
    {
        string str = "";
        for(int i = 0; i < query.length(); i++)
        {
            if(query[i] == ' ')
            {
                
                command.push_back(str);
                str = "";
            }
            else if(query[i] == '(' || query[i]==')' || query[i] == ';' || query[i] == ',')
            {
                continue;
            }
            else{
                str += query[i];
            }


        }
        command.push_back(str);
        
        for(int i = 3; i < command.size(); i+=2)
        {
            pair<string, string> p;
            p.first = command[i];
            p.second= command[i + 1];
            attributes.push_back(p);
        }
    }
    CREATE(command[2], attributes);
    for(int i = 0; i < attributes.size(); i++)
    {
        cout<<attributes[i].first<<" "<<attributes[i].second<<endl;

    }


    return 0;
}