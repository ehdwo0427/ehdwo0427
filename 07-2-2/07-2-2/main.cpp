/*
 책을 의미하는 Book 클래스와 전자 책을 의미하는 Ebook 클래스를 정의하고자 한다. 그런데 전자 책도 책의 일종이므로, 다음의 형태로 클래스의 상속관계를 구성하고자 한다.
 
 class Book
 {
 private:
    char * title;
    char * isbn;
    int price;
    . . .
 };
 
 위의 Ebook 클래스에 선언된 멤버 DRMKey는 전자 책에 삽입이 되는 보안관련 키의 정보를 의미한다. 그럼 다음 main 함수와 함께 실행이 가능하도록 위의 클래스를 완성해보자.
 실행의 예:
 제목 : 좋은 C++;
 ISBN : 555-12345-890-0
 가격 : 20000
 
 제목 : 좋은 C++ ebook
 ISBN : 555-12345-890-1
 가격 : 10000
 인증키 : fdx9wi8kiw
 
 */

#include <iostream>
#include <cstring>
using namespace std;
class Book{
private:
    char * title;
    char * isbn;
    int price;
public:
    Book(char * bookname, char * code, int bookprice) :price(bookprice)
    {
        int booklen = strlen(bookname) + 1;
        int codelen = strlen(code) + 1;
        title = new char[booklen];
        isbn = new char[codelen];
        strcpy(title, bookname);
        strcpy(isbn, code);
    }
    void ShowBookInfo(){
        cout<<"제목 : "<< title << '\n';
        cout<<"ISBN : "<< isbn << '\n';
        cout<<"가격 : " << price << '\n';
    }
    ~Book(){
        delete []title;
        delete [] isbn;
    }
};

class EBook : public Book{
private:
    char * DRMKey;
public:
    EBook(char * bookname, char * code, int bookprice, char * key) : Book(bookname, code, bookprice)
    {
        int len = strlen(key) + 1;
        DRMKey = new char[len];
        strcpy(DRMKey, key);
    }
    void ShowEBookInfo(){
        ShowBookInfo();
        cout<<"인증키 : "<< DRMKey <<'\n';
    }
    ~EBook(){
        delete []DRMKey;
    }
};

int main(){
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<'\n';
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}
