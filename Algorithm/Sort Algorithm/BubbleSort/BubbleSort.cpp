#include <iostream>
#include <vector>
#include <type_traits>
#include <random>

template <typename T,typename =void>
class HAS_GREAT:public std::false_type{
};

template <typename T>
class HAS_GREAT<T,std::void_t<decltype(T()>T())>>:public std::true_type{};

class Pair{
    static std::random_device e;
    static std::uniform_int_distribution<int> dis;
public:
    int first,second;
    Pair(){
        first=dis(e);
        second = dis(e);
    }
    bool operator>(Pair p){
        return first>p.first;
    }
};

std::random_device Pair::e = std::random_device();
std::uniform_int_distribution<int> Pair::dis = std::uniform_int_distribution<int>{0,99};

template <typename T,typename =std::enable_if_t<HAS_GREAT<T>::value>>
void BubbleSort(std::vector<T>& vals) {
    if (vals.empty()) return;
    for (size_t i = 0; i < vals.size() - 1; i++) {
        for (size_t j = vals.size() - 1; j > i; j--) {
            if (vals.at(j - 1) > vals.at(j)) {
                auto temp = vals.at(j);
                vals.at(j) = vals.at(j - 1);
                vals.at(j - 1) = temp;
            }
        }
    }
}


int main() {
    std::vector<Pair> v{30};

    for(auto& i:v){
        std::cout<<(i.first<10?"0":"")<<i.first<<" ";
    }
    std::cout<<std::endl;
    for(auto& i:v){
        std::cout<<(i.second<10?"0":"")<<i.second<<" ";
    }
    std::cout<<std::endl<<std::endl;

    BubbleSort(v);

    for(auto& i:v){
        std::cout<<(i.first<10?"0":"")<<i.first<<" ";
    }
    std::cout<<std::endl;
    for(auto& i:v){
        std::cout<<(i.second<10?"0":"")<<i.second<<" ";
    }
    std::cout<<std::endl;
    return 0;
}