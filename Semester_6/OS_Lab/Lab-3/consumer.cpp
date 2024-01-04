/*
Assignment-3
Group Members:
Atishay Jain-20CS3008
Gaurav Malakar-20CS10029
Monish Natrajan-20CS30033
Roopak Priydarshi-20CS30042
*/

// print shortest path to a node
void path_to_node(vector<int> &parent, int node, FILE *fp)
{
    // if node is not reachable from any source node
    if (parent[node] == -1)
    {
        return;
    }
    fprintf(fp, "%d: ", node);
    vector<int> path;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(node);

    while (path.size() > 1)
    {
        fprintf(fp, "%d --> ", path.back());
        path.pop_back();
    }
    fprintf(fp, "%d\n\n", path.back());
}

// Finds shortest path for each node form the source nodes
void consumer(int *graph, int n, int *slot, string filename)
{

    const int slot_size = slot[0]; // number of source nodes

    FILE *fp;
    fp = fopen(filename.c_str(), "w");

    fprintf(fp, "Source Nodes:  ");
    for (int i = 1; i <= slot_size; ++i)
    {
        fprintf(fp, "%d ", slot[i]);
    }
    fprintf(fp, "\n\n\nShortest Paths:-\n\n");

    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    minpq pq; // min priority queue

    for (int i = 1; i <= slot_size; ++i)
    {
        int node = slot[i];
        dist[node] = 0;
        parent[node] = node;
    }
    for (int i = 0; i < n; ++i)
    {
        pq.push({dist[i], i});
    }

    // dijkstra's algorithm
    while (!pq.empty())
    {
        vector<int> pq_top = pq.top();
        int u = pq_top[1];
        pq.pop();

        int *temp = graph + u * MAX_DEGREE;
        int deg = temp[0];
        for (int i = 1; i <= deg; ++i)
        {
            int v = temp[i];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == 0)
            continue;
        path_to_node(parent, i, fp);
    }
    fclose(fp);
}

// Finds shortest path for each node form the source nodes (OPTIMIZED)
void consumer_optimized(int *graph, int n, int *slot, int *shared_dist, int *shared_parent, string filename)
{
    const int slot_size = slot[0]; // number of source nodes

    FILE *fp;
    fp = fopen(filename.c_str(), "w");

    fprintf(fp, "Source Nodes:  ");
    for (int i = 1; i <= slot_size; ++i)
    {
        fprintf(fp, "%d ", slot[i]);
    }
    fprintf(fp, "\n\n\nShortest Paths:-\n\n");

    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    minpq pq;

    for (int i = 1; i <= slot_size; ++i)
    {
        int node = slot[i];
        dist[node] = 0;
        parent[node] = node;
    }

    // update dist and parent from shared memory (Optimization Step)
    for (int i = 0; i < n; ++i)
    {
        dist[i] = min(shared_dist[i], dist[i]);
        if (dist[i] != INF && parent[i] == -1)
            parent[i] = shared_parent[i];
        pq.push({dist[i], i});
    }

    // dijkstra's algorithm
    while (!pq.empty())
    {
        vector<int> pq_top = pq.top();
        int u = pq_top[1];
        pq.pop();

        int *temp = graph + u * MAX_DEGREE;
        int deg = temp[0];
        for (int i = 1; i <= deg; ++i)
        {
            int v = temp[i];
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // print shortest path to each node
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == 0)
            continue;
        path_to_node(parent, i, fp);
    }
    fclose(fp);

    // update shared memory
    for (int i = 0; i < n; ++i)
    {
        shared_dist[i] = dist[i];
        shared_parent[i] = parent[i];
    }
}