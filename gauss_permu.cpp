#include <bits/stdc++.h>

#include <cmath>


using namespace std;
#define ld long double




void back_substitution(vector < vector < ld >> & a, vector < ld > & b, vector < ld > & x,vector<int> & p) {



    for (int i = b.size()-1; i >= 0; i--) {
        x[i] = b[p[i]];

        for (int j = b.size() - 1; j > i; j--) {

            x[i] = x[i] - a[p[i]][j] * x[j];



        }

        x[i] = x[i] / a[p[i]][i];


    }


}


int maxind(vector<vector<ld>> & a,int j,vector<int> & p){
    int ans=j;
    ld  m= a[p[j]][j];
for(int i=j;i<a[0].size();i++){
    
    if(fabs(a[p[i]][j])>fabs(m)){
        m=a[p[i]][j];
        ans=i;
    }
    
    
    
    
    
    
    
}
    
   return   ans;
    
    
}


void gauss_elimination(vector<vector<ld>> & a,vector < ld > & b, vector < ld > & x,vector<int> & p){
    
    
    
    
    
    for(int i=0;i<b.size();i++){
        
        int j=maxind(a,i,p);
        
        swap(p[i],p[j]);
        // swap(b[i],b[j]);
        ld d= a[p[i]][i];
        
      for(int q=i+1;q<b.size();q++){
          
          ld l= a[p[q]][i];
          
          
          for(int z=0;z<b.size();z++){
              
              a[p[q]][z]=a[p[q]][z]-((l*a[p[i]][z])/d);
              
          }
          b[p[q]]=b[p[q]]-((l*b[p[i]])/d);
          
          
          
          
          
      }
        
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
}











int main() {
    // your code goes here

    cout << "Enter the size of matrix :" << endl;
    int n;

cin>>n;
    vector < vector < ld >> a(n, vector < ld > (n, 0.0));

    vector < ld > b(n,0.0), x(n, 0.0);
    cout << "Enter augumented matrix :" << endl;
    for (int i = 0; i < n; i++) {



        for (int j = 0; j < n; j++) {

            cin >> a[i][j];


        }

        cin >> b[i];



    }
    vector<int>  p(n);
    for(int i=0;i<n;i++)p[i]=i;
    // for(int i=0;i<n;i++)cin>>b[i];
    

    // back_substitution(a, b, x);
    gauss_elimination(a,b,x,p);
  back_substitution(a, b, x,p);

    for (int i = 0; i < x.size(); i++) {

        cout << "x[" << i + 1 << "] = " << x[i] << endl;




    }




}