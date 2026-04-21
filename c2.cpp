#include<string>
#include<iostream>
#include<string_view>
struct X{
    std::string s;
    X(std::string_view s): s{s}{
        std::cout<<std::format("X::X(std::string_view) for {}\n", s);
    }
    ~X(){
        std::cout<<std::format("X::~X() for {}\n",s);

    }
};
X global{"global"};
void g(){
    X xg{<<g()>>};
}
int main(){
    X *p0=new X{"p0"};
    [[maybe_unused]] X *p1=new X{"p1"};
    X xmain{"main()"};
    g();
    delete p0;

}