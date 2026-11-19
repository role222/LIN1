#include <valarray>
#include "Iteration.h"

std::valarray<double> Iteration(std::valarray<std::valarray<double>> &ms, double Eps){
    std::valarray<double> X1;
    std::valarray<double> X2;
    X1.resize(ms.size());
    X2.resize(ms.size());

    for(int i = 0; i < ms.size(); i++) {
        double d_el = ms[i][i];
        ms[i] /= d_el;
    }

    while(true){
        for(int i = 0; i < ms.size(); i++){
            X1[i] = ms[i][ms.size()];
            for(int j = 0; j < ms.size(); j++) if(i!=j) X1[i] -= X2[j] * ms[i][j];
        }

        bool flag = true;
        for(int i = 0; i < ms.size(); i++) if(std::abs(X1[i] - X2[i]) > Eps) flag = false;
        if(flag) break;

        for(int i = 0; i < ms.size(); i++) X2[i] = X1[i];
    }
    return X2;
}