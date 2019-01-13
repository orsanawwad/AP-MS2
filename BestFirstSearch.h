#ifndef AP_MS2_BESTFIRSTSEARCH_H
#define AP_MS2_BESTFIRSTSEARCH_H

#include <queue>
#include <iostream>
#include <string>

#include "Searcher.h"

template<typename StateType, typename CostType>
class BestFirstSearch : public Searcher<StateType, CostType> {
private:
//    unsigned long numberOfStatesEvaluated = 0;
    MyPriorityQueue<State<StateType,CostType>> priorityQueue;
public:
    virtual ISolution search(ISearchable<StateType, CostType> searchable) {

        std::unordered_set<State<StateType,CostType>, StateHash<StateType,CostType>> closedStates;

        this->numberOfStatesEvaluated = 0;
        State<StateType,CostType> goalState = searchable.getGoalState();

        this->priorityQueue.push(searchable.getInitialState());

        while(!this->priorityQueue.empty()) {
            State<StateType,CostType> currentState = this->priorityQueue.pop();
            closedStates.insert(currentState);
            if (currentState == goalState) {
                std::cout << "FOUND" << std::endl;
                // Return Path
                this->numberOfStatesEvaluated = closedStates.size();
            };

            std::unordered_set<State<StateType,CostType>> possibleStates = searchable.getAllPossibleStatesFrom(currentState);

            for (auto state : possibleStates) {
                if (closedStates.find(state) == closedStates.end() && this->priorityQueue.find(state) == this->priorityQueue.end()) {
//                     state.setCameFrom(currentState);
                    this->priorityQueue.push(state);
                } else if (this->priorityQueue.find(state) != this->priorityQueue.end()) {
                    State<StateType, CostType> stateToCompare = *this->priorityQueue.find(state);
                    if (state.getCost() < stateToCompare.getCost()) {
                        this->priorityQueue.remove(stateToCompare);
                        this->priorityQueue.push(state);
                    }
                }
            }

        }

//        SolutionType a;

        return NULL;
    }
};

#endif //AP_MS2_BESTFIRSTSEARCH_H
