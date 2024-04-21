#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the to-do list
void addTask(vector<Task> &todoList, const string &description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to mark a task as completed
void markTaskComplete(vector<Task> &todoList, int index) {
    if (index >= 0 && index < todoList.size()) {
        todoList[index].completed = true;
        cout << "Task marked as completed: " << todoList[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to display the to-do list
void displayTodoList(const vector<Task> &todoList) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i+1 << ". ";
        if (todoList[i].completed)
            cout << "[X] ";
        else
            cout << "[ ] ";
        cout << todoList[i].description << endl;
    }
}

int main() {
    vector<Task> todoList;
    int choice;
    string taskDescription;

    do {
        cout << "\n1. Add Task\n2. Mark Task as Completed\n3. Display To-Do List\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(todoList, taskDescription);
                break;
            case 2:
                int index;
                cout << "Enter index of task to mark as completed: ";
                cin >> index;
                markTaskComplete(todoList, index - 1);
                break;
            case 3:
                displayTodoList(todoList);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
