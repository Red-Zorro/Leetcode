#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
            return NULL;
        queue<UndirectedGraphNode *> q;
		unordered_map<int,UndirectedGraphNode*> labelSet;
		q.push(node);
		while(!q.empty()){
			UndirectedGraphNode *tmp = q.front();
			q.pop();
			UndirectedGraphNode *pt = new UndirectedGraphNode(tmp->label);
			labelSet.insert(make_pair(pt->label,pt));			
			for(int i=0;i<tmp->neighbors.size();i++){
				if(labelSet.find(tmp->neighbors[i]->label) == labelSet.end()){
					q.push(tmp->neighbors[i]);
				}
			}
		}
		q.push(node);
		while(!q.empty()){
			UndirectedGraphNode *tmp = q.front();
			q.pop();
			UndirectedGraphNode *pt = labelSet[tmp->label];
			if(pt->neighbors.empty()&&!tmp->neighbors.empty()){
    			for(int i=0; i<tmp->neighbors.size();i++){
    				pt->neighbors.push_back(labelSet[tmp->neighbors[i]->label]);
					q.push(tmp->neighbors[i]);
			    }
			}
		}
		return labelSet[node->label];
    }
};

int main(void)
{
    cout<<"test"<<endl;
    return 0;
}
