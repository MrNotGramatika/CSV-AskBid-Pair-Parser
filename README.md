# CSV-AskBid-Pair-Parser

## Example
```C++
int main() {  
    const auto eur2 = CSV_Map(  
  "csv/EURUSD_Candlestick_1_M_ASK_01.04.2025-30.04.2025.csv",  
        "csv/EURUSD_Candlestick_1_M_BID_01.04.2025-30.04.2025.csv"  
  );  
    const auto gbp = CSV_Map(  
  "csv/GBPUSD_Candlestick_1_M_ASK_01.04.2025-30.04.2025.csv",  
        "csv/GBPUSD_Candlestick_1_M_BID_01.04.2025-30.04.2025.csv"  
  );  
  
    const std::string timestamp = "01.04.2025 00:01:00.000";  
    std::cout << std::format("Time: [{}]\n", timestamp);  
    std::cout << std::format("  ASK price (open): {}\n", eur2[timestamp].ask.open);  
    std::cout << std::format("  ASK price (close): {}\n", eur2[timestamp].ask.close);  
    std::cout << std::format("  ASK price (high): {}\n", eur2[timestamp].ask.high);  
    std::cout << std::format("  ASK price (low): {}\n", eur2[timestamp].ask.low);  
    std::cout << '\n';  
  
    std::cout << std::format("  BID price (open): {}\n", eur2[timestamp].bid.open);  
    std::cout << std::format("  BID price (close): {}\n", eur2[timestamp].bid.close);  
    std::cout << std::format("  BID price (high): {}\n", eur2[timestamp].bid.high);  
    std::cout << std::format("  BID price (low): {}\n", eur2[timestamp].bid.low);  
}
 ```
