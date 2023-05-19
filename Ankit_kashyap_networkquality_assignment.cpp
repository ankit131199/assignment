#developed by Ankit kashyap (wavelabs assignment.)
#Open readme file for the explanation.
--
    
#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> maxNetworkQuality(std::vector<std::vector<int>>& towers, int radius) {
    int maxQuality = 0;
    std::vector<int> maxCoordinate = {0, 0};

    for (int x = 0; x <= radius; ++x) {
        for (int y = 0; y <= radius; ++y) {
            int totalQuality = 0;

            for (const auto& tower : towers) {
                int xi = tower[0];
                int yi = tower[1];
                int qi = tower[2];
                double d = std::sqrt((xi - x) * (xi - x) + (yi - y) * (yi - y));

                if (d <= radius) {
                    int signalQuality = std::floor(qi / (1 + d));
                    totalQuality += signalQuality;
                }
            }

            if (totalQuality > maxQuality) {
                maxQuality = totalQuality;
                maxCoordinate = {x, y};
            } else if (totalQuality == maxQuality && maxCoordinate > std::vector<int>{x, y}) {
                maxCoordinate = {x, y};
            }
        }
    }

    return maxCoordinate;
}
