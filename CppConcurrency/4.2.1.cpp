/*
 * 4.2.1.cpp
 *
 *  Created on: 2019��3��14��
 *      Author: lian.pengfei
 */




#include <string>
#include <future>
struct X
{
    void foo(int,std::string const&);
    std::string bar(std::string const&);
};
X x;
auto f1=std::async(&X::foo,&x,42,"hello"); // ����p->foo(42,"hello")��p��ָ��x��ָ��
        auto f2=std::async(&X::bar,x,"goodbye"); // ����tmpx.bar("goodbye")�� tmpx��x�Ŀ�������
        struct Y
        {
    double operator()(double);
        };
Y y;
auto f3=std::async(Y(),3.141); // ����tmpy(3.141)��tmpyͨ��Y���ƶ����캯���õ�
auto f4=std::async(std::ref(y),2.718); // ����y(2.718)
X baz(X&);
std::async(baz,std::ref(x)); // ����baz(x)
class move_only
{
    public:
    move_only();
    move_only(move_only&&)
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&);
    move_only& operator=(move_only const&) = delete;
    void operator()();
};
auto f5=std::async(move_only()); // ����tmp()��tmp��ͨ��std::move(move_only())����õ�
