#include <format>
#include <iostream>
#include <map>

#include "headers/csv/csv_pair.h"
#include "headers/csv/csv_reader.h"
#include "headers/csv/csv_structure.h"
#include "headers/utils/status.h"

int main() {
    auto csv_ask = CSV_Reader("csv/EURUSD_Candlestick_1_M_ASK_01.04.2025-30.04.2025.csv");
    auto csv_bid = CSV_Reader("csv/EURUSD_Candlestick_1_M_BID_01.04.2025-30.04.2025.csv");

    if (!csv_ask.isOpen() || !csv_bid.isOpen())
        status::error("Error opening files!");

    csv_ask.readLine();
    csv_bid.readLine();


    auto eur_map = std::map<std::string, CSV_Pair>();

    for (int idx=1; !csv_ask.isEOF(); ++idx) {
        auto ask_data = read_row(csv_ask);
        auto bid_data = read_row(csv_bid);

        eur_map.insert({ask_data.gmt_time, {ask_data, bid_data}});
    }
    if (!csv_ask.readLine().empty() || !csv_bid.readLine().empty())
        status::warn("ASK & BID .csv files are not the same length!");

    std::cout << eur_map["30.04.2025 10:40:00.000"].ask.open;
}

