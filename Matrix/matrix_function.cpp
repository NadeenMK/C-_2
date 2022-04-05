/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void sumFunc(int m,int arr[][4]){
    int sum=0;
     for(int i=0 ;i<m;i++)
    for(int j=0 ;j<3 ;j++){
        sum+=arr[i][j];
    }
    cout<<" the sum is :"<<sum<<endl;
}
int maxFunc(int m,int arr[][4]){
    int max=arr[0][0];
    for(int i=0;i<m;i++)
    for(int j=0;j<3;j++)
    if(max<arr[i][j]){
         max=arr[i][j];
    }
    return max;
}
int minFunc(int m,int arr[][4]){
    int min=arr[0][0];
     for(int i=0;i<m;i++)
    for(int j=0;j<3;j++)
    if(min>arr[i][j]){
        min=arr[i][j];
    }
    return min;
}
    

int main()
{
    int n=2,sum=0;
    int m[n][4]={{2,3,0},{1,2,4}};
    sumFunc(n,m);
    cout<<" the max is :"<<endl;
    cout<<maxFunc(n,m)<<endl;
    cout<<" the min is :"<<endl;
    cout<<minFunc(n,m)<<endl;
    if(sizeof(m)>3){
        for(int i=0;i<4;i++){
            sum+=m[1][i];
        }
        cout<<"sum :" << sum <<endl;
    }
   if(n>2){
        for(int i=0;i<4;i++){
            sum+=m[1][i];
        }
        cout<< endl <<"sum "<< sum <<endl;
    }
    return 0;
}

