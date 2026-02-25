#include "BmpImage/BmpImage.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        std::cerr << "Wrong Amount of Arguments!\n";
        exit(1);
    }
    std::string inputPath;
    inputPath = argv[1];
    BmpImage24Bit myImg(inputPath);
    Pixel mypixel;

    std::cout << "Width: " << myImg.getWidth() << " Height: " << myImg.getHeight() << std::endl;
    mypixel = myImg.getPixelAt(0, 0);
    mypixel.showVals();

    mypixel.setVals(255, 255, 255);
    int i;
    int j;
    for (i = 0; i < myImg.getHeight(); i++) {
        for (j = 0; j < myImg.getWidth(); j++) {
            myImg.setPixelAt(j, i, mypixel);
        }
    }
    std::cout << i << ' ' << j << std::endl;
    std::cout << "End\n";
    return 0;

}
