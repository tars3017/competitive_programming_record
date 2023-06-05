#include "function.h"

INT INT::operator*(INT x) {
    INT tmp = *this;
    INT ret;
    // std::cout << "tmp=" << tmp << std::endl;
    for (int i = 0; i < x.len; ++i) {
        for (int j = 0; j < x.data[i]; ++j) {
            // std::cout << "add " << tmp << std::endl;
            ret = ret + tmp;
        }
        tmp.mulby10();
    }
    return ret;
}