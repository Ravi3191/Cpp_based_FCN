## CPP Based MLP

This is a C++ based implementation of Multilayered Perceptron(MLP). This repository uses Eigen for Matrix manipulations and linear algebra. This project is part of the C++ Nanodegree Capstone Project - Option 1. 

This code performs binary classification on datasets which are represented in a ".csv" format. A custum architecture can be built by using any combination of Linear Layers, ReLU and sigmoid activation functions with a BCE Loss function. Learning rate and number of epochs will be passed as inputs form the user. The training data is being normalized to improve performance of the model.The network architecture can be tuned by modifying the network definition in the model class. The network is currently being trained on the [Breast Cancer Dataset.](https://archive.ics.uci.edu/ml/datasets/Breast+Cancer+Wisconsin+%28Diagnostic%29)

When run using the default dataset and default architecture with a leraning rate equal to 0.001 you should acheive training accuracy ~ 0.9 and test accuracy ~ 0.92. 

## File Structure
* The src folder consists of the main file and implementation of various classes.
* The include folder consits of all the header files and class definitions. 

## Class Structure
* MLP related classes
<img src="Breast_Cancer_Data/Class_Structure.png"/>

* Read_csv class is used to read, store and perform manipulations on input data.


## Dependencies for Running Locally
* cmake >= 3.1
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.5.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* Eigen >= 3.3.7
  * Download the latest stable version - [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download)
  * Extract the zip file in your home directory and rename the folder to Eigen3.


## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build`
3. Move the data folder to the build directory: `mv Breast_Cancer_Data build`
4. Compile: `cd build && cmake .. && make`
5. Run it: `./train`.

## Rubric Points Addressed:

1.  The project reads data from a file and process the data, or the program writes data to a file:  SRead_csv.cpp reads data from an excel sheet, proceses it and then stores the data. Its objects are instantiated in train.cpp file (Line no: 12,15,17,20).
2. The project accepts user input and processes the input: in train.cpp file (Line no: 25, 27).
3. The project uses Object Oriented Programming techniques: The entire code is built using classes. One such class is Read_csv as said above. It's header is available in include/read_csv.h. 
4. Classes use appropriate access specifiers for class members: header files of all the classes are available in the include directory. All functions are declared as public member functions and private variables.
5. Class constructors utilize member initialization lists: src/read_csv.cpp line 71.
6. Classes abstract implementation details from their interfaces: The header files for the base(fcn_operations), read_csv, bce_loss contain comments where appropriate and member functions are named appropriately.  
7. Classes encapsulate behavior: In linear_layer class the weights and bias matrices are encapsulated (/include/fcn_operations.h Line:22-28), getter functions are defined in all the classes to retreive private members. (Eg: /include/read_csv.h Line 20-22)
8. Classes follow an appropriate inheritance hierarchy: fcn_operations is the parent class and linear_layer,relu,sigmoid are child classes.
9.  Overloaded functions allow the same function to operate on different parameters: In class model the function get_accuracy and get_predictions are overloaded. (File: /include/model.h, lines: 21,22,31,32)
10. Derived class functions override virtual base class functions: fcn_operations defines three virtual functions (forward, backward, get_predictions) (File: /include/fcn_operations.h, Line_no: 7-9). These functions are overriden in the linear_layer,relu,sigmoid classes. 
11. The project makes use of references in function declarations: The forward and backward functions in /include/fcn_operations.h use references as inputs (Line: 7,8).
12. The project uses destructors appropriately: All classes which use dynamic memory have destructors.(Eg: linear_layer.cpp line_no:34)
13. The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate: The model class uses RAII in its constructor to build the network. (File: /src/model.cpp Line_no: 3-18)
14. The project follows the Rule of 5: All the child classes of fcn_operations use rule of 5 as they use memory from the heap.
15. The project uses smart pointers instead of raw pointers: Model.cpp file uses smart pointers to contain different layers of the MLP architecture.
