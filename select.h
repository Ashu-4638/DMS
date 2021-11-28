#include<bits/stdc++.h>
using namespace std;

 
ifstream schemas2;

void SELECT(string table1, string table2 = "", vector<string>attributes = {}, string condition = "")
{
    string tables;
    schemas2.open("db/schema.txt", ios :: in);
    if(table2.length() > 0)
    {
        cout<<"JOIN"<<endl;
    }
    else{
        string table;
        while (!(schemas2.eof()))
        {
            getline(schemas, tables);
            if(tables.find(table1) != -1)
            {
                table = tables;
                break;
            }
            else{
                cout<<"No such Table !"<<endl;
                return ;
            }
            
        }
        unordered_map<string, int> mp;
        string temp = "";
        int count = 0;
        for(int i = 0; i < table.length(); i++)
        {
            if(table[i] == '#')
            {
                mp[temp] = count++;
                temp = "";
            }
        }
        unordered_map<string, int> attr;
        for(auto at : attributes)
        {
            attr[at] = mp[at];
        }
        ifstream tb;
        tb.open("db/"+table+".txt");
        string value;
        for(auto at : attributes)
        {
            cout<<at<<" \t \t ";
        }cout<<endl;
        while (!(tb.eof()))
        {
            getline(tb, value);
            vector<string>values;
            string demo = "";
            for(int i = 0; i < value.length(); i++)
            {
                if(value[i] == '#')
                {
                    values.push_back(demo);
                    demo = "";
                }
            }
            for(auto table_value : attr)
            {
                cout<<values[table_value.second - 1];
            }
            
        }
    }
    return;
}