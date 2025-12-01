#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        arr[0] = -1;   // dummy index
        size = 0;
    }

    // INSERT (push)
    void push(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // heapify up
        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // REMOVE HIGHEST PRIORITY ELEMENT (pop)
    void pop() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        // replace root with last element
        arr[1] = arr[size];
        size--;

        // heapify down
        int i = 1;
        while (2 * i <= size) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // GET HIGHEST PRIORITY ELEMENT (top)
    int top() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return arr[1];
    }

    // DISPLAY PRIORITY QUEUE
    void display() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(50);
    pq.push(55);
    pq.push(53);
    pq.push(52);
    pq.push(54);

    cout << "Priority Queue elements: ";
    pq.display();

    cout << "Highest Priority Element: " << pq.top() << endl;

    pq.pop();
    cout << "After deleting highest priority: ";
    pq.display();

    return 0;
}
