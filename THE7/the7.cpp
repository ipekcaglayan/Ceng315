#include "the7.h"

using namespace  std;
int minDistance(vector<int>& vertices, vector<int> & distances, vector<bool> & visited){
    int cost = INT_MAX;
    int returnIndex;
    for(int x: vertices){
//        cout<<"to: "<<to<<"is to visited: "<<visited[to]<<endl;
        if( !visited[x] && distances[x] <= cost){
//            cout<<"if icindeyiz to: "<<to<<"is to visited: "<<visited[to]<<endl;
            cost = distances[x];
            returnIndex = x;
        }
    }
//    cout<<"returnIndex: "<<returnIndex<<endl;
//    cout<<"is visited selected: "<<visited[returnIndex]<<endl;
    visited[returnIndex]=true;


    return returnIndex;
}

void fillPath( vector<int> & parents, int j, vector<int>& path){
    if(parents[j]==-1){
//        cout<<"Parent -1: "<<j<<endl;
//        path.push_back(j);
        return;
    }

    fillPath(parents, parents[j], path);
//    cout<<"j: "<<j<<endl;
    path.push_back(j);

}



int dijkstra(vector<int>& weights, vector<vector<int>> &adj, vector<int>& vertices, vector<int>& path, int n, int src, int dest){
    vector<int> parents(n, -1);
    int cost = INT_MAX;
    vector<int> distances(n, cost);
    distances[src]=0;
    vector<bool> visited(n, false);
    for(int x: vertices){
        int selected = minDistance(vertices, distances, visited);
//        cout<<"selected: "<< selected<<" for x= "<<x<<endl;
//        cout<<"Before distance: "<<distances[selected]<<endl;
        for(int a: adj[selected]){
            if(distances[selected]+weights[selected*n+a]< distances[a]){
                distances[a] = distances[selected]+weights[selected*n+a];
                parents[a] = selected;
//                cout<<"PArents["<<a<<"] = "<<selected<<endl;

//                cout<<"After distance: "<<distances[selected]<<endl;


            }
        }

    }
    fillPath(parents, dest, path);

    cout<<"shortest path from "<< src<< " to "<<dest<<" = "<<distances[dest]<<endl;
    return distances[dest];
}



void FindRoute(int n, std::vector<Road> roads, int s, int d, int x, int y) {
  // You can change these variables. These are here for demo only.
  std::vector<int> path;
  int cost = INT_MAX;

//  vector<int> parents(n,-1);

  vector<int> vertices(n);
  for(int i=0;i<n;i++){
      vertices[i]=i;
  }

  // Write your code here...

  vector<int> weights(n*n, 0);
  vector<vector<int>> adj(n);

  for(Road r: roads){
      int u = r.endpoints.first;
      int v = r.endpoints.second;
      adj[u].push_back(v);
      adj[v].push_back(u);
      weights[v*n+u] = r.time;
      weights[u*n+v] = r.time;
  }
  vector<int> path1;
  vector<int> path2;
  int s_x_y_d = dijkstra(weights, adj, vertices, path1, n, s, x) + dijkstra(weights, adj, vertices, path1, n, x, y) + dijkstra(weights, adj, vertices, path1, n, y, d);
  int s_y_x_d = dijkstra(weights, adj, vertices, path2, n, s, y) + dijkstra(weights, adj, vertices, path2, n, y, x) + dijkstra(weights, adj, vertices, path2, n, x, d);

  cout<<s_x_y_d<<endl;
  cout<<s_y_x_d<<endl;

//  cout<<"path"<<endl;
  if(s_x_y_d < s_y_x_d){
//      fillPath(parents1, d, path);
      cost = s_x_y_d;
      std::cout << cost << " ";
      cout<<s<<"->";
      PrintRange(path1.begin(), path1.end());

  }
  else{
//      fillPath(parents2, d, path);
      cost = s_y_x_d;
      std::cout << cost << " ";
      cout<<s<<"->";
      PrintRange(path2.begin(), path2.end());

  }

  // Your output should be like this. You can change this as long as you keep
  // the output format. PrintRange function helps you print elements of
  // containers with iteratos (e.g., std::vector).

//  std::cout << std::endl;
}

int main(){
    std::vector<Road> roads;
//    roads.push_back(Road(make_pair(0,1),35));
//    roads.push_back(Road(make_pair(0,2),12));
//    roads.push_back(Road(make_pair(1,3),16));
//    roads.push_back(Road(make_pair(2,3),19));
//    roads.push_back(Road(make_pair(3,4),18));
//    FindRoute(5, roads, 0, 4,1,2);

//    roads.push_back(Road(make_pair(0,1),13));
//    roads.push_back(Road(make_pair(0,2),13));
//    roads.push_back(Road(make_pair(0,3),18));
//    roads.push_back(Road(make_pair(1,2),19));
//    roads.push_back(Road(make_pair(1,3),10));
//    roads.push_back(Road(make_pair(1,4),18));
//    roads.push_back(Road(make_pair(2,3),13));
//    roads.push_back(Road(make_pair(2,4),20));
//    roads.push_back(Road(make_pair(3,4),18));
//
//        FindRoute(5, roads, 3, 2,1,4);

//    roads.push_back(Road(make_pair(3,4),18));


//    roads.push_back(Road(make_pair(0,6),11));
//    roads.push_back(Road(make_pair(0,1),18));
//    roads.push_back(Road(make_pair(1,3),19));
//    roads.push_back(Road(make_pair(1,4),16));
//    roads.push_back(Road(make_pair(2,3),10));
//    roads.push_back(Road(make_pair(3,4),10));
//    roads.push_back(Road(make_pair(5,6),11));
//    FindRoute(8, roads, 1, 3,5,4);

    int n;
    cin>>n;
    int s,d,x,y,m;
    cin>>s;
    cin>>d;
    cin>>x;
    cin>>y;
    cin>>m;
    int e1,e2,t;
    for(int i=0;i<m;i++){
        cin>>e1;
        cin>>e2;
        cin>>t;
        roads.push_back(Road(make_pair(e1,e2),t));

    }
    FindRoute(n, roads, s, d,x,y);





//    for(Road r: roads){
//        cout<<r.endpoints.first<<" "<<r.endpoints.second<<" "<<r.time<<endl;
//    }

    return 0;
}