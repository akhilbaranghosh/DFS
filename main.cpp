#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node(int value){
        this->value=value;
    }
    Node(){}
};
class Stack{
    int* arr;
    int tos;
public:
    Stack(int n){
        arr=new int[n];
        tos=-1;
    }
    void push(int n){
        arr[tos++]=n;
    }
    int pop(){
        int value;
        if(tos==0) {
            value = arr[0];
            tos = -1;
        }
        else {
            value = arr[tos--];
        }
        return value;
    }
    bool isEmpty(){
        return tos!=-1;
    }
    int top(){
        return arr[tos];
    }

};
class DFS{
public:
    int vertices;
    int edges;
    bool *isMarked;
    int **graph;
    Stack*s ;
    DFS(int edges,int vertices){
        this->edges=edges;
        this->vertices=vertices;
        graph=new int*[vertices];
        for(int i=0;i<vertices;i++)graph[i]=new int[vertices];
        s=new Stack(vertices*vertices);
        isMarked=new bool[vertices];
    }
    void setGraph(){
        int x,y;
        cout<<"Enter the number of vertices"<<endl;
        //cout<<"Press -1 -1 to continue"<<endl;
       // int v=vertices;
        for(int i=0;;i++){
            cin>>x>>y;
            if(x==-1||y==-1)break;
            graph[x][y]=1;
            graph[y][x]=1;
        }
        for(int i=0;i<vertices;i++){
            isMarked[i]= true;
        }
    }
    void dfs(int start){
        isMarked[start]=false;
        s->push(start);
        //cout<<start<<" ";
        int next;
        for(int i=0;s->isEmpty();i++){
            next=s->top();
            cout<<next<<" ";
            for(int j=0;j<vertices;j++){
                if(graph[next][j]==1&&isMarked[j]){
                    s->push(graph[next][j]);
                    isMarked[j]=false;
                    break;
                }
            }
            if(next==s->top())next=s->pop();
        }
    }
};
int main() {
    int vertices,edges;
    cout<<"Enter the Vertices and Edges";
    cin>>vertices>>edges;
    DFS* obj=new DFS(vertices,edges);

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            obj->graph[i][j]=0;
        }
        cout<<endl;
    }

    obj->setGraph();
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<obj->graph[i][j]<<" ";
        }
        cout<<endl;
    }
    obj->dfs(0);
}