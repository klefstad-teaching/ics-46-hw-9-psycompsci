#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int V = G.numVertices;
    vector<int> distances(V, INF);
    vector<bool> visited(V, false);
    distances[source] = 0;
    previous.assign(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});
    while(!minHeap.empty()){
        int current_distance = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;

        for(Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if(!visited[v] && current_distance + weight < distances[v]) {
                distances[v] = current_distance + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
        
    }
    return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> v;
    stack<int> stk;

    for(int i = destination; i != -1;){
        stk.push(i);
        i = previous[i]; //going in reverse direction from destination towards source
    }

    while(!stk.empty()){
        v.push_back(stk.top());
        stk.pop();
    }
    return v;
}
void print_path(const vector<int>& v, int total) {
    if(v.empty()) return;
    //path
    int path_size = v.size();
    for(int i = 0; i < path_size; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
