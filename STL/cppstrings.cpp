#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main ()
{
        //do random numbers, vectors,sets.
        int b = INT_MAX;
        string am;
        cin>>am;
        int a [8] = {1, 2, 3, 4, 5, 6, 7, 8};
        char d[] = {'d','a','f'};
        string m = "aman";
        string sub = m.substr(1,2);//ma
        m+='a';
        string gi = "ashray";
        if (m.compare(0,2,"apple") == 0);//first index and then no. of characters.
        swap(m,gi);
        char ara = m.at(1);
        cout<<ara;

        char tab2[1024];
        double doi = 2;
        float f = 3;
        strcpy(tab2, m.c_str());
        long long ama;
        string Text = "456";
        float Number;
        if ( ! (istringstream(Text) >> Number) ) Number = 0;
        cout<<Number;
        string g(tab2);
        cout<<"\n"<<g<<"\n";
        int l = m.length();
        sort(m.begin(),m.end()-2);
        sort(d,d+2);
        sort(a,a+8);
        for(int j=0;j<3;j++)
            cout<<d[j];
        for(int i=0;i<8;i++)
            cout<<a[i];
        string c;
        unsigned int Num = 123;
        double Numbe = 123.112;
        m.append("aman");
        string one("aman");
        string two = "amana";
        int ammm = (one==two);
        cout<<"\n"<<ammm;
        int noo = 123;
        //string conv =to_string(noo); In cpp11
        //string check = Numbe+"";       // number to be converted to a string
        string Result;         // string which will contain the result
        ostringstream convert;   // stream used for the conversion
        convert << Numbe;      // insert the textual representation of 'Number' in the characters in the stream
        Result = convert.str();
}