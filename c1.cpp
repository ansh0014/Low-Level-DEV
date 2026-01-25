#include <iostream>
#include <type_traits>
#include <cstddef>

bool same_bytes(const char *p0, const char *p1, std::size_t n){
    for(std::size_t i = 0; i < n; i++){
        if(p0[i] != p1[i]){
            return false;
        }
    }
    return true;
}

template <class T, class U>
bool same_bytes(const T &t, const U &b){
    static_assert(sizeof(T) == sizeof(U));
    static_assert(std::has_unique_object_representations_v<T>);
    static_assert(std::has_unique_object_representations_v<U>);

    return same_bytes(
        reinterpret_cast<const char*>(&t),
        reinterpret_cast<const char*>(&b),
        sizeof(T)
    );
}

template <class T>
void print_bytes(const T& obj){
    const unsigned char* p =
        reinterpret_cast<const unsigned char*>(&obj);

    for(std::size_t i = 0; i < sizeof(T); i++){
        std::cout << (int)p[i] << " ";
    }
    std::cout << "\n";
}

struct A{
    int x{2}, y{3};
};

struct Y{
    int x{2}, y{3};
};

int main(){
    A a;
    Y b;

    std::cout << "Bytes of A: ";
    print_bytes(a);

    std::cout << "Bytes of Y: ";
    print_bytes(b);

    std::cout << "A and Y have same bytes? "<<std::endl;

    if(same_bytes(a, b)){
        std::cout << "same bytes\n";
    } else {
        std::cout << "not same bytes\n";
    }
}
