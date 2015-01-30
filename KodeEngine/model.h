//
//  model.h
//  KodeEngine
//
//  Created by Wilson Koder on 20/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#ifndef __KodeEngine__model__
#define __KodeEngine__model__

#include <stdio.h>
#include <string>

namespace KodeEngine {
    class Model {
    public:
        Model();
        void loadModel(std::string file);
    };
}

#endif /* defined(__KodeEngine__model__) */
