#ifndef AP_MS2_BESTFIRSTSEARCH_H
#define AP_MS2_BESTFIRSTSEARCH_H

#include "MyPriorityQueue.h"
#include <iostream>
#include <string>

#include "SearcherSolution.h"
#include "Searcher.h"

template<typename StateType, typename CostType>
class BestFirstSearch : public Searcher<SearcherSolution<StateType, CostType>, StateType, CostType> {
protected:
    MyPriorityQueue<State<StateType, CostType> *, std::vector<State<StateType, CostType> *>, StateComparator<StateType, CostType>> priorityQueue;
public:
    virtual SearcherSolution<StateType, CostType> search(ISearchable<StateType, CostType> *searchable) {

        std::unordered_set<State<StateType, CostType> *, StateHash<StateType, CostType>, StateEqual<StateType, CostType>> closedStates;

        this->numberOfStatesEvaluated = 0;
        State<StateType, CostType> *goalState = searchable->getGoalState();

        this->priorityQueue.push(searchable->getInitialState());

        while (!this->priorityQueue.empty()) {
            State<StateType, CostType> *currentState = this->priorityQueue.top();
            this->priorityQueue.pop();
            if (*currentState == *goalState) {
                this->numberOfStatesEvaluated = closedStates.size();

                return SearcherSolution<StateType, CostType>(currentState);
            };
            closedStates.insert(currentState);

            std::unordered_set<State<StateType, CostType> *, StateHash<StateType, CostType>, StateEqual<StateType, CostType>> possibleStates = searchable->getAllPossibleStatesFrom(
                    currentState);

            for (auto state : possibleStates) {
                if (closedStates.find(state) == closedStates.end() &&
                    this->priorityQueue.find(state) == this->priorityQueue.end()) {
                    this->priorityQueue.push(state);
                } else if (this->priorityQueue.find(state) != this->priorityQueue.end()) {
                    State<StateType, CostType> *stateToCompare = *this->priorityQueue.find(state);;
                    if (state->getCost() < stateToCompare->getCost()) {
                        this->priorityQueue.remove(stateToCompare);
                        this->priorityQueue.push(state);
                    }
                }
            }
        }

        return SearcherSolution<StateType, CostType>(NULL);
    }
};

#endif //AP_MS2_BESTFIRSTSEARCH_H
