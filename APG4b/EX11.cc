#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  string op;
  int B;

  for(int i = 0; i < N; i++){
    cin >> op >> B;
    if(op == "+"){
        A += B;
    }else if(op == "-"){
        A -= B;
    }else if(op == "*"){
        A *= B;
    }else{
        if(B == 0){
            cout << "error" << endl;
            break;
        }else{
            A /= B;
        }
    }
    //if(B == 0)
        //break;
    cout << i + 1 << ":" << A << endl;
  }
}