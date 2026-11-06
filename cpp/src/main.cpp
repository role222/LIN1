#include <iostream>
#include <fstream>
#include <valarray>
#include <string>

#include "Cramer.h"
#include "read.h"

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

    std::valarray<double> X = Cramer(full_ms);
    for(int i = 0; i < X.size(); i++) std::cout << X[i] << "  ";
    std::cout << std::endl;

    return 0;
}