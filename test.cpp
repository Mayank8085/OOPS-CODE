#include<iostream>
using namespace std;

template<typename T,typename U>
class test
{
private:
 T x;
 U y;
    
public:
void getx();
    
};

template<typename T, typename U>
void test<T,U>::getx(){
    std::cout << x << std::endl;
}


