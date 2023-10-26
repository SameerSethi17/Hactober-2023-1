#include <iostream>
#include <vector>
#include <string>

class MarketData {
public:
    // Simulated market data
    double getStockPrice(const std::string& symbol) {
        // You would typically fetch real market data here
        // For simplicity, we'll use random values
        if (symbol == "AAPL") {
            return 150.0 + (rand() % 100) / 10.0;
        } else if (symbol == "GOOG") {
            return 2800.0 + (rand() % 200) / 10.0;
        }
        return 0.0;
    }
};

class Order {
public:
    std::string symbol;
    int quantity;
    double price;
    std::string side; // "Buy" or "Sell"
};

class TradingSystem {
public:
    MarketData marketData;
    std::vector<Order> orders;

    void placeOrder(const Order& order) {
        // In a real trading system, you would send the order to the exchange
        // For simplicity, we'll just print the order here
        std::cout << "Placing Order: " << order.side << " " << order.quantity << " shares of " << order.symbol
                  << " at $" << order.price << std::endl;
        orders.push_back(order);
    }

    // Simulate trading logic
    void executeTradingStrategy() {
        for (const Order& order : orders) {
            double currentPrice = marketData.getStockPrice(order.symbol);

            if ((order.side == "Buy" && order.price >= currentPrice) ||
                (order.side == "Sell" && order.price <= currentPrice)) {
                std::cout << "Order Executed: " << order.side << " " << order.quantity << " shares of " << order.symbol
                          << " at $" << currentPrice << std::endl;
            } else {
                std::cout << "Order Rejected: " << order.side << " " << order.quantity << " shares of " << order.symbol
                          << " at $" << currentPrice << std::endl;
            }
        }
    }
};

int main() {
    srand(time(0)); // Seed for random data (for simulation)

    TradingSystem tradingSystem;
    Order buyOrder = { "AAPL", 100, 155.0, "Buy" };
    Order sellOrder = { "GOOG", 50, 2790.0, "Sell" };

    tradingSystem.placeOrder(buyOrder);
    tradingSystem.placeOrder(sellOrder);

    tradingSystem.executeTradingStrategy();

    return 0;
}
