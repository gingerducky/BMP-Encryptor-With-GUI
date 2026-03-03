#include <cstdint>
#include <fstream>
#include <iostream>
#include <filesystem>

#pragma once

#pragma pack(push, 1)
struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;

    void showVals() {
        std::cout << "Red: " << (int)red << " Green: " << (int)green << " Blue: " << (int)blue << std::endl;
    }

    void setVals(uint8_t r, uint8_t g, uint8_t b) {
        red = r;
        green = g;
        blue = b;
    }
};
#pragma pack(pop)

class BmpImage24Bit {

    Pixel p;
    int32_t width, height, offset, size, byter_per_row, padding;
    int16_t bits;

    std::filesystem::path filePath;
    std::fstream fileStream;

    void loadBMPData(std::filesystem::path pathToBmp);

    public:
        BmpImage24Bit(std::filesystem::path pathToBmp);
        BmpImage24Bit(const BmpImage24Bit& other);
        std::filesystem::path setFileName(std::string newName);
        int32_t getWidth() const;
        int32_t getHeight() const;
        int32_t getOffset() const;
        int32_t getBytesPerRow() const;
        int32_t getPadding() const;
        int16_t getBits() const;
        std::filesystem::path getFilePath() const;
        Pixel getPixelAt(uint32_t x, uint32_t y);
        Pixel setPixelAt(uint32_t x, uint32_t y, Pixel pixelIn);
};
