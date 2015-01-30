//
//  IOManager.h
//  KodeEngine
//
//  Created by Wilson Koder on 15/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__IOManager__
#define __KodeEngine__IOManager__

#include <string>
#include <vector>

namespace KodeEngine {
    class IOManager {
    public:
        std::string readFileToString(std::string fileName);
        bool readFileToBuffer(const std::string &path, std::vector<unsigned char> &data);
    };
}

#endif /* defined(__KodeEngine__IOManager__) */
