#include "utility.hpp"

float mapf(float input, float input_min, float input_max, float output_min, float output_max) {
  float output = output_min + ((output_max - output_min) / (input_max - input_min)) * (input - input_min);
  return output;
}