#include <format>
#include <iostream>

#include "headers/csv/csv_map.h"


int main() {
    const auto eurusd = CSV_Map(
        "csv/EURUSD_Candlestick_1_M_ASK_01.04.2025-30.04.2025.csv",
        "csv/EURUSD_Candlestick_1_M_BID_01.04.2025-30.04.2025.csv"
    );
    const auto gbpusd = CSV_Map(
        "csv/GBPUSD_Candlestick_1_M_ASK_01.04.2025-30.04.2025.csv",
        "csv/GBPUSD_Candlestick_1_M_BID_01.04.2025-30.04.2025.csv"
    );

    const std::string timestamp = "01.04.2025 00:01:00.000";
    std::cout << std::format("Time: [{}]\n", timestamp);
    std::cout << std::format("  ASK price (open): {}\n", eurusd[timestamp].ask.open);
    std::cout << std::format("  ASK price (close): {}\n", eurusd[timestamp].ask.close);
    std::cout << std::format("  ASK price (high): {}\n", eurusd[timestamp].ask.high);
    std::cout << std::format("  ASK price (low): {}\n", eurusd[timestamp].ask.low);
    std::cout << '\n';

    std::cout << std::format("  BID price (open): {}\n", eurusd[timestamp].bid.open);
    std::cout << std::format("  BID price (close): {}\n", eurusd[timestamp].bid.close);
    std::cout << std::format("  BID price (high): {}\n", eurusd[timestamp].bid.high);
    std::cout << std::format("  BID price (low): {}\n", eurusd[timestamp].bid.low);
}