#ifndef AP_MS2_SEARCHERSOLUTION_H
#define AP_MS2_SEARCHERSOLUTION_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Solution.h"
#include "State.h"

/**
 * Solution implementation for Maze Graph Type problems.
 * @tparam StateType should be a pair of ints
 * @tparam CostType a double.
 */
template<typename StateType, typename CostType>
class SearcherSolution : public Solution<std::string,CostType> {
private:
    State<StateType, CostType> *fromState;
public:

    SearcherSolution(State<StateType, CostType> *fromState) : fromState(fromState) {}

    /**
     * Get price.
     * @return
     */
    virtual CostType getCost() const {
        if (fromState == NULL) {
            return CostType(-1);
        }
        return fromState->getCost();
    }

    /**
     * Parse and restore a solution.
     * @return
     */
    virtual std::string getValues() const {
        if (fromState == NULL) {
            return std::string("-1");
        }

        std::unordered_map<std::pair<int, int>, std::string, PairHash<int, int>> helperMap;
        helperMap.insert({{0, 1}, "Right"});
        helperMap.insert({{0, -1}, "Left"});
        helperMap.insert({{1, 0}, "Down"});
        helperMap.insert({{-1, 0}, "Up"});

        State<StateType, CostType> *currentState = fromState;
        std::vector<std::string> directions;
        while (currentState->getParentState() != NULL) {
            std::pair<int,int> directionPair = *currentState - *currentState->getParentState();
            directions.push_back(helperMap[directionPair]);
            currentState = currentState->getParentState();
        }
        std::stringstream ss;

        for (auto it = directions.end() - 1; it != directions.begin() - 1; --it) {
            ss << *it;
            if (it != (directions.begin())) {
                ss << ",";
            }
        }
        return std::string(ss.str());
    }
};

#endif //AP_MS2_SEARCHERSOLUTION_H
