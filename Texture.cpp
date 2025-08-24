//
// Created by PC on 22-Aug-25.
//

#include "Texture.h"


namespace Euhe {
    void Texture::loadFromFile(const char* inFilename)
    {
        data = stbi_load(inFilename, &width, &height, &nrChannels, 0 );
    }

    void Texture::setSize(int inWidth, int inHeight)
    {
        width = inWidth;
        height = inHeight;
    }
} // Euhe