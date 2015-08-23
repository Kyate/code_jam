/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 
 class Solution {
    private:
        map<int,UndirectedGraphNode *> f;
    public:
        UndirectedGraphNode* clone(UndirectedGraphNode *node){
            if(node==NULL) return NULL;
            if(f.count(node->label)) return f[node->label];
            UndirectedGraphNode *temp=new UndirectedGraphNode(node->label);
            f.insert(make_pair(node->label,temp));
            for(int i=0;i<int((node->neighbors).size());i++)
                temp->neighbors.push_back(clone(node->neighbors[i]));
            return temp;
        }
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            return clone(node);
        }
    };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        
        unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> clone_map; 
        stack<UndirectedGraphNode *> neigbors_stack;
        
        //create the root node, and set it as added, and push all neighbors into stack.
        UndirectedGraphNode *clone_node = new  UndirectedGraphNode(node->label);
        clone_map[node] = clone_node;
        neigbors_stack.push(node);
        
         //for all other nodes in the graph except the first graph root node.
        while(!neigbors_stack.empty())
        {
            //pop the node
            UndirectedGraphNode *curr_vertex_node =neigbors_stack.top();
            neigbors_stack.pop();
            UndirectedGraphNode *clone_curr_node = clone_map[curr_vertex_node];
            for(int i = 0;i<curr_vertex_node->neighbors.size();i++)
            {
                if(clone_map.find(curr_vertex_node->neighbors[i]) == clone_map.end())//not found.
                {
                    //push the unknown node into stack
                    neigbors_stack.push(curr_vertex_node->neighbors[i]);
                    //create the new node from curr neighbor.
                    UndirectedGraphNode *tmp = new  UndirectedGraphNode(curr_vertex_node->neighbors[i]->label);
                    clone_map[curr_vertex_node->neighbors[i]] = tmp;
                    //connection 
                    clone_curr_node->neighbors.push_back(tmp);
                }
                else //found, just connect with clone graph node.
                {
                     UndirectedGraphNode *tmp =  clone_map[curr_vertex_node->neighbors[i]];
                     clone_curr_node->neighbors.push_back(tmp);
                }
            }
        }
        
        return clone_node;
    }
};
