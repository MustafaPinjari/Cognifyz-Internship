#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <sstream>
#include "Task.h"

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";

std::string statusToString(TaskStatus status) {
    switch (status) {
        case TaskStatus::Pending: return "Pending";
        case TaskStatus::InProgress: return "In Progress";
        case TaskStatus::Completed: return "Completed";
    }
    return "Unknown";
}

std::string priorityToString(TaskPriority priority) {
    switch (priority) {
        case TaskPriority::Low: return "Low";
        case TaskPriority::Medium: return "Medium";
        case TaskPriority::High: return "High";
    }
    return "Unknown";
}

std::string formatDate(const std::chrono::system_clock::time_point& date) {
    auto in_time_t = std::chrono::system_clock::to_time_t(date);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
    return ss.str();
}

void printTask(const Task& task) {
    std::cout << BLUE << "Title: " << RESET << task.getTitle() << "\n"
              << BLUE << "Description: " << RESET << task.getDescription() << "\n"
              << BLUE << "Status: " << RESET << statusToString(task.getStatus()) << "\n"
              << BLUE << "Priority: " << RESET << priorityToString(task.getPriority()) << "\n"
              << BLUE << "Due Date: " << RESET << formatDate(task.getDueDate()) << "\n\n";
}

TaskPriority getPriorityFromUser() {
    int priority;
    std::cout << "Enter priority (1: Low, 2: Medium, 3: High): ";
    std::cin >> priority;
    std::cin.ignore();
    switch (priority) {
        case 1: return TaskPriority::Low;
        case 2: return TaskPriority::Medium;
        case 3: return TaskPriority::High;
        default: return TaskPriority::Medium;
    }
}

std::chrono::system_clock::time_point getDueDateFromUser() {
    std::string dateStr;
    std::cout << "Enter due date (YYYY-MM-DD): ";
    std::getline(std::cin, dateStr);
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

void sortTasks(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        if (a.getPriority() != b.getPriority())
            return static_cast<int>(a.getPriority()) > static_cast<int>(b.getPriority());
        return a.getDueDate() < b.getDueDate();
    });
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << GREEN << "1. Create Task\n2. Read Tasks\n3. Update Task\n"
                  << "4. Delete Task\n5. Sort Tasks\n6. Exit\n" << RESET;
        std::cout << "Enter your choice: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                std::string title, description;
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);
                TaskPriority priority = getPriorityFromUser();
                auto dueDate = getDueDateFromUser();
                tasks.emplace_back(title, description, priority, dueDate);
                std::cout << GREEN << "Task created successfully.\n" << RESET;
                break;
            }
            case 2: {
                if (tasks.empty()) {
                    std::cout << YELLOW << "No tasks available.\n" << RESET;
                } else {
                    for (const auto& task : tasks) {
                        printTask(task);
                    }
                }
                break;
            }
            case 3: {
                if (tasks.empty()) {
                    std::cout << YELLOW << "No tasks available to update.\n" << RESET;
                    break;
                }
                std::string title;
                std::cout << "Enter the title of the task to update: ";
                std::getline(std::cin, title);
                auto it = std::find_if(tasks.begin(), tasks.end(),
                    [&title](const Task& t) { return t.getTitle() == title; });
                if (it != tasks.end()) {
                    std::cout << "Enter new description: ";
                    std::string newDescription;
                    std::getline(std::cin, newDescription);
                    it->setDescription(newDescription);
                    it->setPriority(getPriorityFromUser());
                    it->setDueDate(getDueDateFromUser());
                    int status;
                    std::cout << "Enter new status (1: Pending, 2: In Progress, 3: Completed): ";
                    std::cin >> status;
                    std::cin.ignore();
                    it->setStatus(static_cast<TaskStatus>(status - 1));
                    std::cout << GREEN << "Task updated successfully.\n" << RESET;
                } else {
                    std::cout << RED << "Task not found.\n" << RESET;
                }
                break;
            }
            case 4: {
                if (tasks.empty()) {
                    std::cout << YELLOW << "No tasks available to delete.\n" << RESET;
                    break;
                }
                std::string title;
                std::cout << "Enter the title of the task to delete: ";
                std::getline(std::cin, title);
                auto it = std::remove_if(tasks.begin(), tasks.end(),
                    [&title](const Task& t) { return t.getTitle() == title; });
                if (it != tasks.end()) {
                    tasks.erase(it, tasks.end());
                    std::cout << GREEN << "Task deleted successfully.\n" << RESET;
                } else {
                    std::cout << RED << "Task not found.\n" << RESET;
                }
                break;
            }
            case 5:
                sortTasks(tasks);
                std::cout << GREEN << "Tasks sorted by priority and due date.\n" << RESET;
                break;
            case 6:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }

        std::cout << "\n";
    }

    return 0;
}