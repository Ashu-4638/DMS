#include<bits/stdc++.h>
#include "create.h"
#include "insert.h"
#include "drop.h"
#include "helptable.h"
#include "select.h"
using namespace std;


int main()
{
    while(1)
    {
            cout<<"\nMySQL> ";
            string query;
            vector<string> command;
            vector<pair<string, string>> attributes;
            vector<string> values;
            getline(cin, query);
            if(query.find("create table") != -1)
            {
                string str = "";
                for(int i = 0; i < query.length(); i++)
                {
                    if(query[i] == ' ')
                    {
                        if(str.length() > 0)
                        command.push_back(str);
                        str = "";
                    }
                    else if(query[i] == '(' ||  query[i]==')' || query[i] == ';' || query[i] == ',')
                    {
                    if(str.length() > 0)
                        command.push_back(str);
                        str = "";
                    }
                    else{
                        str += query[i];
                    }


                }
                            
                vector<string> tbs = HELP_TABLES();
                bool flag  = false;
                for(auto tb : tbs)
                {
                    if(tb.compare(command[2]) == 0)
                    {
                        flag = true;
                    }
                }
                if(flag)
                cout<<"\n Table with this name already exists !"<<endl;
                else
                CREATE(command[2], attributes);
                
                for(int i = 3; i < command.size(); i+=2)
                {
                    cout<<command[i]<<endl;
                    pair<string, string> p;
                    p.first = command[i];
                    p.second= command[i + 1];
                    attributes.push_back(p);
                }
            }
            else if(query.find("insert into") != -1)
            {
                string str = "";
                for(int i = 0; i < query.length(); i++)
                {
                    if(query[i] == ' ')
                    {
                        if(str.length() > 0)
                        values.push_back(str);
                        str = "";
                    }
                    else if(query[i] == '(' || query[i]==')' || query[i] == ';' || query[i] == ',' || query[i] == '\'')
                    {
                        if(str.length() > 0)
                        {
                            values.push_back(str);
                            
                        }
                        str = "";
                        
                    }
                    else{
                        str += query[i];
                    }
                }
                INSERT(values[2], values);
            }
            else if(query.find("drop") != -1)
            {
                string comm = "";
                for (int i = 0; i < query.length(); i++)
                {
                    if(query[i] == ' ' || query[i] == ';')
                    {
                        command.push_back(comm);
                        comm = "";
                        continue;
                    }
                    comm += query[i];
                }
                 vector<string> tbs = HELP_TABLES();
                bool flag  = false;
                for(auto tb : tbs)
                {
                    if(tb.compare(command[2]) == 0)
                    {
                        flag = true;
                    }
                }
                if(flag)
                cout<<DROP(command[2]);
                else
                cout<<"\n Table does not exists !"<<endl;
                
            }
            else if(query.find("help table") != -1)
            {
                vector<string> tbs =   HELP_TABLES();
                for(auto tb : tbs)
                {
                    cout<<tb<<endl;
                }
            }
            else if(query.find("quit") != -1)
            {
                exit(0);
            }
            else if(query.find("select") != -1)
            {
                string str = "";
                for(int i = 0; i < query.length(); i++)
                {
                    if(query[i] == ' ')
                    {
                        if(str.length() > 0)
                        values.push_back(str);
                        str = "";
                    }
                    else if(query[i] == '(' || query[i]==')' || query[i] == ';' || query[i] == ',' || query[i] == '\'')
                    {
                        if(str.length() > 0)
                        {
                            values.push_back(str);
                            
                        }
                        str = "";
                        
                    }
                    else{
                        str += query[i];
                    }
                }
                string tbl = values[0];
                command.clear();
                int j = 0;
                while(tbl != "from")
                {
                    j++;
                    tbl = values[j];
                    command.push_back(tbl);
                }
                tbl = values[j + 1];
                SELECT(tbl,"", command, "");

            }
            // for(int i = 0; i < attributes.size(); i++)
            // {
            //     cout<<attributes[i].first<<" "<<attributes[i].second<<endl;

            // }
            // for(int i = 0; i < values.size(); i++)
            // {
            //     cout<<values[i]<<" ";
            // }


    }
    

    return 0;
}