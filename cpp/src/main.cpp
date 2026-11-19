#include <iostream>
#include <fstream>
#include <valarray>
#include <string>

#include "GausJordan.h"
#include "Cramer.h"
#include "Iteration.h"

#include "read.h"

int main(int argc, char** argv){
    std::valarray<std::valarray<double>> full_ms;
    if(argc == 1 || argc > 3) {std::cerr << "Need file path, like 'this_program path/to/file'\nAborted.\n"; return 1;}
    else if(argc == 2 && argv[1] == std::string("--fast-test")){
        std::string path = "../data_for_test/equ1.txt";
        if(!file_read(path.c_str(), full_ms)) {std::cerr << "Smth went wrong with '" << path << "'\nAborted\n"; return 1;}
        std::cout << "Cramer method result on '" << path << "'\n";
        std::valarray<double> X_C = Cramer(full_ms);
        for(int i = 0; i < X_C.size(); i++) std::cout << X_C[i] << "  ";
        std::cout << std::endl << std::endl;

        path = "../data_for_test/equ1.txt";
        if(!file_read(path.c_str(), full_ms)) {std::cerr << "Smth went wrong with '" << path << "'\nAborted\n"; return 1;}
        std::cout << "GausJordan method result on '" << path << "'\n";
        std::valarray<std::valarray<double>> X_GJ = GausJordan(full_ms);
        for(int y = 0; y < X_GJ.size(); y++){
            for(int x = 0; x < X_GJ[0].size(); x++) std::cout << X_GJ[y][x] << "  ";
            std::cout << std::endl;
        }
        std::cout << std::endl;

        path = "../data_for_test/equ1.txt";
        if(!file_read(path.c_str(), full_ms)) {std::cerr << "Smth went wrong with '" << path << "'\nAborted\n"; return 1;}
        std::cout << "Iteration method result on '" << path << "'\n";
        std::valarray<double> X_I = Iteration(full_ms);
        for(int i = 0; i < X_I.size(); i++) std::cout << X_I[i] << "  ";
        std::cout << std::endl << std::endl;

        return 0;
    }
    else if(argc == 2) {if(!file_read(argv[1], full_ms)) {std::cerr << "Bad file or path\nAborted\n"; return 1;}}
    else if(argc == 3 && argv[1] == std::string("--bp")){
        std::string path = "../data_for_test/";
        path += argv[2];
        if(!file_read(path.c_str(), full_ms)) {std::cerr << "Bad file or path\nAborted\n"; return 1;}
    }

    

    else {std::cerr << "For use basic path, you should write 'this_program -bp name.of.file/or/path'\nAborted.\n"; return 1;}

    std::cout << "Cramer method result:\n";
    std::valarray<double> X_C = Cramer(full_ms);
    for(int i = 0; i < X_C.size(); i++) std::cout << X_C[i] << "  ";
    std::cout << std::endl << std::endl;

    std::cout << "GausJordan method result:\n";
    std::valarray<std::valarray<double>> X_GJ = GausJordan(full_ms);
    for(int y = 0; y < X_GJ.size(); y++){
        for(int x = 0; x < X_GJ[0].size(); x++) std::cout << X_GJ[y][x] << "  ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Iteration method result:\n";
    std::valarray<double> X_I = Iteration(full_ms);
    for(int i = 0; i < X_I.size(); i++) std::cout << X_I[i] << "  ";
    std::cout << std::endl << std::endl;

    return 0;
}