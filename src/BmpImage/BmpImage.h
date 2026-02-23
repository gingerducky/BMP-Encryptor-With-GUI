#include <cstdint>
#include <string>
#include <fstream>

#pragma once

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

class BmpImage24Bit {

    std::fstream fileStream;
    Pixel p;
    int32_t width, height, offset, size, byter_per_row, padding;
    int16_t bits;

    std::string filePath;

    public:
        BmpImage24Bit(std::string pathToBmp);
        int32_t getWidth() const;
        int32_t getHeight() const;
        int32_t getOffset() const;
        int32_t getBytesPerRow() const;
        int32_t getPadding() const;
        int16_t getBits() const;
        std::string getFilePath() const;
        Pixel getPixelAt(uint32_t x, uint32_t y) const;
        bool setPixelAt(uint32_t x, uint32_t y, Pixel pixelIn);
};
