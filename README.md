
# Bank
This project is a simple bank management system implemented in C using linked lists. 
It provides basic functionalities such as user login, password management, account creation, deposit, withdrawal, and balance inquiry. The system is designed to handle multiple user accounts while ensuring data integrity and security.


## Features

- User authentication: Users can log in to their accounts using a username and password. The system verifies the credentials and grants access upon successful authentication.
- Password management: Users can change their passwords to enhance account security. Passwords are stored securely using hashing techniques.
- Account creation: New users can create accounts by providing necessary information such as name, address, and contact details. Each user account is stored as a node in a linked list.
- Balance inquiry: Users can check their account balance to monitor their financial status.


# Implementation Details
Linked list data structure: The project utilizes a linked list to manage user accounts. Each node represents a user account and stores relevant information such as username, password, account balance, and user details.
User-friendly interface: The system provides a text-based user interface (UI) with clear prompts and instructions for easy interaction.
Prerequisites
The project is implemented in C programming language and requires a C compiler to build and run.

## Running Tests

To run the program, run the following command

```bash
    gcc *.c
```

# Lessons Learned and Challenges
During the process of building this bank management system in C with linked lists, I encountered several challenges that helped me gain valuable insights and improve my programming skills. Here are some of the lessons learned and the challenges I faced:

### Lessons Learned

* ### Data structure implementation:
    Implementing a linked list data structure allowed me to understand how data can be organized and managed efficiently in a dynamic manner. I learned about the concept of nodes, pointers, and how they are interconnected to form a linked list.

* ### User authentication and password security:
     Developing the user authentication system taught me the importance of password security. I explored different techniques, such as password hashing, to securely store and compare passwords. This experience emphasized the significance of protecting user information and maintaining data integrity.

* ### User interface design:
     Creating a user-friendly text-based interface was crucial for the project. I focused on designing clear prompts and intuitive menu options to enhance the user experience. This experience taught me the importance of considering the end user's perspective and creating interfaces that are easy to navigate.

### Challenges and Solutions
* Handling user input validation: One of the challenges I faced was validating user input to prevent unexpected behavior or errors. I addressed this challenge by implementing input validation techniques, such as checking for valid data types and range limits. This helped ensure that the program could handle various scenarios and maintain stability. 

* Ensuring data integrity in a multi-user environment: As the system needed to handle multiple user accounts simultaneously, ensuring data integrity was a challenge. I addressed this by implementing appropriate synchronization techniques and utilizing mutex locks to prevent race conditions and maintain data consistency.

* Debugging and error handling: Throughout the development process, I encountered various bugs and errors. I overcame this challenge by adopting a systematic approach to debugging, such as using print statements and debugging tools, to identify and resolve issues effectively. Implementing robust error handling mechanisms also helped improve the overall stability of the program.

* Designing efficient algorithms: Optimizing the algorithms used for operations such as deposit, withdrawal, and balance inquiry was another challenge. I approached this by analyzing the time complexity of the algorithms and exploring ways to improve efficiency, such as utilizing appropriate data structures and algorithmic techniques.

* Overall, building this bank management system provided me with valuable hands-on experience in C programming, data structures, file handling, and user interface design. It allowed me to learn from challenges and develop problem-solving skills to overcome them effectively.


## Authors

- [@imad OULASRI](https://www.github.com/ioulasri/)
