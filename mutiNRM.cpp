#include <bits/stdc++.h>

#include <cmath>


using namespace std;
#define ld long double
#define ll long long 
#define rep(i, a, b) for (ll i = a; i < b; i++) // For loop macro





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

void solve (vector<vector<ld>> & a,vector < ld > & b, vector < ld > & x,vector<int> & p){

gauss_elimination(a,b,x,p);
back_substitution(a,b,x,p);



}



ld f_d(int i, int j,ld x1,ld x2, ld x3){


    if(i==0)
    return 1;




if(i==1 ){
    if(j==0)
    return  2*x1;
if(j==1)
    return  2*x2;


    return  2*x3;}

if(j==0)
    return  3*x1*x1;
if(j==1)
    return  3*x2*x2;

    return  3*x3*x3;
}


ld f1(ld x1,ld x2, ld x3){return -1.0*(x1+x2+x3 -0.3);}

ld f2(ld x1,ld x2, ld x3){return -1.0*(x1*x1 + x2*x2 + x3*x3 -0.03);}

ld f3(ld x1,ld x2, ld x3){return -1.0*(x1*x1*x1 + x2*x2*x2  + x3*x3*x3 -0.003);}



 ld epsilon(vector<ld> & err, vector<ld> & x){

ld a=0.0;

ld b=0.0;
rep(i,0,err.size())a+=err[i]*err[i];
rep(i,0,x.size())b+=x[i]*x[i];

return sqrt(a/b);


 }

void print_ld(vector<ld> &v){
rep(i,0,v.size()){
    cout<<v[i]<<" ";
}
cout<<endl;

}

 signed main(){

vector< ld> x = {0,0.2,10};

ld e=0.001;
vector<ld> b={f1(x[0],x[1],x[2]),f2(x[0],x[1],x[2]),f3(x[0],x[1],x[2])};

vector<vector<ld>> m(3,vector<ld>(3));
vector<int> p(3);
vector<ld> err (3,1e5);
int count=0;

while(count<1000 && epsilon(err,x) > e){
count++;

rep(i,0,3){
    rep(j,0,3){
  m[i][j]=f_d(i,j,x[0],x[1],x[2]);


    }
 
}

b={f1(x[0],x[1],x[2]),f2(x[0],x[1],x[2]),f3(x[0],x[1],x[2])};

rep(i,0,3)p[i]=i;
solve(m,b,err,p);

rep(i,0,3){
    x[i]=x[i]+err[i];
}


}


print_ld(b);

cout<<"this is x :"<<endl;
rep(i,0,3){cout<<x[i]<<" ";}
cout<<endl;





















 }
