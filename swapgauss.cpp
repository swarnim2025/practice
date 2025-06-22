#include <bits/stdc++.h>

#include <cmath>


using namespace std;
#define ld long double




void back_substitution(vector < vector < ld >> & a, vector < ld > & b, vector < ld > & x) {



    for (int i = b.size()-1; i >= 0; i--) {
        x[i] = b[i];

        for (int j = b.size() - 1; j > i; j--) {

            x[i] = x[i] - a[i][j] * x[j];



        }

        x[i] = x[i] / a[i][i];


    }


}


int maxind(vector<vector<ld>> & a,int j){
    int ans=j;
    ld  m= a[j][j];
for(int i=j;i<a[0].size();i++){
    
    if(fabs(a[i][j])>fabs(m)){
        m=a[i][j];
        ans=i;
    }
    
    
    
    
    
    
    
}
    
   return   ans;
    
    
}


void gauss_elimination(vector<vector<ld>> & a,vector < ld > & b, vector < ld > & x){
    
    
    
    
    
    for(int i=0;i<b.size();i++){
        
        int j=maxind(a,i);
        
        swap(a[i],a[j]);
        swap(b[i],b[j]);
        ld d= a[i][i];
        
      for(int q=i+1;q<b.size();q++){
          
          ld l= a[q][i];
          
          
          for(int z=0;z<b.size();z++){
              
              a[q][z]=a[q][z]-((l*a[i][z])/d);
              
          }
          b[q]=b[q]-((l*b[i])/d);
          
          
          
          
          
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
    // for(int i=0;i<n;i++)cin>>b[i];
    

    // back_substitution(a, b, x);
    gauss_elimination(a,b,x);
  back_substitution(a, b, x);
cout<<fixed <<setprecision(12);
    for (int i = 0; i < x.size(); i++) {

        cout << "x[" << i + 1 << "] = " << x[i] << endl;




    }




}