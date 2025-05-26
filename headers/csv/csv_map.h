//
// Created by mrnotgramatika on 5/26/25.
//

#ifndef CSV_MAP_H
#define CSV_MAP_H
#include <map>

#include "csv_pair.h"
#include "csv_reader.h"
#include "csv_structure.h"
#include "../utils/status.h"

class CSV_Map {
public:
    CSV_Map(const std::string& ask_csv_filename, const std::string& bid_csv_filename)
        : csv_ask(CSV_Reader(ask_csv_filename)), csv_bid(CSV_Reader(bid_csv_filename))
    {
        if (!csv_ask.isOpen() || !csv_bid.isOpen())
            status::error("Error opening files!");

        csv_ask.read(); csv_bid.read();

        for (int idx=1; !csv_ask.isEOF() && !csv_bid.isEOF(); ++idx) {
            auto ask_data = read_row(csv_ask);
            auto bid_data = read_row(csv_bid);

            // printData(ask_data);

            m_map.insert({ask_data.gmt_time, {ask_data, bid_data}});
        }

        if (!csv_ask.isEOF() || !csv_bid.isEOF())
            status::warn("ASK & BID .csv files are not the same length!");
    }

    CSV_Pair operator[](const std::string& timestamp) {
        return m_map[timestamp];
    }

    CSV_Pair operator[](const std::string& timestamp) const {
        return m_map.at(timestamp);
    }


private:
    constexpr void printData(CSV_Structure csv_data, std::string headerName="") {
        if (!headerName.empty()) std::cout << std::format("--- {} --- \n", headerName);

        std::cout << std::format("[{}]: \n", csv_data.gmt_time);
        std::cout << "  Open: " << csv_data.open << '\n';
        std::cout << "  Close: " << csv_data.close << '\n';
        std::cout << std::format("  Low/High: {}/{}\n\n", csv_data.low,csv_data.high);
    }

    void insertDataIntoMap() {

    }


    using timestamp = std::string;

    CSV_Reader csv_ask;
    CSV_Reader csv_bid;
    std::map<timestamp, CSV_Pair> m_map;
};

#endif //CSV_MAP_H
