#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tire {
    double t; 
    double f; 
};

vector<vector<vector<double>>> dp1;
vector<vector<vector<double>>> dp2;
vector<vector<vector<vector<double>>>> dp3;

double gpSum(double f, int laps) {
    if (f == 1.0) return laps;
    return (pow(f, laps) - 1.0) / (f - 1.0);
}

double minTimeToRaceWarmUp(vector<Tire>& tires, int laps) {
    double totalTime = 1e18;
    for (const auto& tire : tires) {
        double currTime = tire.t * gpSum(tire.f, laps);
        totalTime = min(totalTime, currTime);
    }
    return totalTime;
}

double recurTime(vector<Tire>& tires, int currTire, int tireTime, int lapIndex, int laps, double pitTime) {
    if (lapIndex == laps) return 0.0;

    if (dp1[currTire][tireTime][lapIndex] > -0.5) {
        return dp1[currTire][tireTime][lapIndex];
    }

    // or don't
    double currentLapCost = tires[currTire].t * pow(tires[currTire].f, tireTime);
    double res = currentLapCost + recurTime(tires, currTire, tireTime + 1, lapIndex + 1, laps, pitTime);

    // take a pitstop
    for (int i = 0; i < tires.size(); i++) {
        double pitOption = currentLapCost + pitTime + recurTime(tires, i, 0, lapIndex + 1, laps, pitTime);
        res = min(res, pitOption);
    }

    return dp1[currTire][tireTime][lapIndex] = res;
}

double minTimeToRace(vector<Tire> tires, int laps, double pitTime) {
    int tSize = tires.size();
    dp1.assign(tSize, vector<vector<double>>(laps + 1, vector<double>(laps + 1, -1.0)));

    double totalTime = 1e18;
    for (int i = 0; i < tSize; i++) {
        totalTime = min(totalTime, recurTime(tires, i, 0, 0, laps, pitTime));
    }
    // time : O(laps^2*tires^2)
    return totalTime;
}

double recurTimeV2(vector<Tire>& tires, int currTire, int tireTime, int lapIndex, int laps, const vector<double>& pitCosts) {
    if (lapIndex == laps) return 0.0;

    if (dp2[currTire][tireTime][lapIndex] > -0.5) {
        return dp2[currTire][tireTime][lapIndex];
    }

    double currentLapCost = tires[currTire].t * pow(tires[currTire].f, tireTime);
    double res = currentLapCost + recurTimeV2(tires, currTire, tireTime + 1, lapIndex + 1, laps, pitCosts);

    for (int i = 0; i < tires.size(); i++) {
        double pitOption = currentLapCost + pitCosts[i] + recurTimeV2(tires, i, 0, lapIndex + 1, laps, pitCosts);
        res = min(res, pitOption);
    }

    return dp2[currTire][tireTime][lapIndex] = res;
}

double minTimeToRaceV2(vector<Tire> tires, int laps, vector<double> pitCosts) {
    int tSize = tires.size();
    dp2.assign(tSize, vector<vector<double>>(laps + 1, vector<double>(laps + 1, -1.0)));

    double totalTime = 1e18;
    for (int i = 0; i < tSize; i++) {
        totalTime = min(totalTime, recurTimeV2(tires, i, 0, 0, laps, pitCosts));
    }
    
    // O(laps^2*tires^2)
    return totalTime;
}

double recurTimeV3(vector<Tire>& tires, int currTire, int tireTime, int lapIndex, int psCount, int laps, 
                   double basePitTime, double linearInc) {
    if (lapIndex == laps) return 0.0;

    if (dp3[currTire][tireTime][lapIndex][psCount] > -0.5) {
        return dp3[currTire][tireTime][lapIndex][psCount];
    }

    double currentLapCost = tires[currTire].t * pow(tires[currTire].f, tireTime);
    double res = currentLapCost + recurTimeV3(tires, currTire, tireTime + 1, lapIndex + 1, psCount, laps, basePitTime, linearInc);

    double currentPitCost = basePitTime + psCount * linearInc;

    for (int i = 0; i < tires.size(); i++) {
        double pitOption = currentLapCost + currentPitCost + 
                           recurTimeV3(tires, i, 0, lapIndex + 1, psCount + 1, laps, basePitTime, linearInc);
        res = min(res, pitOption);
    }

    return dp3[currTire][tireTime][lapIndex][psCount] = res;
}

double minTimeToRaceV3(vector<Tire> tires, int laps, double basePitTime, double linearInc) {
    int tSize = tires.size();
    dp3.assign(tSize, vector<vector<vector<double>>>(laps + 1, vector<vector<double>>(laps + 1, vector<double>(laps + 1, -1.0))));

    double totalTime = 1e18;
    for (int i = 0; i < tSize; i++) {
        totalTime = min(totalTime, recurTimeV3(tires, i, 0, 0, 0, laps, basePitTime, linearInc));
    }

    // O(laps^3*tires^2)
    return totalTime;
}
