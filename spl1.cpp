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

/*void countCoupling()
{

       int countCu=0;
      ifile.open("Student.java");
     // ofile.open("output.java");

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

     cout<< "The number OF coupling is:" << countCu << endl;


}*/

void countParameter()
{
     ifile.open("SPL.java");
	//ofile.open("output.java");

	int flag=0;

	int countl=0;
	string s;


	if(ifile.is_open())
    {
		
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
	cout<<"Parameter Number: " << countl << endl;
    ifile.close();

}
void  countMethod()
{
    bool flag = false;
    string s;
    string s1="";
    string temp;
    char ch;
    int x=0;

    ifile.open("SPL.java");
    //ofile.open("Output.java");    

    if(ifile.is_open())
    {

        while(getline(ifile,s))
        {

            int n = s.length();
            //cout<<"strlength "<<n<<endl;
            
          
       //custom method
    
            for(int j=0; j<s.length()-1; j++)  
            {
               if(s[j]=='(' && s [s.length()-1]==';')
               {
               		 //cout<<s<<endl;
               		
                     countmethod++;

               }
            }



	    //...custom method count
	    
	    //default method..
	    
	      if(s.length()>5){

		for(int i=0; i<s.length()-5; i++){
		
			if(s[i]=='f'&&s[i+1]=='o'&&s[i+2]=='r')
			{
			    //cout<<s<<endl;
			    countExtraDefault++;
			   // cout<<"for"<<endl;
			}	
			
			else if(s[i]=='w'&&s[i+1]=='h'&&s[i+2]=='i'&&s[i+3]=='l'&&s[i+4]=='e')
			{
			   // cout<<s<<endl;
			    countExtraDefault++;
			     // cout<<"while"<<endl;
			}	
			
			else if(s[i]=='d'&&s[i+1]=='o'&&s[i+2]!='u')
			{
			
			   // cout<<s<<endl;
			    countExtraDefault++;
			  
			     // cout<<"do"<<endl;
			}	
			
			else if(s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='i'&&s[i+3]=='n')
			{
			    //cout<<s<<endl;
			    countExtraDefault++;
			     // cout<<"main"<<endl;
			}
			
			else if(s[i]=='.'&&s[i+1]=='o'&&s[i+2]=='u'&&s[i+3]=='t'&&s[i+4]=='.')
			{
			    //cout<<s<<endl;
			     x=x+1;
			    // cout<<"println"<<endl;
			}
			
			
				
		   }
		}
	    //default method..
	   
	   	
  

   
    
    }
    }
    ifile.close();
    
     cout<<"total method: "<< countmethod+countExtraDefault<<endl;
    // cout<<"custom method: "<<countmethod<<endl;

}

void countvariable()

{
   	ifstream ifile ;
	ofstream ofile;
    ifile.open("SPL.java");
	//ofile.open("Output.java");
    string s;
    istringstream iss;
    int countv=0,flag=0;
    int i,j;

    if(ifile.is_open())
    {
        while(getline(ifile,s))
        {
            iss >> s;
			flag=0;

            int n = s.length();
            char charArr[n+1];
            char charArr2[n+1];
            char charArr3[n+1];

            strcpy(charArr,s.c_str());

            for(i=0;i<n;i++)
			{

                if((charArr[i] >= 65 && charArr[i]<=90 ) || (charArr[i] >= 97 && charArr[i]<=122 )){
                    break;
                }
            }

            for(j=0;i<=n;i++,j++)
			{
                charArr2[j] = charArr[i];
            }

            for(i=0,j=0;i<=n;i++){
               if(charArr[i]==' ')continue;
               else
				{    
					charArr3[j]=charArr[i];
                	j++;
               }
            }

            for(j=0;charArr3[j]!='\0';j++){

                if(charArr3[j] == '=' && charArr3[j+1]!='='){
                    if(j+3 < strlen(charArr3)){
                        if(charArr3[j+1]=='n' && charArr3[j+2]=='e' && charArr3[j+3]=='w'){
                            countv++;
							//cout << charArr << endl;
                        }

                    }
                }
            }

			
            char *p = strtok(charArr2," ");

            while(p){
                
				
                if(!strcmp("int",p) || !strcmp("double",p) || !strcmp("float",p) || !strcmp("boolean",p) || !strcmp("char",p) || !strcmp	("String",p) || !strcmp("byte",p)){
                    flag=1;

                }


                char *q=p;
                int i=0;

                if(flag == 1){

					for(i=0;i<n;i++){

						if(charArr[i]==';'){
							
                			flag=2;
							
						}
					}
				}
				if(flag==2){

		             while(q[i]){

		                 if(q[i]==',')
						{
							
								countv++;
								//cout << charArr << endl;	
		                 		flag=3;
							

		                }

		                i++;
		            }
				}
                p = strtok(NULL," ");
            }

            if(flag==2) {

				for(i=0;i<n;i++){

					if(charArr[i]==';'){
						countv++;
						//cout << charArr << endl;
                
					}
				}
				flag=0;    
            }
            else if(flag==3) {
                countv++;
				//cout << charArr << endl;
                flag=0;
            }

        }

		//if(countv) ofile << "Total Variable number : "<<countv<< endl;

		

    }
	cout << "Total Variable number : "<<countv<< endl;
	ifile.close();
	

}


void countCommentlineNumber()
 {
	int flag=0;
	int comment1=0;
	string s;

    ifile.open("SPL.java");
	//ofile.open("Output.java");

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
					flag=1;
					break;
                }

                else if(s[i]=='*' && s[i+1]=='/' && flag == 1)
                {
                    comment1++;
                    //cout << s << endl;
					flag=0;
					break;
                }

            }

			if(flag==1) {
			    //cout << s << endl;
                comment1++;
			}
        }
    }

        cout<<"Total commentLine Number: " << comment1<<endl;
	   //ofile<<"Totlal commentLine Number: " << comment1<<endl;

	ifile.close();
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

	 ifile.open("Student.java");
	//ofile.open("output.java");

     countCommentlineNumber();


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
          //  cout<<"Blank line of code :"<<wcount<<endl;
           cout<<"Total line of code: "<< linecounter<<endl;
           // cout<<"Exact line without blank line : " << (linecounter-wcount)<<endl;
			// ofile<<"Comment line of code: "<< comment<<endl;
            //ofile<<"Number of primitive variable: " << variablecount<<endl;*/


	}

	else
	{
		cout<<"U can't open file"<<endl;
	}
	ifile.close();
}



int main()
{

	countvariable();
	countParameter();
	//openfile();
	//countCommentlineNumber();
	countMethod();
	
	
	



	return 0;
}
