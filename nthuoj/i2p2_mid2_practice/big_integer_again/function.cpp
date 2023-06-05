#include "function.h"
INT INT::operator*(INT x) {
    INT ret;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < data[i]; ++j) {
            ret = ret + x;
        }
        x.mulby10();
    }
    return ret;
}