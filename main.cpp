#include<iostream>
#include<algorithm>
#define Max 1000000000
using namespace std;
int N, A, B, C, D, high = -Max, low = Max;
int Array[12];
void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Array[i];
    }
    cin >> A >> B >> C >> D;
}

void solution(int plus, int minus, int multiply, int divide, int cnt, int sum){
    if(cnt == N){
        high = max(sum, high);
        low  = min(sum, low);
        return;
    }
    
    if(plus > 0){
        solution(plus - 1, minus, multiply, divide, cnt + 1, sum + Array[cnt]);
    }
    if(minus > 0){
        solution(plus, minus - 1, multiply, divide, cnt + 1, sum - Array[cnt]);
    }
    if(multiply > 0){
        solution(plus, minus, multiply - 1, divide, cnt + 1, sum * Array[cnt]);
    }
    if(divide > 0){
        solution(plus, minus, multiply, divide - 1, cnt + 1, sum / Array[cnt]);
    }
}

void solve(){
    input();
    solution(A,B,C,D,1,Array[0]);
    cout<< high << '\n' << low << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
