//
// Created by Deniz Tohumcu on 23/11/2019.
//

#include "log.h"
#include <iostream>
log::log() {
    std::freopen( "output.txt","w",stdout);
    std::freopen( "error.txt", "w",stderr);
}
