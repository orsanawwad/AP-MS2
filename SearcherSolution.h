//
// Created by Orsan Awwad on 13/01/2019.
//

#ifndef AP_MS2_SEARCHERSOLUTION_H
#define AP_MS2_SEARCHERSOLUTION_H

#include <string>
#include <vector>
#include <unordered_map>

#include "Solution.h"
#include "State.h"

template<typename StateType, typename CostType>
class SearcherSolution : public Solution<std::string> {
private:
    std::unordered_map<std::pair<int, int>, std::string, PairHash<int, int>> helperMap;
    State<StateType, CostType> *fromState;
public:

    SearcherSolution(State<StateType, CostType> *fromState) : fromState(fromState) {
        helperMap.insert({{0, 1}, "Right"});
        helperMap.insert({{0, -1}, "Left"});
        helperMap.insert({{1, 0}, "Down"});
        helperMap.insert({{-1, 0}, "Up"});
    }


    virtual std::string getValues() {
        State<StateType, CostType> *currentState = fromState;
        std::vector<std::string> directions;
        while (currentState->getParentState() != NULL) {
            std::pair<int, int> directionPair(
                    {currentState->getState().first - currentState->getParentState()->getState().first,
                     currentState->getState().second - currentState->getParentState()->getState().second});
            directions.push_back(helperMap[directionPair]);
            currentState = currentState->getParentState();
        }
        std::stringstream ss;

        for (auto it = directions.begin(); it != directions.end(); ++it) {
            ss << *it;
            if (it != (
                    directions.end() - 1)) {
                ss << ",";
            }
        }

//        for (auto direction : directions) {
//            ss << direction << ",";
//        }
        return std::string(ss.str());
    }
};

#endif //AP_MS2_SEARCHERSOLUTION_H
