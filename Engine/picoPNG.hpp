#ifndef PICO_PNG_H
#define PICO_PNG_H

#include <vector>
/* decodePNG: the picoPNG function, decodes a PNG file buffer in memory, into a raw pixel buffer.
 * returns 0 if no error, something else if an error occured.
 */
namespace Mengine { extern int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height, const unsigned char* in_png, size_t in_size, bool convert_to_rgba32 = true); }

#endif