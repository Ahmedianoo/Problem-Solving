#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


// time: O(n + p), space: O(n + p), v + e 
unordered_set<int> visitedSet;
unordered_map<int, vector<int>>  preMap;

bool dfs(int crs){
    if(visitedSet.count(crs)) return false;
    if(preMap[crs].empty()) return true;

    visitedSet.insert(crs);
    for(int pre : preMap[crs])
        if(!dfs(pre)) 
            return false;

    visitedSet.erase(crs);
    preMap[crs] = {};

    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for(int i = 0; i < numCourses; i++)
        preMap[i] = {};

    for(vector<int> pre : prerequisites)
        preMap[pre[0]].push_back(pre[1]);

    for(int i = 0; i < numCourses; i++)
        if(!dfs(i)) return false;
    
    return true;
}

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false

// Input: numCourses = 3, prerequisites = [[1,0],[0,2], [2, 1]]
// 0: 2
// 1: 0, 2
// 2: 1, 0
// Output: false

// ================= straight forward solution ===================
// the first element is the course, the second is the prerequisite
// there is numCourses, 
//      not all the courses must have prerequisites
//      so, why the number of courses is given here?, why is it useful?
// 
// for the prerequisites
//      we can traverse it 
//
// i think there is a case that this clash happens and when it does, we cannot solve the problem
//      if i have no prerequisites, this is ok
//      the problem when a circle happens, when a deadlock comes to life
//      good, how to detect this deadlock
//
// detecting this deadlock
//      it could be straight forward like the given testcase
//          when two courses are prerequisites to each other
//      this chain could be longer than just a direct realtion like this, thinking of each course having a list
// 
// it could be done like this 
//      we will be traversing the prerequisites, each loop we have two numbers, at pos 0 and pos 1
//      pos 0 is the current course, pos 1 is the prerequisite
//      suppose this prerequisite has a list of prerequisites, this list should not have the course at pos 0
//      this will solve it if it is a direct relation
// we could do another thing, we could the all the prerequisites in this list, not just the direct ones
//      for each element, add the prerequisites of its prerequisite, in this this current element
// adjacency list, a graph, detect a cycle