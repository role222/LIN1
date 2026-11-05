#include <valarray>
#include <iostream>
#include "print_ms.h"

void print_ms(std::valarray<std::valarray<double>> &ms){
    int N = ms[0].size(), M = ms.size();

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) std::cout << ms[i][j] << "  ";
        std::cout << "\n";
    }
}