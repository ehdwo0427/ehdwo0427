/*
 정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다. 그런데 정사각형은 직사각형의 일종이므로, 다음의 형태로 클래스의 상속관계를 구성하고자 한다.
이에 다음 main 함수와 함께 실행이 가능하도록 위의 클래스를 완성해보자. 참고로 상속을 한다고 해서 유도 클래스에 무엇인가를 많이 담아야 한다는 생각을 버리자!
 
 int main(){
     Rectangle rec(4,3);
     rec.ShowAreaInfo();
     
     Square sqr(7);
     sqr.ShowAreaInfo();
     return 0;
 }
 실행의 예:
 면적: 12
 면적: 49
 */

#include<iostream>
using namespace std;

class Rectangle{
private:
    int lenx;
    int leny;
public:
    Rectangle(int x, int y) : lenx(x), leny(y)
    {}
    void ShowAreaInfo(){
        cout<<"면적 :"<< lenx * leny <<'\n';
    }
};

class Square : public Rectangle {
private:
    int lenz;
public:
    Square(int a) :Rectangle(a,a)
    {}
};

int main(){
    Rectangle rec(4,3);
    rec.ShowAreaInfo();
    
    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}
