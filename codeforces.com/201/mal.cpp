// Written by HadronWave 
// P.S. Contains too many bugs.

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
//-I\O-------------

#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
//-C-libraries------

#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
//-Structs-----------

#include <algorithm>
#include <functional>
//-Other-------------

using namespace std;
//-Using-------------


typedef long long ll;
typedef pair<double,double> prd;
typedef pair<int,int> pr;
//-Typedefs----------


#define double long double
//-Define------------

const ll mod7 = 1000000007;
const ll mod9 = 1000000009;
const int linf = 2000000000;
const ll llinf = 1000000000000000000ll;
//-Const-------------

ifstream in("input.txt");
ofstream out("output.txt");
//-File-I/O----------

struct back{
    int i,j,k;
    back(){
        i=j=k=-1;
    }
    back(int i,int j,int k):i(i),j(j),k(k){}
    bool operator==(const back &a){
        return( a.i==i && a.j==j && a.k==k);
    }
};

int dp[101][101][101];
back p[101][101][101];

int Automat[101][26];

int prefix[101];

void PrefixFunc(string &s){
    int l = s.length();
    for(int i=1;i<l;++i){
        int k = prefix[i-1];
        while(k && s[i]!=s[k]){
           k = prefix[k-1];
        }
        if(s[i]==s[k])
            ++k;
        prefix[i] = k;
    }
    for(int i=0;i<l;++i){
        for(int j=0;j<26;++j){
            char x = (char)(j+'A');
            if(i && x!=s[i]){
                Automat[i][j] = Automat[prefix[i-1]][j];
            }else{
                Automat[i][j] = i+(x==s[i]);
            }
        }
    }
    
}


int main(){
    string s[3];
    int l[3];

    for(int i=0;i<3;++i){
        cin >> s[i];
        l[i] = s[i].length();
    }

    PrefixFunc(s[2]);

    dp[0][0][0] = 0;
    back bad = back(-1,-1,-1);

    int ans = 0;
    back Ans;
    
    for(int i=0;i<l[0];++i){
        
        for(int j=0;j<l[1];++j){
            
            for(int k=0;k<l[2];++k){
                
                bool add = (s[0][i]==s[1][j]);

                int go = s[0][i]-'A';
                int next = Automat[k][go];
                
                if(add && next<l[2]){
                    if(dp[i+1][j+1][next]<dp[i][j][k]+1){
                        dp[i+1][j+1][next] = dp[i][j][k]+1;
                        p[i+1][j+1][next] = back(i,j,k);
                    }
                }
                
                if(dp[i][j][k]>dp[i+1][j][k]){
                   dp[i+1][j][k] = dp[i][j][k];
                   p[i+1][j][k] = p[i][j][k];
                }
                if(dp[i][j][k]>dp[i][j+1][k]){
                   dp[i][j+1][k] = dp[i][j][k];
                   p[i][j+1][k] = p[i][j][k];
                }
                
                if(ans<dp[i][j][k]){
                    ans = dp[i][j][k];
                    Ans = p[i][j][k];
                }
            }
        }
    }
    
    for(int i=0;i<=l[0];++i)
        for(int j=0;j<=l[1];++j)
            for(int k=0;k<l[2];++k)
                if(ans<dp[i][j][k]){
                    ans = dp[i][j][k];
                    Ans = p[i][j][k];
                }
    
    
    string res = "";
    
    do{
        if(Ans==bad) break;
        res += s[0][Ans.i];
        Ans = p[Ans.i][Ans.j][Ans.k];
        if(Ans==bad) break;
    }while(true);
    
    reverse(res.begin(),res.end());
    
    if(res=="")
        cout << 0;
    else
        cout << res;
    
    return 0;
}
