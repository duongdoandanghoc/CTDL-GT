#include <iostream>  
#include <queue>  
#include <stack>  

using namespace std;  

class Graph {  
private:  
    int** adjMatrix; 
    int numVertices; 

public:  
    Graph(int vertices) {  
        numVertices = vertices;  
        adjMatrix = new int*[numVertices];  
        for (int i = 0; i < numVertices; i++) {  
            adjMatrix[i] = new int[numVertices];  
            for (int j = 0; j < numVertices; j++) {  
                adjMatrix[i][j] = 0;   
            }  
        }  
    }  

    ~Graph() {  
        for (int i = 0; i < numVertices; i++) {  
            delete[] adjMatrix[i];  
        }  
        delete[] adjMatrix;  
    }  

    void addEdge(int start, int end) {  
        adjMatrix[start][end] = 1;   
        adjMatrix[end][start] = 1;   
    }  

    void BFS(int start) {  
        bool* visited = new bool[numVertices];  
        for (int i = 0; i < numVertices; i++) {  
            visited[i] = false;  
        }  

        queue<int> q;  
        visited[start] = true; 
        q.push(start);  

        cout << "Duyệt BFS: ";  
        while (!q.empty()) {  
            int currentVertex = q.front();  
            q.pop();  
            cout << currentVertex << " ";   

           
            for (int i = 0; i < numVertices; i++) {  
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {  
                    visited[i] = true;   
                    q.push(i);  
                }  
            }  
        }  
        cout << endl;  
        delete[] visited;  
    }  

    void DFS(int start) {  
        bool* visited = new bool[numVertices];  
        for (int i = 0; i < numVertices; i++) {  
            visited[i] = false;
        }  

        stack<int> s;  
        s.push(start);  

        cout << "Duyệt DFS: ";  
        while (!s.empty()) {  
            int currentVertex = s.top();  
            s.pop();  

            if (!visited[currentVertex]) {  
                visited[currentVertex] = true;   
                cout << currentVertex << " ";  
            }  

            for (int i = numVertices - 1; i >= 0; i--) {  
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {  
                    s.push(i);  
                }  
            }  
        }  
        cout << endl;  
        delete[] visited;  
    }  

    void inputGraph() {  
        int edges;  
        cout << "Nhập số lượng cạnh của đồ thị: ";  
        cin >> edges;  

        cout << "Nhập các cạnh (khai báo dạng: bắt đầu kết thúc):\n";  
        for (int i = 0; i < edges; i++) {  
            int start, end;  
            cin >> start >> end;  
            addEdge(start, end);  
        }  
    }  
};
int main() {  
    int numVertices;  
    cout << "Nhập số lượng đỉnh: ";  
    cin >> numVertices;  

    Graph g(numVertices);  

    g.inputGraph(); 
    int startVertex;  
    cout << "Nhập đỉnh bắt đầu để duyệt BFS và DFS: ";  
    cin >> startVertex;  

    g.BFS(startVertex); 
    g.DFS(startVertex);  

    return 0;  
}