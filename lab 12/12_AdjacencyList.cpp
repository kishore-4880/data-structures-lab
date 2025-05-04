#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacency_list;

public:
    Graph(int);
    bool insert(int, int);
    int remove(int, int);
    bool search(int, int);
    void display();
};

int main()
{
    int choice;
    int x, y, result, vertices;
    cout << "\n Enter number of vertices : ";
    cin >> vertices;
    Graph graph(vertices);
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter vertices : ";
            cin >> x >> y;
            if (graph.insert(x, y))
            {
                cout << "Insertion successful." << endl;
            }
            else
            {
                cout << "Insertion failed." << endl;
            }
            break;

        case 2:
            cout << "Enter vertices : ";
            cin >> x >> y;
            result = graph.remove(x, y);
            if (result == 1)
            {
                cout << "Deletion successful." << endl;
            }
            else if (result == 0)
            {
                cout << "Deletion failed. Edge does not exist." << endl;
            }
            else
            {
                cout << "Deletion failed. Vertices out of bounds." << endl;
            }
            break;

        case 3:
            cout << "Enter vertices : ";
            cin >> x >> y;
            result = graph.search(x, y);
            if (result)
            {
                cout << "Edge found." << endl;
            }
            else
            {
                cout << "Edge does not exist." << endl;
            }
            break;

        case 4:
            graph.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 5);
}

Graph::Graph(int num)
{
    vertices = num;
    adjacency_list.resize(vertices);
}

bool Graph::insert(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return 0;
    }
    for (int i = 0; i < adjacency_list[x].size(); i++)
    {
        if (adjacency_list[x][i] == y)
            return 0;
    }
    adjacency_list[x].push_back(y);
    adjacency_list[y].push_back(x);
    return 1;
}

int Graph::remove(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return -1;
    }
    bool found = false;
    for (int i = 0; i < adjacency_list[x].size(); i++)
    {
        if (adjacency_list[x][i] == y)
        {
            adjacency_list[x].erase(adjacency_list[x].begin() + i);
            found = true;
            break;
        }
    }
    for (int i = 0; i < adjacency_list[y].size(); i++)
    {
        if (adjacency_list[y][i] == x)
        {
            adjacency_list[y].erase(adjacency_list[y].begin() + i);
            break;
        }
    }
    if (found)
    {
        return 1;
    }
    return 0;
}

bool Graph::search(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
        return 0;

    for (int i = 0; i < adjacency_list[x].size(); i++)
    {
        if (adjacency_list[x][i] == y)
        {
            return 1;
        }
    }
    return 0;
}

void Graph::display()
{
    cout << "\n Adjacency List : " << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << " : ";
        for (int j = 0; j < adjacency_list[i].size(); j++)
        {
            cout << adjacency_list[i][j] << "  ";
        }
        cout << endl;
    }
}
