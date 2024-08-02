# Project Shell

***Demo video***

[![Watch the video](https://img.youtube.com/vi/n3SR9lyYcLE/0.jpg)](https://youtu.be/n3SR9lyYcLE)

## Why the shell ?

A shell is a **Command Line Interface (CLI)** that allows users to **interact** with the **operating system**. It serves as an intermediary between the user and the operating system, enabling users:

- to execute commands
- run programs
- manage system resources.

Understanding the shell is vital in Software Engineering to understand the Operating Sytem workings such as:

 - file management
 - process management
 - memory management
 - I/O device management

The low level knowledge of the system workings makes understanding complex concepts later on easier.

----

### With this project we learnt

- how [processes are managed by the OS](https://www.geeksforgeeks.org/introduction-of-process-management/)

- [system calls](https://www.geeksforgeeks.org/introduction-of-system-call/)

- [input/output handling](https://www.geeksforgeeks.org/introduction-to-input-output-interface/)

- [command parsing](https://bito.ai/resources/c-parse-string-c-string-explained/)

- [job control](https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_chapter/libc_27.html)

- [signal handling](https://medium.com/@razika28/signals-ad83f38f80b6)

- [file system interaction](https://www.geeksforgeeks.org/basics-file-handling-c/
)
- [error handling](https://www.geeksforgeeks.org/error-handling-in-c/)

- [environment variables](https://www.cs.purdue.edu/homes/bb/cs348/www-S08/unix_path.html)

----
As much as we would love to dwelve into [history of the shell](https://developer.ibm.com/tutorials/l-linux-shells/), we are not trying to bore you with a lecture on it and so, let's get started with project structure.

```.
├── allias.c ----------------> /* Creating alias operations  */
├── changedir.c ----------------> /*  Changing dir operations  */
├── che.c ----------------> /* Check string operations  */
├── envi.c ----------------> /*  Environment variables  Operations  low-level */
├── envman.c ----------------> /* Environment variables operations more abstract layer */
├── fun2.c ----------------> /* Utility operations */
├── fun3.c ----------------> /* Utility operations */
├── func1.c ----------------> /* Utility operations: free memory operation */
├── func.c ----------------> /* Utility operations: Memory operations */
├── hist.c ----------------> /* CRUD operations on history file */
├── info.c ----------------> /* info_t struct operations CRUD */
├── listing.c -------------> /* contains list CRUD operations */
├── listman.c -------------> /* list operations */
├── lowlv.c -------------> /* buffer operations */
├── main.c ----------------> /* main loop starting point */
├── main.h ----------------> /* header file */
├── path.c ----------------> /* PATH operations */
├── puttingf.c -------------> /* I/O operations */
├── shell -------------> /* executable file (shell itself) */
├── shell.c ---------------> /* main entry point of the file */
├── strman2.c -------------> /* contains string operations functions */
├── strman3.c -------------> /* contains string operations functions */
├── strman4.c -------------> /* contains string operations functions */
└── strman.c -------------> /* contains string operations functions */
```

----

### Conclusion

Developing this shell project has provided invaluable insights into the fundamental aspects of operating system.

Understanding these concepts is crucial for any software engineer as it lays the groundwork for mastering more advanced topics in systems programming and software development.

We hope this project serves as a practical and educational resource for those looking to deepen their knowledge of shell programming and operating system internals. Feel free to explore the code, experiment with modifications, and expand the functionality further. Happy coding!

For any questions or contributions, please reach out through our [GitHub repository](https://github.com/your-repo-link).

----

Thank you for checking out our project!
