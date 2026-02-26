#include "../BmpImage/BmpImage.h"
#include <cstdlib>
#include <cstdint>
#include <filesystem>

#pragma once

class Encryptor {
    public:
        enum class ImageType {
            BMP24bit
        };
        Encryptor(ImageType t);
        Pixel pixelXOREncryption(Pixel input);
        void resetSrand(uint16_t pass);
    private:
        ImageType imgType;
};
