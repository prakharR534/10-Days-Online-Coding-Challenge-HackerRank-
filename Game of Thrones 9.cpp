#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string commonPrefixUtil(string str1, string str2) 
{ 
    string result; 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Compare str1 and str2 
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
    { 
        if (str1[i] != str2[j]) 
            break; 
        result.push_back(str1[i]); 
    } 
  
    return (result); 
} 







string commonPrefix (string A[], int n) 
{ 
    string prefix =  A[0]; 
  
    for (int i=1; i<=n-1; i++) 
        prefix = commonPrefixUtil(prefix, A[i]); 
  
    return (prefix); 
} 


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    string ans = commonPrefix(A, n); 
  
    if (ans.length()) 
        printf ("%s", 
                 ans.c_str()); 
    else
        printf(""); 
    
    
    return 0;
}
