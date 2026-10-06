#include "winners.hpp"
#include <cmath>
#include <numeric>

float nearestScore2Average(const vector<float>& scores) {
    if (scores.empty()) return 0.0;

    float average = accumulate(scores.begin(), scores.end(), 0.0f) / scores.size();

    float nearest = scores[0];
    float smallestDiff = fabs(scores[0] - average);

    for (float score : scores) {
        float diff = fabs(score - average);
        if (diff < smallestDiff) {
            smallestDiff = diff;
            nearest = score;
        }
    }
    return nearest;
}

float furthestScoreFromWinner(const vector<float>& scores) {
    if (scores.empty()) return 0.0;

    float winner = nearestScore2Average(scores);

    float furthest = scores[0];
    float largestDiff = fabs(scores[0] - winner);

    for (float score : scores) {
        float diff = fabs(score - winner);
        if (diff > largestDiff) {
            largestDiff = diff;
            furthest = score;
        }
    }
    return furthest;
}
