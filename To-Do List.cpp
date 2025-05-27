#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void display(std::vector<std::string> todo) {
	for (unsigned long i = 0; i < todo.size(); i++) {
		std::cout << i + 1 << '.' << " " << todo[i] << '\n';
	}
}
std::string toLowerCase(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
bool action(std::string choice3) {
	while (true) {
		std::cout << "Do you want to do another action(yes/no): ";
		std::cin >> choice3;
		toLowerCase(choice3);
		if (choice3 == "no") {
			return true;
			break;
		}
		else if (choice3 == "yes") {
			return false;
			break;
		}
		else {
			std::cout << "Not valid. Try again" << '\n';
		}
	}
}
int main() {
	std::vector<std::string> todo = { "Read for 20 minutes", "Study for 1 hour" , "Work on your new project"};
	std::string task;
	int choice;
	unsigned long choice1;
	unsigned long choice2;
	std::string choice3;
	while (true) {
		std::cout << "To-Do List\n1. Display the list\n2. Put a task into the list\n3. Mark  task as completed\n4. Remove a task from the list\nChoose an action: ";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		switch (choice) {
		case 1:
			display(todo);
			break;
		case 2:
			std::cout << "Enter the task: ";
			std::getline(std::cin, task);
			todo.push_back(task);
			break;
		case 3:
			display(todo);
			std::cout << "Choose the task to mark as completed: ";
			std::cin >> choice1;
			todo[choice1 - 1] += " -- completed";
			display(todo);
			break;
		case 4:
			display(todo);
			std::cout << "Choose the task to remove from the list: ";
			std::cin >> choice2;
			todo.erase(todo.begin() + choice2 - 1);
			display(todo);
		}
		if (action(choice3)) {
			break;
		}
		else {
			continue;
		}
	}
	return 0;
}