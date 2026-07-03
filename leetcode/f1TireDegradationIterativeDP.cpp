
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tire {
    double t; 
    double f; 
};


double gpSum(double f, int laps) {
    if (f == 1.0) return laps;
    return (pow(f, laps) - 1.0) / (f - 1.0);
}

// super clean iterative dp, a bit tricky but better optimisation
double minTimeToRace(vector<Tire> tires, int laps, double pitTime) {
    int tSize = tires.size();

    double totalTime = 1e18;

    // precalculate all the decays
    

    vector<double> dpRace(laps+1, 1e18); // contain the time
    vector<double> dpLap(laps+1, 1e18);

    // min time to complete the lap via tires

    int i,j,l; // this just says the min Time to cover 3 laps
    for(i=1;i<= laps;i++){
      for(j = 0; j<tSize; j++){
        // run the entire via this j tire, for entire lap period
        dpLap[i] = min(dpLap[i], tires[j].t*gpSum(tires[j].f, i));
      }
    }

    dpRace[0] = 0.0;
    for(i=1;i<=laps;i++){
      for(j=0;j<i;j++){
        // we take a pit stop at j
        double activePitTime = (j == 0) ? 0.0 : pitTime;
        dpRace[i] = min(dpRace[i], dpRace[j] + activePitTime +dpLap[i-j]);
      }
    }
    
    // TC: O(N*T + N^2)
    // Space : O(N)
    return dpRace[laps];
}


// follow up 1
double minTimeToRaceV2(vector<Tire> tires, int laps, vector<double> pitTime) {
    int tSize = tires.size();

    double totalTime = 1e18;

    // precalculate all the decays
    

    vector<double> dpRace(laps+1, 1e18); // contain the time
    vector<vector<double>> dpLap(laps+1, vector<double>(tSize+1, 1e18));

    // min time to complete the lap via tires

    int i,j,l, t; // this just says the min Time to cover 3 laps
    for(i=1;i<= laps;i++){
      for(j = 0; j<tSize; j++){
        // run the entire via this j tire, for entire lap period
        dpLap[i][j] = min(dpLap[i][j], tires[j].t*gpSum(tires[j].f, i));
      }
    }
    dpRace[0] = 0.0;
    // adds another state
    for(i=1;i<=laps;i++){
      for(j=0;j<i;j++){
        for(t=0;t<tSize;t++){
        // we take a pit stop at j
          double activePitTime = (j == 0) ? 0.0 : pitTime[t];
        // pitTime now depends on the tire
          dpRace[i] = min(dpRace[i], dpRace[j] + activePitTime +dpLap[i-j][t]);
        }
      }
    }
    
    // TC: O(N*T + N^2*T)
    // Space : O(N)
    return dpRace[laps];
}


// follow up 2, now need to maintain pitStop Count as well right
double minTimeToRaceV3(vector<Tire> tires, int laps, vector<double> pitTime, int pitIncCost) {
    int tSize = tires.size();

    double totalTime = 1e18;

    // precalculate all the decays
    

    vector<vector<double>> dpRace(laps+1, vector<double>(laps+1, 1e18)); // contain the time
    vector<vector<double>> dpLap(laps+1, vector<double>(tSize+1, 1e18));

    // min time to complete the lap via tires

    int i,j,l, t; // this just says the min Time to cover 3 laps
    for(i=1;i<= laps;i++){
      for(j = 0; j<tSize; j++){
        // run the entire via this j tire, for entire lap period
        dpLap[i][j] = min(dpLap[i][j], tires[j].t*gpSum(tires[j].f, i));
      }
    }

    dpRace[0][0] = 0.0;
    // adds another state
    int c;
    for(i = 1; i <= laps; i++){
        for(j = 0; j < i; j++){
            for(t = 0; t < tSize; t++){
                if (j == 0) {
                    dpRace[i][0] = min(dpRace[i][0], dpRace[0][0] + dpLap[i][t]);
                } else {
                    for(c = 0; c < j; c++){ 
                        if (dpRace[j][c] < 1e17) {
                            double activePitTime = pitTime[t] + c * pitIncCost;
                            dpRace[i][c + 1] = min(dpRace[i][c + 1], dpRace[j][c] + activePitTime + dpLap[i - j][t]);
                        }
                    }
                }
            }
        }
    }
    
    double finalTime = 1e18;
    for(c = 0; c <= laps; c++){
        finalTime = min(dpRace[laps][c], finalTime);
    }

    // TC: O(N*T + N^3*T)
    // Space : O(N)
    return finalTime;
}
