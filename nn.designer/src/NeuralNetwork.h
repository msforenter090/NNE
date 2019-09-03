#pragma once

#include <QObject>

namespace designer {
class NeuralNetwork {
    Q_DISABLE_COPY(NeuralNetwork)

private:
    float *_synapse;

    // fan_in, layer1, layer2, ..., fan_out
    unsigned int *_topology;
    unsigned int *_count;

public:
    explicit NeuralNetwork();
    float const * synapses() const;
    unsigned int const * topology() const;
    unsigned int const * count() const;
    void resize();
};
}
