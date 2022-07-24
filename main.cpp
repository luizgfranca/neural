#include <iostream>

int main(void) {
    const int input_size = 4;
    const int neuron_count = 3;

    double inputs[input_size] = {1, 2, 3, 2.5};    
    double results[neuron_count];

    double** weights = new double*[neuron_count];

    double bias[neuron_count];

    weights[0] = new double[input_size] {0.2, 0.8, -0.5, 1};
    bias[0] = 2;

    weights[1] = new double[input_size] {0.5, -0.91, 0.26, -0.5};
    bias[1] = 3;

    weights[2] = new double[input_size] {-0.26, -0.27, 0.17, 0.87};
    bias[2] = 0.5;

    for(int i = 0; i < neuron_count; i ++) {
        results[i] = 0;
    }

    for(int i = 0; i < input_size; i ++) {
        for(int j = 0; j < neuron_count; j ++) {
            results[i] += weights[j][i] * inputs[i];
        }
    }

    for(int i = 0; i < neuron_count; i ++) {
        results[i] += bias[i];
    }

    std::cout << "RESULTS\n";
    for(int i = 0; i < neuron_count; i ++) {
        std::cout << i << results[i] << "\n";
    }

    return 0;
}