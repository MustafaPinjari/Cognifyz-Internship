#pragma once
#include <string>
#include <chrono>

enum class TaskStatus { Pending, InProgress, Completed };
enum class TaskPriority { Low, Medium, High };

class Task {
public:
    Task(std::string title, std::string description, TaskPriority priority, 
         const std::chrono::system_clock::time_point& dueDate);
    
    std::string getTitle() const;
    std::string getDescription() const;
    TaskStatus getStatus() const;
    TaskPriority getPriority() const;
    std::chrono::system_clock::time_point getDueDate() const;
    
    void setDescription(const std::string& description);
    void setStatus(TaskStatus status);
    void setPriority(TaskPriority priority);
    void setDueDate(const std::chrono::system_clock::time_point& dueDate);

private:
    std::string title;
    std::string description;
    TaskStatus status;
    TaskPriority priority;
    std::chrono::system_clock::time_point dueDate;
};
