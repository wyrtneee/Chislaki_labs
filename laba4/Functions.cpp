
#include "Functions.hpp"


vector<pair<double, double>> readFromFile(const string& fileName, int& N) {
    ifstream in(fileName);
    vector<pair<double, double>> F;
    if (in.is_open()) {
        in >> N;
        double x;
        double y;
        for (int i = 0; i < N; ++i) {
            in >> x >> y;
            F.push_back({ x, y });
        }
    }
    in.close();
    return F;
}

