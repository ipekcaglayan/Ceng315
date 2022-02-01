#include "the6.h"
// Don't add any additional includes

/*
  N: Number of racers
  updates: Updates you have heard
*/

using namespace std;


// color 0=white, 1=gray, 2=black

void DfsVisit(int u, vector<int>& parents, vector<vector<int>>& edges, vector<int>& color,
              vector<int>& discoveryTimes, vector<int>& finishingTimes, int& time, bool & containsCycle, vector<int> & path, stack<int>& cyclePath ){
    if(containsCycle){
        return;
    }
    color[u] = 1;
    time++;
    discoveryTimes[u] = time;

    cyclePath.push(u);
    for(int v : edges[u]){
        if(color[v]==0 || color[v] == 1){

            if(color[v]==1 && !containsCycle ){
                containsCycle = true;
                cyclePath.push(v);
                path.push_back(v);
            }
            parents[v] = u;
            DfsVisit(v, parents, edges, color, discoveryTimes, finishingTimes, time, containsCycle, path, cyclePath);
        }
//        if(color[v]==1){
//            containsCycle = true;
//            path.push_back(v);
//        }

    }
    if(!containsCycle){

        cyclePath.pop();

    }
    color[u] = 2;



    finishingTimes[u] = ++time;
    path.push_back(u);





}


std::pair<bool, std::vector<int>>
RaceResult(int N, std::vector<std::pair<int, int>> updates) {
    vector<int> color(N, 0);
    vector<int> parents(N, -1);
    vector<vector<int>> edges(N);
//    vector<int> vertices;
    vector<int> finishingTimes(N,-1);
    vector<int> discoveryTimes(N,0);
    stack<int> cyclePath;
    int time = 0;
    bool containsCycle = false;
//    for(int i=0; i<N;i++){
//        vertices.push_back(i);
//    }

    for(pair<int, int> update :  updates){
        edges[update.first].push_back(update.second);
    }
    vector<int> path;
    for(int i=0; i<N;i++){
        if(color[i]==0){
            DfsVisit(i, parents, edges, color, discoveryTimes, finishingTimes, time, containsCycle, path, cyclePath);
        }
    }

    vector<int> result;
    vector<int> cycleResult;




    if(containsCycle){
        while (!cyclePath.empty()) {
            cycleResult.push_back(cyclePath.top());
            cyclePath.pop();
        }
        int resSize = cycleResult.size();
        if (cycleResult[0] != cycleResult[resSize-1]){
            for(int i=0; i<resSize-1; i++){
                result.push_back(cycleResult[i]);
            }

        }
        else{
            result = cycleResult;
        }

        vector<int> reversed;

        for(int i=result.size()-1; i>=0; i--){
            reversed.push_back(result[i]);
        }
        result = reversed;

        int startVal = result[result.size()-1];
        int startindex = 0;
        if(result[0] != startVal ){
            for(int i=0; i< result.size(); i++){
                if(result[i]==startVal){
                    startindex = i;
                    break;
                }
            }
        }
        vector<int> fixed;
        for(int i=startVal;i<result.size();i++){
            fixed.push_back(result[i]);
        }
        result= fixed;


    }
    else{
        for( int i=path.size()-1; i>=0 ; i--){
            result.push_back(path[i]);
        }

    }

    pair<bool, std::vector<int>> returnVal;

    returnVal.first = containsCycle;
    returnVal.second = result;


    return returnVal; // This is a dummy return value. YOU SHOULD CHANGE THIS!
}

int main(){

    vector<std::pair<int, int>> updates;
//    //test
//    int N=5;
//    updates.push_back(pair<int, int>(0,2));
//    updates.push_back(pair<int, int>(0, 1));
//    updates.push_back(pair<int, int>(1, 3));
//    updates.push_back(pair<int, int>(1, 2));
//    updates.push_back(pair<int, int>(2, 3));

    //test
//    int N=3;
//    updates.push_back(pair<int, int>(0, 1));
//    updates.push_back(pair<int, int>(1, 2));
//    updates.push_back(pair<int, int>(2, 0));

    //test
//    int N=5;
//    updates.push_back(pair<int, int>(0,2));
//    updates.push_back(pair<int, int>(0, 1));
//    updates.push_back(pair<int, int>(1, 3));
//    updates.push_back(pair<int, int>(1, 2));
//    updates.push_back(pair<int, int>(2, 3));
//    updates.push_back(pair<int, int>(3, 0));


    //test
//    int N= 10;
//    updates.push_back(pair<int, int>(0,5));
//    updates.push_back(pair<int, int>(1, 0));
//    updates.push_back(pair<int, int>(1, 7));
//    updates.push_back(pair<int, int>(2, 4));
//    updates.push_back(pair<int, int>(2, 0));
//    updates.push_back(pair<int, int>(3, 4));
//    updates.push_back(pair<int, int>(3,5));
//    updates.push_back(pair<int, int>(3, 7));
//    updates.push_back(pair<int, int>(3, 6));
//    updates.push_back(pair<int, int>(4, 7));
//    updates.push_back(pair<int, int>(4, 1));
//    updates.push_back(pair<int, int>(6, 2));
//    updates.push_back(pair<int, int>(6, 5));
//    updates.push_back(pair<int, int>(6, 9));
//    updates.push_back(pair<int, int>(7, 9));
//    updates.push_back(pair<int, int>(7, 5));
//    updates.push_back(pair<int, int>(7, 3));
//    updates.push_back(pair<int, int>(8, 3));

    // test
    int N= 10;
    updates.push_back(pair<int, int>(0,5));
    updates.push_back(pair<int, int>(1, 0));
    updates.push_back(pair<int, int>(1, 7));
    updates.push_back(pair<int, int>(2, 4));
    updates.push_back(pair<int, int>(2, 0));
    updates.push_back(pair<int, int>(3, 4));
    updates.push_back(pair<int, int>(3,5));
    updates.push_back(pair<int, int>(3, 7));
    updates.push_back(pair<int, int>(3, 6));
    updates.push_back(pair<int, int>(4, 7));
    updates.push_back(pair<int, int>(4, 1));
    updates.push_back(pair<int, int>(6, 2));
    updates.push_back(pair<int, int>(6, 5));
    updates.push_back(pair<int, int>(6, 9));
    updates.push_back(pair<int, int>(7, 9));
    updates.push_back(pair<int, int>(7, 5));
    updates.push_back(pair<int, int>(7, 3));
    updates.push_back(pair<int, int>(8, 3));

    pair<bool, std::vector<int>> returnVal;

    returnVal = RaceResult(N, updates);
    cout<<"Contains Cycle: "<< returnVal.first<<endl;
    for(int i=0 ; i< returnVal.second.size();i++){
        cout<<returnVal.second[i]<<" ";
    }
    cout<<endl;
    return 0;
}
