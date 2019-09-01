#include "nn_kernels.h"

#include "nn.sdk.common/nn_util.h"

const byte **simple_kernel_names_list = (const char *[]) {
    "vector_add", NULL
};

const byte **simple_kernel_sources_list = (const char *[]) {
    dump_bits(void __kernel vector_add() {
        return;
    }), NULL
};

void simple_kernel_sources(nn_kernel_source *const sources) {
    sources->kernel_names = simple_kernel_names_list;
    sources->kernel_sources = simple_kernel_sources_list;
    sources->kernel_names_length = 1;
    sources->kernel_sources_length = 1;
    return;
}