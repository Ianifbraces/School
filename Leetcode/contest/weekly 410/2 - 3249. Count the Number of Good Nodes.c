# https://leetcode.com/problems/count-the-number-of-good-nodes/description/

# Difficulty: Medium

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        for (const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        good_nodes = 0;
        dfs(0,-1);
        return good_nodes;
    }
private:
    unordered_map<int, vector<int>> tree;
    int good_nodes;

    int dfs(int node, int parent){
        int subtree_size = 1;
        vector<int> child_size;

        for (int child : tree[node]){
            if (child == parent){
                continue;
            }
            int size = dfs(child, node);
            subtree_size += size;
            child_size.push_back(size);
        }

        if (unordered_set<int>(child_size.begin(), child_size.end()).size() <= 1) {
            good_nodes++;
        }

        return subtree_size;
    }
};