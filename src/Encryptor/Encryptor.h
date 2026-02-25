#include "../BmpImage/BmpImage.h"
#include <filesystem>

#pragma once

class Encryptor {
    BmpImage24Bit inputImg;
    BmpImage24Bit outputImg; //Make a copy of the original and change it's name and then encrypt it
    std::filesystem::path pathToOutputFolder;

    public:
        Encryptor() {}
        Encryptor(std::filesystem::path inputPath): inputImg(inputPath), outputImg(inputPath);
        setImg(std::filesystem::path inputPath);
        setImg(std::filesystem::path inputPath, std::filesystem::path outputPath);
        setImg(std::filesystem::path inputPath, std::filesystem::directory outputPath, std::filesystem::path imgName);
        setImg()
        applyXORCurrent();
}
