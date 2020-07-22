#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
         int res=0;
        int n,k;
        cin>>n>>k;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        
        map<int,int>m;
               
       
        
         for(int i=0;i<n;i++){
         	m[A[i]]++;
    }
    
      for(int i=0;i<n;i++){
      	if(m[A[i]] != k)
      	cout<<A[i]<<endl;
    }
    
        
        
    }
    
}
