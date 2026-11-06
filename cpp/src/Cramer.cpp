#include <valarray>
#include "Cramer.h"
#include "Det.h"

std::valarray<std::valarray<double>> rebuild_ms(std::valarray<std::valarray<double>> &ms, int i){
    std::valarray<std::valarray<double>> sm;

    sm.resize(ms.size());
    for(int i = 0; i < ms.size(); i++) sm[i].resize(ms.size());

    for(int x = 0; x < ms.size(); x++)
        for(int y = 0; y < ms.size(); y++)
            if(y != i) sm[x][y] = ms[x][y];
            else sm[x][i] = ms[x][ms.size()];
    
    return sm;
}

std::valarray<double> Cramer(std::valarray<std::valarray<double>> &ms){
    double Te = Det(ms);

    std::valarray<std::valarray<double>> sm;

    sm.resize(ms.size());
    for(int i = 0; i < ms.size(); i++) sm[i].resize(ms.size());

    std::valarray<double> X_ms;
    X_ms.resize(ms.size());

    for(int i = 0; i < ms.size(); i++){
        sm = rebuild_ms(ms, i);
        X_ms[i] = Det(sm);
    }
    X_ms /= Te;

    return X_ms;
}