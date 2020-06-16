/*
 #include <iostream>
using namespace std;

class First{
public:
    vartual void MyFunc() { cout<<"FirstFunc"<<'\n';}
};

class Second : public First{
public:
    void MyFunc() { cout<<"SecondFunc"<<'\n';}
};

class Third : public Second{
public:
    void MyFunc() { cout<<"ThirdFunc"<<'\n';}
};

int main(){
    Third *tptr = new Third();
    Second *sptr = tptr;
    First *fptr = sptr;
    
    fptr->MyFunc();     //각 포인터 함수를 이용해서 함수 호출
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    
    return 0;
}
*/ 
