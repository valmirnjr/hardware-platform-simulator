# hardware-platform-simulator
A simplified simulator of hardware components. The simulator loads textual definitions of hardware components, builds a platform with the loaded components and simulates their behavior.

## Week 1
### 04/09/2021 - 11/09/2021

- [x] Class diagram
- [x] Project folder structure
- [ ] Implement Factory Pattern
  - [ ] Read text file
  - [ ] Create component according to the text file
  
### **Class diagram**
The class diagram designed is presented below:

![Getting Started](./doc/img/classDiagram.png)

### **Project folder structure**
We use the following organization structure:

```
hardware-platform-simulator/
  bin/ -> executables
  doc/ -> documentation
    img/
  obj/ -> object files
  src/ -> source code
    main.cpp
  test/ -> test files
  .gitignore
  .README.md
```

The namespace organization follows the convetion described in: https://iamsorush.com/posts/namespace-cpp/
