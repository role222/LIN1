#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdint>
#include <valarray>


int main(int argc, char* argv[]){
    std::ifstream file("../data_for_test/equ1.txt");
    double smth = 0;
    file >> smth;
    std::cout << smth << std::endl;
}