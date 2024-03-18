#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
  string description;
  bool completed;
};

vector<Task> tasks;

void addTask() {
  string description;
  cout << "Enter task description: ";
  getline(cin, description);

  Task task;
  task.description = description;
  task.completed = false;
  tasks.push_back(task);

  cout << "Task added successfully!" << endl;
}

void viewTasks() {
  if (tasks.empty()) {
    cout << "No tasks found!" << endl;
    return;
  }

  cout << "\n** Your Tasks **" << endl;
  for (int i = 0; i < tasks.size(); i++) {
    string status = tasks[i].completed ? "Completed" : "Pending";
    cout << i + 1 << ". " << tasks[i].description << " (" << status << ")" << endl;
  }
}

void markTaskComplete() {
  if (tasks.empty()) {
    cout << "No tasks found!" << endl;
    return;
  }

  viewTasks();

  int taskNumber;
  cout << "Enter the number of the task to mark complete: ";
  cin >> taskNumber;

  if (taskNumber < 1 || taskNumber > tasks.size()) {
    cout << "Invalid task number!" << endl;
    return;
  }

  tasks[taskNumber - 1].completed = true;
  cout << "Task marked complete successfully!" << endl;
}

int main() {
  int choice;

  do {
    cout << "\n** To-Do List Application **" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task Complete" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        addTask();
        break;
      case 2:
        viewTasks();
        break;
      case 3:
        markTaskComplete();
        break;
      case 4:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice!" << endl;
    }

  } while (choice != 4);

  return 0;
}
