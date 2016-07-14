/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 *///支持两节点之间多条边，
class Solution {
private:
UndirectedGraphNode *clone_root;
map<int,UndirectedGraphNode *> nei_label;//记录构造过的节点，以label为键，防止重复构造
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        clone_root=clone(node);
		return clone_root;
    }
	UndirectedGraphNode *clone(UndirectedGraphNode *node)
	{
		if(node!=NULL)
		{
			UndirectedGraphNode *clone_node=new UndirectedGraphNode(node->label);
			UndirectedGraphNode *r_node;
			//static map<int,UndirectedGraphNode *> nei_label;递归函数中静态变量？？
			for(int i=0;i<node->neighbors.size();++i)
			{
				if(node->neighbors[i]->label==node->label)
				    clone_node->neighbors.push_back(clone_node);
				else{
				    if(nei_label.find(node->neighbors[i]->label)!=nei_label.end())//之前已经递归构造过该节点
				        {
				            r_node=(nei_label.find(node->neighbors[i]->label))->second;
				            clone_node->neighbors.push_back(r_node);
				        
				        }
				    else
				    {
				        r_node=clone(node->neighbors[i]);
				        nei_label.insert(pair<int,UndirectedGraphNode *>(node->neighbors[i]->label,r_node));
				        clone_node->neighbors.push_back(r_node);
				        
				    }
				}
			}
			return clone_node;
		}
		else
		{
			return NULL;
		}
	}
};