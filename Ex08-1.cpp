#include <iostream>
using namespace std;

class First{
public:
    void FirstFunc() { cout<<"FirstFunc()"<<'\n';}
    virtual void SimpleFunc() { cout<<"First's SimpleFunc()"<<'\n';}
};

class Second : public First{
public:
    void SecondFunc() { cout<<"SecondFunc()"<<'\n';}
    virtual void SimpleFunc() { cout<<"Second's SimpleFunc()"<<'\n';}
};

class Third : public Second{
public:
    void ThridFunc() { cout<<"ThirdFunc()"<<'\n';}
    virtual void SimpleFunc() { cout<<"Third's SimpleFunc()"<<'\n';}
};

int main(){
    Third obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThridFunc();
    obj.SimpleFunc(); //가상함수이므로 Third만 출력
    
    Second & sref = obj;  //Second 참조자를 생성
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();
    
    First & fref = obj;  //First 참조자를 생성
    fref.FirstFunc();
    fref.SimpleFunc();
    return 0;
}
