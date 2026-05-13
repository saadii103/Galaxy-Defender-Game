# SECURITY POLICY

## 1. Purpose

This security policy outlines the procedure for reporting and handling security-related issues in the **Galaxy Defender (C++ OpenGL Game)** project.

---

## 2. Project Information

**Project Name:** Galaxy Defender
**Technology Stack:** C++ with OpenGL/GLUT
**Maintainer:** Muhammad Saad Shafiq
**Contact Email:** [m250103@mtn.nu.edu.pk](mailto:m250103@mtn.nu.edu.pk)

---

## 3. Scope

This policy applies to all versions of the Galaxy Defender project, including source code, build files, and associated documentation.

---

## 4. Reporting a Vulnerability

If you identify a security vulnerability, bug, or unexpected behavior, you are requested to report it responsibly.

### Reporting Channels:

* Email: [m250103@mtn.nu.edu.pk](mailto:m250103@mtn.nu.edu.pk)
* GitHub private issue (if available)

Please include the following details in your report:

* Description of the issue
* Steps to reproduce the problem
* Expected and actual behavior
* Screenshots or logs (if applicable)

---

## 5. Types of Issues to Report

The following issues are considered valid security or stability concerns:

* Application crashes or segmentation faults
* Memory management issues (e.g., leaks, invalid access)
* File handling vulnerabilities (e.g., score file corruption)
* Input validation issues
* Game logic errors affecting stability

---

## 6. Out of Scope

The following are not considered security vulnerabilities:

* Gameplay difficulty or balancing concerns
* Feature requests or enhancements
* Graphical or UI improvements
* Audio or visual design suggestions

---

## 7. Response Process

* All reports will be reviewed in a timely manner.
* Confirmed issues will be prioritized based on severity.
* Fixes will be included in subsequent updates where applicable.
* Communication may be maintained for clarification if required.

---

## 8. Developer Security Guidelines

Contributors and developers must ensure:

* Proper bounds checking for arrays (e.g., bullets, enemies)
* Prevention of buffer overflows
* Safe handling of user input (e.g., player name input)
* Stable execution of game loops (Display and Timer functions)
* Secure file handling for persistent data storage

---

## 9. System Environment

* The application operates in an offline environment
* No network communication is implemented
* All data is stored locally in files (e.g., data.txt)
* The project is designed for Linux-based systems (Ubuntu)

---

## 10. Responsible Disclosure

We encourage responsible disclosure of vulnerabilities. All security-related issues should be reported privately to the maintainer to ensure proper assessment and resolution before public disclosure.
* GitHub repository structure (folders + files layout)
* Or CV-ready project description for internships/jobs
