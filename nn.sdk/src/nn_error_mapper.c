#include "nn_error_mapper.h"

nn_error map_error_code(cl_uint error_code, nn_tuple const * const mapping, const unsigned short length) {
    for(unsigned short i = 0; i < length; i++) {
        if(error_code == mapping[i].key) { return mapping[i].error; }
    }
    return OK;
}