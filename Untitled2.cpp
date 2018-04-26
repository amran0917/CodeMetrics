#include <bits/stdc++.h>

using namespace std;

int main()

{

    int countl=0;
    string s;
    getline(cin,s);

    for(int i=0;i<s.length();i++)
    {

        if(s[i]=='(')
        {

            for(int j=i;j<s.length();j++)
            {

               if (s[j]==',') countl++;

            }
        }

    }

      if(countl==0) cout<<countl<< endl;
      else cout<<countl+1<< endl;
      return 0;
}
