#ifndef UTILITY_HPP
#define UTILITY_HPP

#define RGB(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3))

float mapf(float input, float input_min, float input_max, float output_min, float output_max);

#endif