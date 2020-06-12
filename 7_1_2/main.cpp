#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
private:
    char *name;
    int age;
public:
    MyFriendInfo(char *myname, int myage) :age(myage)
    {
        int len = strlen(myname) + 1; //길이에 의한 할당
        name = new char[len]; //이름에 대한 동적할당
        strcpy(name, myname);
    }
    void ShowMyFriendInfo(){
        cout<<"이름 : "<< name << '\n';
        cout<<"나이 : "<< age << '\n';
    }
    ~MyFriendInfo(){
        delete [] name; //동적할당 소멸
        cout<<"My Friend 소멸자 실행"<<'\n';
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;
public:
    MyFriendDetailInfo(char *myname, int myage, char *address, char *phonenum) :MyFriendInfo(myname, myage)
    {
        int len = strlen(address) + 1; //주소의 길이
        int len_sec = strlen(phonenum) + 1; // 핸드폰번호의 길이
        addr = new char[len]; //주소 동적할당
        phone = new char[len_sec]; //핸드폰번호 동적할당
        strcpy(addr, address); //주소 복사
        strcpy(phone,phonenum); //핸드폰번호 복사
    }
    void ShowMyFriendDetailInfo(){
        ShowMyFriendInfo();
        cout<<"주소 : "<< addr << '\n';
        cout<<"핸드폰 번호 : "<< phone << '\n';
    }
    ~MyFriendDetailInfo(){
        delete []addr;
        delete []phone;
        cout<<"My Friend Detail 소멸자 실행" << '\n';
    }
};
int main(){
    MyFriendDetailInfo user1("이동재", 25, "서울특별시 광진구 구의3동", "010-1234-5678");
    MyFriendDetailInfo user2("동까", 25, "서울특별시 광진구 구의동", "010-4321-8765");
    user1.ShowMyFriendDetailInfo();
    user2.ShowMyFriendDetailInfo();
    return 0;
}
