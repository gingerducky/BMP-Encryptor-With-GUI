#include <"BmpImage.h">
#include <string>
#include <fstream>

BmpImage24Bit::BmpImage24Bit(std::string pathToBmp) : filePath(pathToBmp) {
    fileStream.open(pathToBmp, std::ios::binary|std::ios::in|std::ios::out);

    /* What do I do if and object's constructor fails but I don't want to
    end the program? I think it's in chapter 24 of my book, so I'll
    wait until I get there before implementing this. */
}
