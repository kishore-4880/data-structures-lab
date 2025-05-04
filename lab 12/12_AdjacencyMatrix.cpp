#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> matrix;

public:
    Graph(int);
    int insert(int, int);
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
            result = graph.insert(x, y);
            if (result == 1)
            {
                cout << "Insertion successful." << endl;
            }
            else if (result == 0)
            {
                cout << "Insertion failed. Edge already exists." << endl;
            }
            else
            {
                cout << "Insertion failed. Vertices out of bounds." << endl;
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

Graph::Graph(int ver)
{
    vertices = ver;
    matrix.resize(vertices, vector<int>(vertices, 0));
}

int Graph::insert(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return -1;
    }
    if (matrix[x][y])
    {
        return 0;
    }
    else
    {
        matrix[x][y] = 1;
        matrix[y][x] = 1;
        return 1;
    }
}

int Graph::remove(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return -1;
    }
    if (!matrix[x][y])
    {
        return 0;
    }
    else
    {
        matrix[x][y] = 0;
        matrix[y][x] = 0;
        return 1;
    }
}

bool Graph::search(int x, int y)
{
    if (x >= vertices || y >= vertices || x < 0 || y < 0)
    {
        return 0;
    }
    return matrix[x][y];
}

void Graph::display()
{
    cout << "\n Adjacency Matrix : " << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
