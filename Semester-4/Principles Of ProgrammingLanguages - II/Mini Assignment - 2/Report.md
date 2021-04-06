# Report
## C++11 / C++14 Features Used
### 1. Friend Class:
A friend class can access private and protected members of other classes in which it is declared as a friend.

Ref1: [FrontendAction.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/Frontend/FrontendAction.h)

----- spcae for image -----

Here, the classes - ASTMergeAction and WrappedFrontendAction would have access to the private and protected members of FrontendAction class.

Ref2: [Decl.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Decl.h)

----- space for image ----- 

Here, the classes - ASTDeclReader and ASTDeclWrited would have access to the private and protected members of the class PragmaCommentDecl.


Ref 3: [ASTConsumer.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/ASTConsumer.h)

----- space for image -----

Here, the class - SemaConsumer will have access to the private and protected members of the ASTConsumer class.

---------------------------------------------------------------------------------------------------------------------------------------------------

### 2. Abstract Class:
When we don’t know about the implementation of any function in the base class, we provide that in the derived class rather than the base class. Such a base class is called an abstract base class.

Ref1: [FrontEndAction.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/Frontend/FrontendAction.h)

----- space for image -----

There are 3 classes as can be seen above. ASTFrontendAction is derived from FrontendAction and PluginASTAction is derived from ASTFrontendAction.
Here, FrontendAction and ASTFrontendAction are the Abstract Base Classes.

---------------------------------------------------------------------------------------------------------------------------------------------------

### 3. Final:
When we don’t want a derived class to override the virtual function of a base class, we can do that using the final specifier.

Ref1: [Decl.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Decl.h)

----- space for image -----

Here, PragmaCommentDecl will not override the virtual function of the Decl class.

---------------------------------------------------------------------------------------------------------------------------------------------------

### 4. Explicit:
To avoid the implicit conversion of the constructor to a conversion constructor, we use Explicit declaration.

Ref1: [Decl.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Decl.h)

----- space for image -----

---------------------------------------------------------------------------------------------------------------------------------------------------

### 5. Inline Functions:
Inline functions are used to avoid the overhead when some small and commonly used functions are called, which usually takes a lot more time for the calling of the function as compared to the time taken by the actual execution.
When the inline functions are called, whole code of the inline function gets inserted or substituted at the point of inline function call, which is done by C++ compiler at compile time.

Ref1: [Decl.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Decl.h)

----- space for image -----

---------------------------------------------------------------------------------------------------------------------------------------------------

### 6. Virtual Functions:
A virtual function is a member function which is declared within a base class and is re-defined by a derived class.

Ref1: [Decl.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Decl.h)

----- space for image -----

---------------------------------------------------------------------------------------------------------------------------------------------------

## Class Hierarchy
We have seen class hierarchy throughout the project, but here we are going to show you some complex as well as simple class hierarchies to explain the concepts of class hierarchy and inheritance used in the project.

Ref1: [Attr.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Attr.h)

-----space for image-----

The types of hierarchy used in the above Diagram are Single Inheritance and Hierarchial Inheritance which are together bound with Multi-Level Inheritance as shown above.

Ref2: [Decl.h](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/AST/Decl.h)

-----space for image-----

The above diagram shown a more complex hierarchy of classes.
The types of hierarchy used in the above Diagram are Single Inheritance, Hierarchial Inheritance, Multiple Inheritance and Hybrid Inheritance which are together bound with Multi-Level Inheritance as shown above.

## OOP Design Desicions for LLVM:
