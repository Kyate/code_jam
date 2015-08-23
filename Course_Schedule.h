/*There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.*/

class Solution {
public:
 bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
            // build the graph and compute in_degrees
            vector<int>inDegree(numCourses, 0);
            vector<vector<int>> neighbours(numCourses);
            for(int i=0; i<prerequisites.size(); ++i){
                neighbours[prerequisites[i].second].push_back(prerequisites[i].first);
                inDegree[prerequisites[i].first]++;
            }
            
            // find all in_degree==0, and mark them as visited(set inDegree to -1)
            queue<int> stack;
            int count=0;
            for(int i=0; i<numCourses; ++i){
                if(!inDegree[i]){
                    stack.push(i);
                    inDegree[i]=-1; // maked as visited
                    count++;
                }
            }
            // pop a node from queue, decrease the degree of the neighbours and push the degree==0    
            while(!stack.empty()){
                int cur=stack.front(); 
                stack.pop();
                for(int i=0; i<neighbours[cur].size(); ++i) {
                    inDegree[neighbours[cur][i]]--;
                    if(inDegree[neighbours[cur][i]]==0){
                        count++;
                        stack.push(neighbours[cur][i]);
                        inDegree[neighbours[cur][i]]=-1;
                    }
                }
            }
            return (count==numCourses);
    }
  };
