#include "NeuralNetwork.h"

designer::NeuralNetwork::NeuralNetwork() {}

float const * designer::NeuralNetwork::synapses() const { return _synapse; }
unsigned int const * designer::NeuralNetwork::topology() const { return _topology; }
unsigned int const * designer::NeuralNetwork::count() const { return _count; }
void designer::NeuralNetwork::resize() {}
