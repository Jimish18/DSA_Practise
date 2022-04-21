#include <bits/stdc++.h>
#include <vector>
using namespace std;

class queue
{
    private:
    vector<int> v;
    int front;
    int back;

    public:
    queue()
    {
        front = v[0];
        // back = v.size()-1;
    }

    void enqueqe(int data)
    {
        v.push_back(data);
    }

    void dequeue()
    {
        v.pop_front();;
    }
}

int main()
{

    return 0;
}