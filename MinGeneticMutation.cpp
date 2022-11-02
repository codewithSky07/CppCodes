class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {

        // queue and set defined.
        queue<string> queue;
        unordered_set<string> visited;

        // insert  start node .
        queue.push(start);
        visited.insert(start);

        // declare to step to store ans.
        int steps = 0;

        // BFS..
        while (!queue.empty()) {
            int nodesInQueue = queue.size();

            for (int j = 0; j < nodesInQueue; j++) {
                string node = queue.front();
                queue.pop();

                // if we reached the end.
                if (node == end) {
                    return steps;
                }

                // else do mutation and check for non visited neighbour.
                for (char c: "ACGT") {
                    for (int i = 0; i < node.size(); i++) {

                        // do mutation
                        string mutant = node;
                        mutant[i] = c;
                        // check if it is neighbour
                 if (!visited.count(mutant) && find(bank.begin(), bank.end(), mutant) != bank.end()) {
                            queue.push(mutant);
                            visited.insert(mutant);
                        }
                    }
                }
            }
            // increase the step value.
            steps++;
        }
        // not found.
        return -1;
    }
};
