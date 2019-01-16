#ifndef AP_MS2_SOLUTION_H
#define AP_MS2_SOLUTION_H

/**
 * To adapt SOLID princible, Solution is used to take a state, and restore a solution to the user.
 * @tparam ReturnType
 * @tparam CostType
 */
template<typename ReturnType, typename CostType>
class Solution {
public:

    /**
     * Get cost of current solution.
     * @return State's cost.
     */
    virtual CostType getCost() const = 0;

    /**
     * Get the processed solution.
     * @return state's type.
     */
    virtual ReturnType getValues() const = 0;
    virtual ~Solution() {}
};

template<typename ReturnType, typename CostType>
bool operator<(const Solution<ReturnType, CostType>& lhs, const Solution<ReturnType, CostType>& rhs) {
    const auto lcost = lhs.getCost();
    const auto rcost = rhs.getCost();
    return lcost < rcost;
}

template<typename ReturnType, typename CostType>
bool operator>(const Solution<ReturnType, CostType>& lhs, const Solution<ReturnType, CostType>& rhs) {
    const auto lcost = lhs.getCost();
    const auto rcost = rhs.getCost();
    return lcost > rcost;
}

template<typename ReturnType, typename CostType>
bool operator<=(const Solution<ReturnType, CostType>& lhs, const Solution<ReturnType, CostType>& rhs) {
    const auto lcost = lhs.getCost();
    const auto rcost = rhs.getCost();
    return lcost <= rcost;
}

template<typename ReturnType, typename CostType>
bool operator>=(const Solution<ReturnType, CostType>& lhs, const Solution<ReturnType, CostType>& rhs) {
    const auto lcost = lhs.getCost();
    const auto rcost = rhs.getCost();
    return lcost >= rcost;
}

#endif //AP_MS2_SOLUTION_H
