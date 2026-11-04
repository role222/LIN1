#include <valarray>
#include <fstream>
#include "read.h"

bool file_read(const char* path, std::valarray<std::valarray<double>> &read_ms){
    std::ifstream file(path);
    if(!file.is_open()) return false;

    //Resize block
    std::string str;
    std::getline(file, str);
    int M = 1;
    for(int i = 0; i < str.size(); i++) if(str[i] == ',') M++;
    int N = 1;
    while(std::getline(file, str)) N++;
    read_ms.resize(M);
    for(int i = 0; i < M; i++) read_ms[i].resize(N);

    //Read data
    file.clear();
    file.seekg(0, std::ios::beg);

    for(int j = 0; j < N-M; j++){
        for(int i = 0; i < M; i++) {if(i != 0) {file.ignore(1);} file >> read_ms[i][M + j];}
    }

    for(int i = 0; i < M; i++) for(int j = 0; j < M; j++) {if(j != 0) {file.ignore(1);} file >> read_ms[i][j];}

    file.close();
    return true;
}