# C++ Based Login System

This is a basic console-based login system written in C++.
It allows users to:
- Sign up with a username, email, and password
- Log in using their credentials
- Retrieve a forgotten password by providing their username and email

User data is stored in a simple text file `(logindata.txt)` in the following format:  
`username*email*password`

**📂 Project Structure**
```
.
├── logindata.txt    // User data file (created automatically)
├── main.cpp         // C++ source file containing the login system
└── README.md        // Project description and usage guide
```

**🚀 Features**
- 📌 Sign Up: Create a new user account and save it to a text file.
- 📌 Login: Verify existing credentials against saved data.
- 📌 Forgot Password: Retrieve the password by verifying username and email.
