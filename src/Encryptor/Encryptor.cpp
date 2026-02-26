#include "Encryptor.h"
#include <cstdint>
#include <cstdlib>
#include <filesystem>

Encryptor::Encryptor(ImageType t) : imgType(t) {}

Pixel Encryptor::pixelXOREncryption(Pixel input) {
    input.setVals(input.red^(rand() % 256), input.green^(rand() % 256), input.blue^(rand() % 256));
    return input;
}

void Encryptor::resetSrand(uint16_t pass) {
    srand(pass);
}


