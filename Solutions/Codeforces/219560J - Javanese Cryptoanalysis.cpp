#include <bits/stdc++.h>
using namespace std;


string fr;
map<int,int> dic; // (esq) - dir
map<int,int> dic2;// esq - (dir)
char ans[123456];




int ehvogal(int a){
  if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a  == 'U') return -50;
  return 50;
}


bool nextVogal(char &v){
  if(!dic2.count('A')) return (v = 'A');
  if(!dic2.count('E')) return (v = 'E');
  if(!dic2.count('I')) return (v = 'I');
  if(!dic2.count('O')) return (v = 'O');
  if(!dic2.count('U')) return (v = 'U');
  return false;
}

bool nextConsoante(char &v){
  for(int i = 'A' ; i <= 'Z' ; ++i){
    if(ehvogal(i) > 0){
      if(!dic2.count(i)) return (v = i);
    }
  }
  return false;
}



int F(int idx,int ant){  // ant < 0 .: vogal... ant > 0 .: consoante ... ant == 0 espaco!!!!!!!!

  // cout << idx;
  // printf("%s\n",ans);

  if(idx >= (int)fr.size())
  {
    printf("%s\n",ans);
    exit(0);
    return true;
  }

  if(fr[idx] == ' ' || fr[idx] == '\n')
  {
    ans[idx] = fr[idx];
    return F(idx+1, 0 );
  }

  if( dic.count( fr[idx] ) )
  {
    if((ant < 0 && ehvogal( dic[fr[idx]] ) < 0 ) || (ant > 0 && ehvogal( dic[fr[idx]] ) > 0) ) return false;
    ans[idx] = dic[ fr[idx] ];

    return F(idx+1,ehvogal( dic[ fr[idx] ] ));
  }


  if(ant == 0){
    char B;
    if(nextVogal(B)){
      ans[idx] = B;
      dic[ fr[idx] ] = B,dic2[ B ] = fr[idx];
      if(F(idx+1,-50)) return true;
      dic.erase( fr[idx] ),dic2.erase( B );
    }

    if(nextConsoante(B)){
      ans[idx] = B;
      dic[ fr[idx] ] = B,dic2[ B ] = fr[idx];
      if(F(idx+1,50)) return true;
      dic.erase( fr[idx] ),dic2.erase( B );
    }

    return false;
  }


  if(ant > 0){ //consoante
    char B;
    if(nextVogal(B)){
      ans[idx] = B;
      dic[ fr[idx] ] = B;
      dic2[ B ] = fr[idx];
      if(F(idx+1,-50)){
        return true;
      }
      dic.erase( fr[idx] ); // desmapeia
      dic2.erase( B );
    }

    return false;
  }

  if(ant < 0){
    char B;
    if(nextConsoante(B)){
      ans[idx] = B;
      dic[ fr[idx] ] = B;
      dic2[ B ] = fr[idx];
      if(F(idx+1,50)){
       return true;
      }
      dic.erase( fr[idx] ); // desmapeia
      dic2.erase( B );

    }
  }

  return false;
}






int main(){

  freopen("javanese.in","r",stdin);
  freopen("javanese.out","w",stdout);

  // freopen("IN","r",stdin);


string aux;

  for(int i = 0 ; getline(cin,aux); ++i){
   if(i) fr += '\n';
   fr += aux;
  }
  dic.clear();
  dic2.clear();
  F(0,0);
  puts("impossible");
  return 0;
}
