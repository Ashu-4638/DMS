#include<bits/stdc++.h>
using namespace std;
ifstream  schemas;
ofstream newschema;

string DROP(string tablename)
{
    cout<<tablename;
    string tables;
    schemas.open("db/schema.txt", ios :: in);
    newschema.open("db/temp.txt", ios :: out);
    int flag = 0;
    while (!(schemas.eof()))
    {
        getline(schemas, tables);
        cout<<tables<<endl;
        if(tables.find(tablename) != -1)
        {
            flag = 1;
            continue;
        }
        newschema<<tables;
    }
    newschema.close();
    schemas.close();
    if(flag == 1)
    {
        string file1 = "db/"+tablename+".txt";
        const char *dletb = file1.c_str();
        int status = remove(dletb);
        char file2[] = "db/schema.txt";
        int shcema = remove(file2);
        rename("db/temp.txt", "db/schema.txt");
        if(!status)
        {
            return "Table Deleted Successfully !";
        }
        else{
            return "Something went Wrong !";
        }

    }
    else
    return "Table Does Not Exists !";

    return "NULL";
}