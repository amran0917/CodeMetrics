#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>


using namespace std;
string str;

int linecounter=0;
int wcount=0;

int  variablecount=0;
int countmethod = 0;
int countCustomMethod = 0, countExtraDefault = 0;
int doCount=0;

ifstream ifile;
ofstream ofile;

void countCoupling()
{

        int countCu=0;
      ifile.open("SPL_1.java");
      ofile.open("output.java");

      if(ifile.is_open())
    {

        while(getline(ifile,str))
        {
            int len = str.length();

            for(int i=0;i<len;i++)
            {
                if(str[i]=='.')// && str[len-1]==';')
                {
                        countCu++;


                }
            }
        }

    }
     ifile.close();

  //   cout<< "The number OF coupling is:" << countCu << endl;


}

 //****  Parameter ****####/// 


void countParameter()
{
    ifile.open("E:\\My File\\spl\\SPL_1.java");
	//ofile.open("output.java");

	int flag=0;

	int countl=0;
	string s;


	if(ifile.is_open())
    {
		//cout << "dsgsdg" << endl;
        while(getline(ifile,s))
        {

            for(int i=0;i<s.length();i++)
            {
               if(s[i]=='('  && s[i+1] != ')'&& s[s.length()-1]!=';'){

					//cout << s <<endl;

					for(int j=i+1; j<s.length()-1; j++)
					{
						if(s[j]==','){
							countl++;
							flag=1;
						}
					}
					if(flag == 1) {
						countl++;
						flag=0;
					}
					else{
						countl++;
					}
				}

           }

        }
    }

    //if(countl==0 && flag==1) cout<<countl<< endl;
    //else if (flag==0) cout<<countl+1<< endl;
	cout<<countl;
    ifile.close();

}


/* method count*/


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
		//cout << "hoise " << endl;
        while(getline(ifile,s))
        {

            int n = s.length();
           // cout<<"strlength "<<n<<endl;

            temp = s;
            char arr[n];

            for(int j=0;j<s.length()-1;j++)
            {
               if(s[j]=='('&&s[s.length()-2]==';')
               {
               		 cout<<s<<endl;
               		 cout<<"gghfgdtdyh"<<s.length()<<endl;
                     countmethod++;

               }
            }



	    //...custom method count


		for(int i=0; i<s.length()-1; i++){
			 if(s[i]=='('&&s[s.length()-2]!=';'){
               		// cout<<s<<endl;
                    countCustomMethod++;
                    break;

               }
		}


        if(s.length()>=5){

		for(int i=0; i<s.length()-5; i++){

			if(s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='r')
			{
			    cout<<s<<endl;
			    countExtraDefault++;
			   // cout<<"for"<<endl;
			}

			else if(s[i]=='w'&&s[i+1]=='h'&&s[i+2]=='i'&&s[i+3]=='l'&&s[i+4]=='e')
			{
			    cout<<s<<endl;
			    countExtraDefault++;
			     // cout<<"while"<<endl;
			}

			else if(s[i]=='d'&&s[i+1]=='o'&&s[i+2]!='u')
			{

			    cout<<s<<endl;
			    countExtraDefault++;

			     // cout<<"do"<<endl;
			}

			else if(s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='i'&&s[i+3]=='n')
			{
			    cout<<s<<endl;
			    countExtraDefault++;
			     // cout<<"main"<<endl;
			}


		}
		}



    }




    }
    ifile.close();

     cout<<"total method: "<< countmethod + countExtraDefault <<endl;
     cout<<"custom method"<<countCustomMethod - countExtraDefault<<endl;

}


 void countvariable()

{
  ifstream ifile ;
    ifile.open("SPL_1.java");
    string s;
    istringstream iss;
    int countv=0,flag=0;
    int i,j;

    if(ifile.is_open())
    {
        while(getline(ifile,s))
        {
            iss >> s;

            int n = s.length();
            char charArr[n+1];
            char charArr2[n+1];
            char charArr3[n+1];

            strcpy(charArr,s.c_str());

            for(i=0;i<n;i++){

                if((charArr[i] >= 65 && charArr[i]<=90 ) || (charArr[i] >= 97 && charArr[i]<=122 )){
                    break;
                }
            }
            for(j=0;i<=n;i++,j++){
                charArr2[j] = charArr[i];

            }

            for(i=0,j=0;i<=n;i++){
               if(charArr[i]==' ')continue;
               else{
                charArr3[j]=charArr[i];
                j++;
               }

            }
            for(j=0;charArr3[j]!='\0';j++){

                if(charArr3[j] == '=' && charArr3[j+1]!='='){
                    if(j+3 < strlen(charArr3)){
                        if(charArr3[j+1]=='n' && charArr3[j+2]=='e' && charArr3[j+3]=='w'){
                            countv++;
                        }

                    }
                }
            }



            cout << charArr << endl;
            cout << charArr2 << endl;
            cout << charArr3 << endl;

            char *p = strtok(charArr2," ");

            while(p){
                //cout << p <<" - ";

                if(!strcmp("int",p) || !strcmp("double",p) || !strcmp("float",p) || !strcmp("boolean",p) || !strcmp("char",p) || !strcmp("String",p) || !strcmp("byte",p) ){
                    flag=1;


                }
                char *q=p;
                int i=0;

                if(flag == 1){
                    while(q[i]){

                        if(q[i]==','){
                            countv++;
                            flag=2;

                        }
                        i++;
                    }
                }
                p = strtok(NULL," ");
            }
            cout <<  endl;

            if(flag==1) {
                countv++;
                flag=0;
            }
            else if(flag==2) {
                countv++;
                flag=0;
            }

        }
                        // if(s[i]=='=' && s[i+1]!= '=') countv++;

        if(countv) cout << countv<< endl;


    }




}
/* int countPrimitiveVariable(string &str)
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
 */


void countCommentlineNumber()
 {
	int flag=0;
	int comment1=0;
	string s;

    ifile.open("SPL_1.java");
    ofile.open("output.java");



	if(ifile.is_open())
	{
		while(getline(ifile,s))
		{
            int len=s.length()-1;

            for(int i=0;i<len;i++)
            {

                if((s[i]=='/') && (s[i+1]=='/') && flag != 1)
                {
						//cout << s << endl;
                        comment1++;
                        break;
                }
                else if(s[i]=='/' && s[i+1]=='*')
                {
                	//cout << s << endl;
                    //comment1++;
			
			flag=1;
			break;
                }

                else if(s[i]=='*' && s[i+1]=='/' && flag == 1)
                {
                    if(i ==0 || i ==1 || i ==2){

                        flag=0;
                        break;
                    }
                    comment1++;
                    //cout << s << endl;
					flag=0;
					break;
                }

            }

		if(flag==1) 
		{
			    //cout << s <<endl;
                	comment1++;
		}
        }
    }

        cout<<"Total commentLine Number: " << comment1<<endl;
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

//****** LineCount *****//

int countTotalLineOfCode(string &str)
{

			linecounter++;

			return linecounter;
}

// **** file open ***** //

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

          // countPrimitiveVariable(str);
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
	//openfile();
	countCommentlineNumber();
	//countMethod();
	//countParameter();
	//countCoupling();
	//countvariable();


	return 0;
}
