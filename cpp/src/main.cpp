#include <iostream>
#include <fstream>
#include <valarray>
#include <string>

#include "read.h"

void ms_print(std::valarray<std::valarray<double>> &ms){
    int N = ms[0].size(), M = ms.size();

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) std::cout << ms[i][j] << "  ";
        std::cout << "\n";
    }
}

int main(int argc, char** argv){
    std::valarray<std::valarray<double>> full_ms;
    if(argc == 1 || argc > 3) {std::cerr << "Need file path, like 'this_program path/to/file'\nAborted.\n"; return 1;}
    else if(argc == 2) {if(!file_read(argv[1], full_ms)) {std::cerr << "Bad file or path\nAborted\n"; return 1;}}
    else if(argc == 3 && argv[1] == std::string("-bp")){
        std::string path = "../data_for_test/";
        path += argv[2];
        if(!file_read(path.c_str(), full_ms)) {std::cerr << "Bad file or path\nAborted\n"; return 1;}
    }
    else {std::cerr << "For use basic path, you should write 'this_program -bp name.of.file/or/path'\nAborted.\n"; return 1;}

    ms_print(full_ms);

    std::cout << full_ms[0].size() << "  " << full_ms.size() << "\n";
    int N = full_ms[0].size(), M = full_ms.size();
    for(int j = 0; j < N-M; j++) {
        for(int i = 0; i < M; i++) std::cout << full_ms[i][M + j] << "  ";
        std::cout << "\n";
    }



    return 0;
}