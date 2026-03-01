#include "BmpImage/BmpImage.h"
#include "Encryptor/Encryptor.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

    
    if (argc < 3 || argc > 4) {
        std::cerr << "Wrong Amount of Arguments!\n";
        exit(1);
    }
    std::string inputPath;
    inputPath = argv[1];
    BmpImage24Bit myImg(inputPath);
    BmpImage24Bit myNewImg = myImg;
    
    if (argc == 4) {
        std::cout << myNewImg.setFileName(argv[3]) << std::endl;
    }
        Pixel mypixel;
    
    Encryptor bmpEnc(Encryptor::ImageType::BMP24bit);
    bmpEnc.resetSrand(std::atoi(argv[2]));
    mypixel = myImg.getPixelAt(0, 0);
    std::cout << "Here!\n";
    mypixel.showVals();
    std::cout<<myNewImg.getWidth() << ' ' << myNewImg.getHeight() << std::endl;
    std::cout<<myImg.getWidth() << ' ' << myImg.getHeight() << std::endl;

    int i;
    int j;
    for (i = 0; i < myNewImg.getHeight(); i++) {
        for (j = 0; j < myNewImg.getWidth(); j++) {
            mypixel = myNewImg.getPixelAt(j, i);
            mypixel = bmpEnc.pixelXOREncryption(mypixel);
            myNewImg.setPixelAt(j, i, mypixel);
        }
    }
    std::cout << i << ' ' << j << std::endl;
    std::cout << "End\n";
    return 0;

}
