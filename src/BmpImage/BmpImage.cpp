#include "BmpImage.h"
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

void BmpImage24Bit::loadBMPData(std::filesystem::path pathToBmp) {
    fileStream.open(pathToBmp, std::ios::binary|std::ios::in|std::ios::out);
    if (!fileStream) {
        std::cerr << "Something went wrong while trying to open the file!\n";
        exit(1);
    }
    /* What do I do if and object's constructor fails but I don't want to
    end the program? I think it's in chapter 24 of my book, so I'll
    wait until I get there before implementing this. */
    fileStream.seekg(28, std::ios::beg);
    fileStream.read(reinterpret_cast<char *>(&bits), 2);

    if (bits!=24) {
        std::cerr << "File is not of RGB 24 bit type!\n";
        exit(1);
    }

    fileStream.seekg(2, std::ios::beg);
    fileStream.read(reinterpret_cast<char *>(&size), 4);
    fileStream.seekg(10, std::ios::beg);
    fileStream.read(reinterpret_cast<char *>(&offset), 4);
    fileStream.seekg(18, std::ios::beg);
    fileStream.read(reinterpret_cast<char *>(&width), 4);
    fileStream.read(reinterpret_cast<char *>(&height), 4);
    
    byter_per_row = 3 * width;
    if (byter_per_row % 4 != 0) byter_per_row = (byter_per_row / 4 + 1) + 1;
    padding = byter_per_row - 3 * width;

    fileStream.seekg(offset, std::ios::beg); //first pixel location setup
}

BmpImage24Bit::BmpImage24Bit(std::filesystem::path pathToBmp) : filePath(pathToBmp) {
    BmpImage24Bit::loadBMPData(pathToBmp);
}

BmpImage24Bit::BmpImage24Bit(const BmpImage24Bit& other) {
    std::filesystem::path directory = other.getFilePath().parent_path();
    std::string stem = other.getFilePath().stem().string();
    std::string extension = other.getFilePath().extension().string();

    filePath = directory / (stem + "Copy" + extension);
    
    std::filesystem::copy_file(other.filePath, filePath, std::filesystem::copy_options::overwrite_existing);
    loadBMPData(filePath);
}

std::filesystem::path BmpImage24Bit::setFileName(std::string newName) {
    std::filesystem::path newPath = filePath.parent_path() / (newName + filePath.extension().string());

    std::filesystem::rename(filePath, newPath);
    filePath = newPath;
    return filePath;
}

int32_t BmpImage24Bit::getWidth() const {
    return width;
}

int32_t BmpImage24Bit::getHeight() const {
    return height;
}

int32_t BmpImage24Bit::getOffset() const {
    return offset;
}

int32_t BmpImage24Bit::getBytesPerRow() const {
    return byter_per_row;
}

int32_t BmpImage24Bit::getPadding() const {
    return padding;
}

int16_t BmpImage24Bit::getBits() const {
    return bits;
}

std::filesystem::path BmpImage24Bit::getFilePath() const {
    return filePath;
}

Pixel BmpImage24Bit::getPixelAt(uint32_t x, uint32_t y) {
    if (x > width-1 || y > height-1) {
        std::cerr << "Out of bounds!";
        exit(1);
    }
    fileStream.seekg(getOffset() + x * 3 + y * getBytesPerRow(), std::ios::beg);
    fileStream.read(reinterpret_cast<char *>(&p), 3);
    return p;
}

Pixel BmpImage24Bit::setPixelAt(uint32_t x, uint32_t y, Pixel pixelIn) {
    if (x > width-1 || y > height-1) {
        std::cerr << "Out of bounds!";
        exit(1);
    }
    fileStream.seekp(getOffset() + x * 3 + y * getBytesPerRow(), std::ios::beg);
    fileStream.write(reinterpret_cast<char *>(&pixelIn), 3);
    return getPixelAt(x, y);

}
