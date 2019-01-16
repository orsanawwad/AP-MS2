#include "SearchableSolverAdapter.h"
#include "BFS.h"
#include "DFS.h"
#include "AstarAlgo.h"
#include "BestFirstSearch.h"


std::string SearchableSolverAdapter::solve(ISearchable<std::pair<int, int>, double> *searchable) {

    /**
     * Init 4 algos
     */

    BFS<std::pair<int,int>,double> bfs;
    DFS<std::pair<int,int>,double> dfs;
    BestFirstSearch<std::pair<int,int>,double> bestFirstSearch;
    AstarAlgo<std::pair<int,int>,double> aStarAlgo;


    /**
     * Get 4 solutions
     */
    auto solution1 = bfs.search(searchable);
    auto solution2 = dfs.search(searchable);
    auto solution3 = bestFirstSearch.search(searchable);
    auto solution4 = aStarAlgo.search(searchable);

    /**
     * Find the minimal
     */
    auto finalSolution = std::min(std::min(solution1,solution2),std::min(solution3,solution4));

    std::cout << solution1.getCost() << "," << bfs.getNumberOfStatesEvaluated() << std::endl;
    std::cout << solution2.getCost() << "," << dfs.getNumberOfStatesEvaluated() << std::endl;
    std::cout << solution3.getCost() << "," << bestFirstSearch.getNumberOfStatesEvaluated() << std::endl;
    std::cout << solution4.getCost() << "," << aStarAlgo.getNumberOfStatesEvaluated() << std::endl;

//    std::cout << searchable->getSize() << "," << bfs.getNumberOfStatesEvaluated() << "," << dfs.getNumberOfStatesEvaluated() << "," << bestFirstSearch.getNumberOfStatesEvaluated() << "," << aStarAlgo.getNumberOfStatesEvaluated() << std::endl;


    /**
     * Return it.
     */
    return finalSolution.getValues();
}
