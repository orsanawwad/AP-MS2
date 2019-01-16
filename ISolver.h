#ifndef AP_MS2_ISOLVER_H
#define AP_MS2_ISOLVER_H

namespace server_side {
    /**
     * Solver interface to implement different kinds of solvers.
     * @tparam Problem problem to solve.
     * @tparam Solution solution to solve.
     */
    template<typename Problem, typename Solution>
    class ISolver {
    public:
        virtual Solution solve(Problem problem) = 0;
        virtual ~ISolver() {}
    };
}

#endif //AP_MS2_ISOLVER_H
