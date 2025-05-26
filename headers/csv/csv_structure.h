//
// Created by mrnotgramatika on 5/26/25.
//

#ifndef CSV_STRUCTURE_H
#define CSV_STRUCTURE_H
#include "csv_reader.h"

struct CSV_Structure {
    using fp64 = long double;

    std::string gmt_time;
    fp64 open;
    fp64 high, low;
    fp64 close;
    fp64 volume;

    constexpr CSV_Structure() = default;
    constexpr CSV_Structure(const std::string&& gmt_time, const std::string&& open, const std::string&& high, const std::string&& low, const std::string&& close, const std::string&& volume)
        : gmt_time(gmt_time), volume(std::stold(volume)),
        open(std::stold(open)), close(std::stold(close)),
        high(std::stold(high)), low(std::stold(low)) {}
};


CSV_Structure read_row(CSV_Reader& csv, char delim=',') {
    return {
        csv.read(delim),
        csv.read(delim),
        csv.read(delim),
        csv.read(delim),
        csv.read(delim),
        csv.read()
    };
}

#endif //CSV_STRUCTURE_H
