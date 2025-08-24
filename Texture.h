//
// Created by PC on 22-Aug-25.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#define STB_IMAGE_IMPLEMENTATION

#include "Euhe.h"
#include "ExternalLibrary/stb_image.h"

namespace Euhe {

class Texture {

public:
    void loadFromFile(const char* inFilename);

    void setSize(int inWidth, int inHeight);

private:
    int width;
    int height;
    int nrChannels;
    unsigned char *data;
};

} // Euhe

#endif //TEXTURE_H
