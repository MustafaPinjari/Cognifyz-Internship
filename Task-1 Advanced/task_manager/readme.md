# 📝 Task Management System - README

## 📚 Project Overview

The **Task Management System** is a C++ command-line application that helps you manage your tasks efficiently. It allows you to create, view, update, delete, and sort tasks based on priority and due date. This project is ideal for anyone looking to improve their productivity through a simple, intuitive task management solution.

---

## 🚀 Features

1. **🆕 Create Tasks**: Add new tasks with a title, description, priority (Low, Medium, High), and a due date.
2. **👁️ View Tasks**: List all tasks, showing their title, description, status (Pending, In Progress, Completed), priority, and due date.
3. **🔄 Update Tasks**: Modify task details such as description, priority, status, and due date.
4. **❌ Delete Tasks**: Remove tasks from the list by entering the title.
5. **🔀 Sort Tasks**: Sort tasks by their priority and due date, ensuring that the most important and urgent tasks are listed first.

---

## 🛠️ Usage

### 1. Run the Program
Execute the program in your terminal using:

```bash
g++ main.cpp Task.cpp -o TaskManager
./TaskManager
```

### 2. Available Commands:
- **1️⃣ Create Task**: Follow prompts to enter task details like title, description, priority, and due date.
- **2️⃣ Read Tasks**: View all your tasks with their respective details.
- **3️⃣ Update Task**: Modify an existing task by entering its title.
- **4️⃣ Delete Task**: Remove a task from your list by providing its title.
- **5️⃣ Sort Tasks**: Automatically sort tasks by priority and due date.
- **6️⃣ Exit**: Exit the application.

---

## 🖥️ Sample Output

```bash
1. Create Task
2. Read Tasks
3. Update Task
4. Delete Task
5. Sort Tasks
6. Exit
Enter your choice: 1
Enter title: Study for exam
Enter description: Prepare for the final math exam
Enter priority (1: Low, 2: Medium, 3: High): 3
Enter due date (YYYY-MM-DD): 2024-10-10
Task created successfully.
```

---

## 🔧 File Structure

```
├── main.cpp       # Main application logic
├── Task.h         # Header file containing Task class declaration
├── Task.cpp       # Implementation of the Task class
├── README.md      # Project documentation
```

---

## 🧩 Dependencies

- C++11 or later
- Standard Libraries: `<iostream>`, `<vector>`, `<algorithm>`, `<iomanip>`, `<chrono>`, `<sstream>`

---

## 📦 Compilation

To compile the project, ensure you have a C++ compiler installed and run the following command:

```bash
g++ main.cpp Task.cpp -o TaskManager
```

Run the program with:

```bash
./TaskManager
```

---

## 🌐 Socials:
- **Developer**: Mustafa Pinjari ([@MustafaPinjari](https://github.com/MustafaPinjari))
[![Instagram](https://img.shields.io/badge/Instagram-%23E4405F.svg?logo=Instagram&logoColor=white)](https://instagram.com/its_ur_musuuu)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mustafa-pinjari-287625256/)
[![LeetCode](https://img.shields.io/badge/LeetCode-%23F7DF1E.svg?logo=leetcode&logoColor=black)](https://leetcode.com/u/Mustafa_Pinjari/)
[![Stack Overflow](https://img.shields.io/badge/Stack_Overflow-%23F48024.svg?logo=stack-overflow&logoColor=white)](https://stackoverflow.com/users/26745237/mustafapinjari)
[![CodePen](https://img.shields.io/badge/CodePen-%23000000.svg?logo=codepen&logoColor=white)](https://codepen.io/-MUSTAFA-)
[![Hugging Face](https://img.shields.io/badge/Hugging%20Face-%23FFAE00.svg?logo=huggingface&logoColor=black)](https://huggingface.co/MustafaPinjari)
[![Devfolio](https://img.shields.io/badge/Devfolio-%23000000.svg?logo=devfolio&logoColor=white)](https://devfolio.co/@Mustafa_Pinjari)


---

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.

---

Thank you for using the **Task Management System**! 😊 Organize your tasks efficiently and boost your productivity! 💪