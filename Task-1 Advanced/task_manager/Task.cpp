#include "Task.h"

Task::Task(std::string title, std::string description, TaskPriority priority, 
           const std::chrono::system_clock::time_point& dueDate)
    : title(std::move(title)), description(std::move(description)), 
      status(TaskStatus::Pending), priority(priority), dueDate(dueDate) {}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
TaskStatus Task::getStatus() const { return status; }
TaskPriority Task::getPriority() const { return priority; }
std::chrono::system_clock::time_point Task::getDueDate() const { return dueDate; }

void Task::setDescription(const std::string& newDescription) { description = newDescription; }
void Task::setStatus(TaskStatus newStatus) { status = newStatus; }
void Task::setPriority(TaskPriority newPriority) { priority = newPriority; }
void Task::setDueDate(const std::chrono::system_clock::time_point& newDueDate) { dueDate = newDueDate; }
