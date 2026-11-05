#include <valarray>
#include "Det.h"

double Det(std::valarray<std::valarray<double>> &ms){
    if(ms.size() == 2) return ((ms[0][0] * ms[1][1]) - (ms[0][1] * ms[1][0]));
    else if(ms.size() == 1) return ms[0][0];
    std::valarray<std::valarray<double>> sm;
    sm.resize(ms.size() - 1);
    for(int i = 0; i < ms.size() - 1; i++) sm[i].resize(ms.size() - 1);
    double det = 0;

    for(int i = 0; i < ms.size(); i++){

        for(int x = 1; x < ms.size(); x++){
            for(int y = 0; y < ms.size() - 1; y++){
                if(y >= i) sm[x - 1][y] = ms[x][y+1];
                else sm[x-1][y] = ms[x][y];
            }
        }

        double otv = (i%2 == 1 ? (-1) : 1) * Det(sm) * ms[0][i];
        det += otv;

    }

    return det;
}