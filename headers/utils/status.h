//
// Created by mrnotgramatika on 5/25/25.
//

#ifndef STATUS_H
#define STATUS_H
#include <cstdlib>
#include <iostream>

namespace status {
    constexpr void error(std::string msg, int error_code=1, bool die=true) {
        std::cerr << "[ERR]: " << msg << '\n';
        exit(error_code);
    }

    constexpr void warn(std::string msg) {
        std::clog << "[WARN]: " << msg << '\n';
    }
}

#endif //STATUS_H
