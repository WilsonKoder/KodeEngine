//
//  IOManager.cpp
//  KodeEngine
//
//  Created by Wilson Koder on 15/1/15.
//  Copyright (c) 2015 WilsonKoder. All rights reserved.
//

#include "IOManager.h"
#include <fstream>
#include <iostream>

std::string KodeEngine::IOManager::readFileToString(std::string fileName)
{
    std::string fileText = "";
    std::ifstream fileStream(fileName, std::ios::in);
    
    if (fileStream.is_open())
    {
        std::string line = "";
        while(getline(fileStream, line))
        {
            fileText += "\n" + line;
            //std::cout << line << std::endl;
        }
    }
    
    return fileText;
}

bool KodeEngine::IOManager::readFileToBuffer(const std::string &path, std::vector<unsigned char> &data)
{
    std::ifstream file;
    file.open(path, std::ios::binary);
    
    if(file.fail())
    {
        std::cerr << "Could not open file: " << path << std::endl;
        exit(2);
        return false;
    }
    
    file.seekg(0, std::ios::end); // go to end of file.
    int fileSize = file.tellg(); // get file size in bytes.
    file.seekg(0, std::ios::beg); // go back to beginning
    fileSize -= file.tellg(); // subtract any left over bytes
    
    data.resize(fileSize);
    file.read((char*)data.data(), fileSize);
    file.close();
    
    return true;
}