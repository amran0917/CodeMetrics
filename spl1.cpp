
## few erroe detection###



#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>


using namespace std;
string str,str1;

int linecounter=0;
int wcount=0;
int comment=0;
int  variablecount=0;
int countmethod = 0;

ifstream ifile;
ofstream ofile;

void  countMethod()
{
    bool flag = false;
    string s;
    string s1="";
    string temp;
    char ch;

    ifile.open("SPL_1.java");
	ofile.open("output.java");

    if(ifile.is_open())
    {

        while(getline(ifile,s))
        {



            int n = s.length();
            temp = s;
            char arr[n];

            for(int j=0;j<s.length();j++)
            {
               if(s[j]=='('&&s[s.length()-1]!=';'){
                cout<<s<<endl;
                                   countmethod++;

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
               }
            }

            s=arr;
            istringstream iss(s);

            int len=0;

            while(iss>>s){


                    len++;
           }


            if((len==2||len==3)&&ch=='(' && temp[n-1]!=';')
            {
                   // cout<<"this is method"<<endl;
                   //countmethod++;
            }

            else
            {
              flag = false;
                //cout<<"haire gada" << endl;
           }

            ch=' ';

        }

    }
    if (flag) cout<<"haire gada" << endl;
    else cout<< "Hey Number Of Method in here " << countmethod<<endl;


    ifile.close();

}



 int countPrimitiveVariable(string &str)
 {

   istringstream iss;
   iss.str(str);
   string value,s;

    for(int j=0;j<str.length();j++)
    {
            iss>>value;

            if(value=="int" || value=="char" || value=="float" || value=="double" || value=="boolean"   || value == "byte" || value=="short"|| value=="long")
            {
                    s = value;
                    iss>>value;
                    for(int i=0;i<value.length();i++)
                    {
                        if(value[i]==',' || value[i]==';' ) variablecount++;

                    }
            }


    }

    return variablecount;
 }


void countCommentlineNumber()
 {

    ifile.open("SPL_1.java");
    ofile.open("output.java");

    while(getline(ifile,str))
    {

        if(ifile.is_open())
        {

            for(int i=0;i<str.length();i++)
            {
                if(str[i]=='/' && str[i+1]=='/')
                {
                        comment++;
                        break;

                }
            }

            for(int i=0;i<str.length()-2;i++)
            {

                 if(str[i]=='/' && str[i+1]=='*')
                {
                    comment++;
                    bool fl=false;
                    while((getline(ifile,str1)))
                    {

                        for(int j=0;j<str1.length()-2;j++)
                        {
                                if(str1[j]=='*' && str1[j+1]=='/')
                                {
                                        fl=true;
                                        break;
                                }
                         }

                        if(fl==true) break;
                        comment++;
                     }

                        break;
                }
            }

        }
    }
    //return comment;
   // cout << comment << endl;
        ofile<<"Total commentLine Number: " << (comment-1)<<endl;
 }

int withoutBlankLinecount(string &str)
{


    if(str.length()==0) wcount++;
          /*  int length = str.length();
            cout<< length<<endl;
            wcount++;
            for (int i = 0; i < length; i++) {
                if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ') {
                    wcount--;
                    break;
                }
            }*/

            return wcount;
}

int countTotalLineOfCode(string &str)
{

			linecounter++;

			return linecounter;
}


void openfile()
{

	ifile.open("SPL_1.java");
	ofile.open("output.java");

    // countCommentlineNumber();


	if(ifile.is_open())
	{


		while(getline(ifile,str))
		{
            countTotalLineOfCode(str);

            withoutBlankLinecount(str);

           countPrimitiveVariable(str);
          // countMethod(str);
           //countCommentlineNumber();

        }
           /* ofile<<"Blank line of code :"<<wcount<<endl;
            ofile<<"Total line of code: "<< linecounter<<endl;
            ofile<<"Exact line without blank line : " << (linecounter-wcount)<<endl;
			// ofile<<"Comment line of code: "<< comment<<endl;
            ofile<<"Number of primitive variable: " << variablecount<<endl;*/


	}

	else
	{
		cout<<"U can't open file"<<endl;
	}
	ifile.close();
}



int main()
{
	openfile();
	//countCommentlineNumber();
	countMethod();


	return 0;
}
