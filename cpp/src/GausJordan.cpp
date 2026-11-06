#include <valarray>
#include "GausJordan.h"

std::valarray<std::valarray<double>> GausJordan(std::valarray<std::valarray<double>> &ms){
    std::valarray<std::valarray<double>> sm = ms;
    for(int i = 0; i < ms.size(); i++){
        int max_indx = i;
        for(int j = i+1; j < ms.size(); j++) if(abs(sm[max_indx][i]) < abs(sm[j][i])) max_indx = j;

        std::valarray<double> tmp;
        tmp = sm[max_indx];
        sm[max_indx] = sm[i];
        sm[i] = tmp;
    }

    for(int i = 0; i < sm.size(); i++){
        double sm_d_el = sm[i][i];
        sm[i] /= sm_d_el;
        for(int j = i+1; j < sm.size(); j++) sm[j] -= sm[i] * sm[j][i];
    }

    std::valarray<std::valarray<double>> X_ms;
    X_ms.resize(ms[0].size() - ms.size());
    for(int i = 0; i < ms[0].size() - ms.size(); i++) X_ms[i].resize(ms.size());

    for(int i = ms.size()-1; i >= 0; i--){
        for(int x = 0; x < X_ms.size(); x++){
            X_ms[x][i] = sm[i][sm.size() + x];
            for(int j = 0; j < sm.size(); j++){
                if(j != i) X_ms[x][i] -= sm[i][j] * X_ms[x][j];
            }
            X_ms[x][i] /= sm[i][i];
        }
    }

    return X_ms;
}