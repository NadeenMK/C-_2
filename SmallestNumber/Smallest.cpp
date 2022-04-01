/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include "smalleslib.h"

using namespace std;

int main()
{
    fromThisFile();
    int n,m;
    cout<<" enter the size of p :"<<endl;
    cin>>n;
    cout<<" enter the size of q :"<<endl;
    cin>>m;
    int*p=new int [n];
    double*q=new double [m];

    for(int i=0 ;i<n; i++){
        cout<<" enter the p [ "<<i<<" ] :"<<endl;
        cin>>p[i];
    }
     for(int i=0 ;i<m; i++){
        cout<<" enter the q [ "<<i<<" ] :"<<endl;
        cin>>q[i];
    }
     cout<<smalLest(p) << endl;
     cout<<smalLest(q) << endl;




    system("pause");
    return 0;
}
