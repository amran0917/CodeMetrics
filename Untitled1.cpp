#include<bits/stdc++.h>

using namespace std;


int main ()
{
    string s;
    string s1="";
    string temp;
    char ch;


    getline(cin,s);
    int n = s.length();
    char arr[n];

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('){

            ch=s[i];

            break;
        }
        else
        {
            arr[i]=s[i];
        }


    }
    s=arr;
    istringstream iss(s);



    //cout<<s<<endl;
    int len=0;

    while(iss>>s){
                    temp = s;
       // if(temp=="public" || temp== "private" || temp == "protected")
           len++;

    }
    cout<<len<<endl;

    if((len==2||len==3)&&ch=='(' && s[n-1]!=';'){
        cout<<"this is method"<<endl;
    }

    else{
        cout<<"haire gada" << endl;
    }



    return 0;
}
