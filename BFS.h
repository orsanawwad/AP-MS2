//
// Created by USER on 14/01/2019.
//

#ifndef AP_MS2_BFS_H
#define AP_MS2_BFS_H


#include <iostream>
#include <string>
#include <queue>

#include "SearcherSolution.h"
#include "Searcher.h"

template<typename StateType, typename CostType>
class BFS : public Searcher<SearcherSolution<StateType, CostType>, StateType, CostType> {
protected:
    //MyPriorityQueue<State<std::pair<int, int>, double> *, std::vector<State<std::pair<int, int>, double> *>, StateComparator<std::pair<int, int>, double>> priorityQueue;
    std::queue<State<StateType, CostType>*> queue;
public:
    virtual SearcherSolution<StateType, CostType> search(ISearchable<StateType, CostType> *searchable) {

        std::unordered_set<State<StateType, CostType> *, StateHash<StateType, CostType>, StateEqual<StateType, CostType>> closedStates;

        this->numberOfStatesEvaluated = 0;
        State<StateType, CostType> *goalState = searchable->getGoalState();

        this->queue.push(searchable->getInitialState());

        while (!this->queue.empty()) {
            State<StateType, CostType> *currentState = this->queue.front();
            this->queue.pop();
            if (*currentState == *goalState) {
                this->numberOfStatesEvaluated = closedStates.size();

                // State<std::pair<int, int>, double> *test = currentState;

                return SearcherSolution<StateType, CostType>(currentState);
            } else if (closedStates.find(currentState) == closedStates.end()) {

                closedStates.insert(currentState);
                std::unordered_set<State<StateType, CostType> *, StateHash<StateType, CostType>, StateEqual<StateType, CostType>> possibleStates = searchable->getAllPossibleStatesFrom(
                        currentState);
                for (auto state : possibleStates) {
                    queue.push(state);
                }
            }
        }
        return SearcherSolution<StateType, CostType>(NULL);
    }
};

#endif //AP_MS2_BFS_H
