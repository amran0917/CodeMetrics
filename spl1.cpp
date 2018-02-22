#include<bits/stdc++.h>

using namespace std;
string str;

int linecounter=0;
 int wcount=0;
 int comment=0;
int  variablecount=0;

 int countVariable(string &str)
 {
     for(int j=0;j<str.length();j++)
     {
     //    if(str=="int" || str="char" || str=="float" || str=="double" || str="string")
         {
             if(str[j+1]==',' || str[j+1]==';')
             {
                 variablecount++;
             }
         }
     }

     cout<<variablecount<<endl;
 }
int countCommentlineNumber(string &str)
 {
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='/'|| (str[i]=='/*' && str[i]=='*/')) comment++;
        else break;
    }

    return comment;
 }

int withoutBlankLinecount(string &str)
{
    for(int j=0;j<str.length();j++)
    {
        if( str[j]==' ' && str[j+1]=='\n') wcount++;
    }
    return wcount;
 //   if(str==' ' && str=='\n') wcount++
           // if (str.length()==0) wcount++;


}

int countTotalLineOfCode(string &str)
{

			linecounter++;

			return linecounter;
}


void openfile()
{
	ifstream ifile;
	ifile.open("spl1-source.java");


	if(ifile.is_open())
	{


		while(getline(ifile,str))
		{
            countTotalLineOfCode(str);

            withoutBlankLinecount(str);
            countCommentlineNumber(str);
            countVariable(str);

        }
            cout<<"Blank line of code :"<<wcount<<endl;
			cout<<"Total line of code: "<< linecounter<<endl;

			cout<<"Exact line without blank line : " << (linecounter-wcount)<<endl;
			cout<<"Comment line of code: "<< comment<<endl;

	}

	else
	{
		cout<<"U can't open file"<<endl;
	}
}



int main()
{
	openfile();

	return 0;
}
