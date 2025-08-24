//
// Created by PC on 21-Aug-25.
//

#ifndef SHADER_H
#define SHADER_H

#include "Euhe.h"

namespace Euhe {

class Shader {

public:
    // designated the program ID
    unsigned int ID;

    // constructor read and builds the shader
    Shader(const char* inVertexPath, const char* inFragmentPath);

    // activate the shader
    virtual void activate();

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

};

} // Euhe

#endif //SHADER_H
