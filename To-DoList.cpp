#include <iostream>
  using namespace std;

struct Node 
{
    string task;
    Node* next;    
    Node(const string& t) : task(t), next(nullptr) { }
};


class TodoList 
{
 private:
    Node* head;
    int size;

 public:
    TodoList() : head(nullptr), size(0) {  }

    void displayTodoList() 
    {
        if (head == nullptr) 
        {
            cout << "To-Do List is empty.\n\n";
            return;
        }

        cout << "To-Do List:\n";
        Node* current = head;
        int index = 1;
        while (current != nullptr) 
        {
            cout << index << ". " << current->task << endl;
            current = current->next;
            index++;
        }
        cout << endl;
    }

    void addTask(const string& task) 
    {
        Node* newNode = new Node(task);
        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            while (current->next != nullptr) 
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
        cout << "Task added: " << task << endl << endl;
    }

     void removeTask(int taskIndex) 
     {
        if (taskIndex < 1 || taskIndex > size) 
        {
            cout << "Invalid task index. No task removed.\n\n";
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 1; i < taskIndex; ++i) 
        {
            previous = current;
            current = current->next;
        }

        if (previous == nullptr) 
        {
            head = current->next;
        } 
        else 
        {
            previous->next = current->next;
        }

        delete current;
        size--;
        cout << "Task removed.\n\n";
    }

    ~TodoList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() 
{
    TodoList todoList;

    while (true) 
    {
        
        cout << "Menu:\n";
        cout << "1. Display To-Do List\n";
        cout << "2. Add Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Quit\n";

        int choice;
        string newTask;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                todoList.displayTodoList();
                break;
            case 2:
                cin.ignore();
                cout << "Enter task to add: ";                
                getline(cin, newTask);
                todoList.addTask(newTask);
                break;
            case 3:
                cout << "Enter task index to remove: ";
                int taskIndex;
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case 4:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n\n";
                break;
        }
    }

    return 0;
}