#include <iostream>

int main(){
    std::cout << "I'm ghoul!!!" << std::endl;
    for (int i = 1000; i > 6; i -= 7){
        std::cout << i << " - 7 = " << i - 7 << std::endl;
    }
    return 0;
}