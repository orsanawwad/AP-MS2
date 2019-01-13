#ifndef AP_MS2_STATE_H
#define AP_MS2_STATE_H

#include <iostream>

template<typename StateType, typename CostType>
class State {
private:
    StateType state;
    CostType cost;
    State* cameFrom;
public:
    State(StateType state, CostType cost) : state(state), cost(cost) {}

    bool equalsTo(State<StateType,CostType> stateToCompare) { return stateToCompare.state == this->state; };

    void setCameFrom(State *cameFrom) {
        this->cameFrom = cameFrom;
    }

    bool operator==(const State &rhs) const {
        return state == rhs.state;
    }

    bool operator<(const State &rhs) const {
        return cost > rhs.cost;
    }

    StateType getState() const {
        return state;
    }

    CostType getCost() const {
        return cost;
    }

    void setCost(CostType cost) {
        this->cost = cost;
    }
};

template<typename StateType, typename CostType>
struct StateHash {
    std::size_t operator()(const State<StateType, CostType>& _state) const {
        return std::hash<std::string>()(_state.getState());
    }
};

#endif //AP_MS2_STATE_H
