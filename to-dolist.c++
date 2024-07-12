#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void showMenu();
void addTask(vector<string> &tasks);
void viewTasks(const vector<string> &tasks);
void deleteTask(vector<string> &tasks);

int main() {
    vector<string> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();  // Clear the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}

void showMenu() {
    cout << "\n=== To-Do List Manager ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter task to add: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added!\n";
}

void viewTasks(const vector<string> &tasks) {
    cout << "\n--- Tasks ---\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

void deleteTask(vector<string> &tasks) {
    int index;
    viewTasks(tasks);  // Display current tasks

    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
        return;
    }

    cout << "Enter task number to delete (1-" << tasks.size() << "): ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted.\n";
    }
}
    