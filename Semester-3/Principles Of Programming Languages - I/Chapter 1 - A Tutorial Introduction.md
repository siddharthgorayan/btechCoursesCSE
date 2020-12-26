# Chapter 1 - A Tutorial Introduction

## Getting Started

The only way to learn any programming language is to start writing the programs. We often write a hello world program which prints the message "Hello World" on the screen.

But since we are making a language which has everything in Hindi, we will make a program which prints "नमस्कार".

### First Program In Hindi:
```    
प्रारंभ ():
        लिखो (नमस्कार)
```
        
`How to run, compile and execute this program?`

Well, all these questions are out of the scope of this tutorial since we aim at designing a language and not a compiler.

But we can surely explain you the working of this program:
* The program starts executing from the `प्रारंभ()` function. 
* Here we use indentation instead of braces, to make it more simpler. 
* In the `प्रारंभ()`  function we have a statement `लिखो()`  which prints the message given as an argument to it. 
* `प्रारंभ` is a predefined function and therefore a keyword as well. We can't use this keywork elsewhere.  
``लिखो (नमस्कार)``

The above sample code prints  `नमस्कार`
_________________________________

## Variables And Arithmetic Expressions:
```
प्रारंभ ():
    न = 10 
    ना = 11
    क = न + ना
    लिखो([क])           << outputs 21  >>
    ग = “हे”
    लिखो([न]+[ग])      << outputs  10हे  >>
```

* The above code introduces variables, arithmetic expressions, comments, assignments.

* This is a simple addition program which has some statements in ` प्रारंभ ()` function, the statements
`न = 10 
 ना = 11`
 assigns integer values to न, ना. 
 * These  न, ना variables store integer values and the statement   `ग = ‘हे’` is assigning a string to the ग variable. 
 * The sum of the values stored in न, ना is computed and stored in क variable.
        ``क = न + ना``
* We have a लिखो statement which prints the value stored at variable क. [क] here indicates the value stored at variable क.
        ``लिखो([न]+[ग])``
* The above statement prints the concatenation of a string stored at ग  and the number stored at न. 
* The two lines:
        ``<< outputs  10हे  >> ``
        ``<<  outputs  21 >>``
are comments, any characters between << and >> are ignored by the interpreter.

_________________________________

## The Conditional Statements:
* In DevaN, we use `अगर` `अनयथा यदि` `अनयथा` statements to put conditions and execute commands according to the outcome of the statements.
* These statements are super-useful when we want to take decisions depending on the outcome of a statement.
Example:
```
प्रारंभ ():
पढ़े(क)                                           <<  scans input from user >> 
अगर (क < 5) :                                   << if condition >>
    लिखो ([क] 5 से कम हे )                        << prints a message >>
अन्यथा अगर  (क < 10):                             << else if condition >>
    लिखो ([क] 5 से अधिक और 10 से कम  हे )
अन्यथा :                                          << else condition >> 
    लिखो ([क] 10 से अधिक हे )
```

_________________________________

## The `जबतक` Statement:

`जबतक` statement is a loop which is used to do a task iteratively.

* We often use this statement when we want to repeat a task several times until a condition is reached.
* This statement saves time and space because you write a samll code rather than rewriting the same code again and again.

Example: 
```
प्रारंभ ():
    न =10 
    क = 0 
    जबतक (न > 0):
        क = क  + 1
        न = न - 2
        लिखो([क])
```
In the above Example:

* `क = 0` is the initialisation
* `न > 0` is the condition 
* `न = न  - 2` is the increment step(decrement here)
* This program outputs the value stored in क variable i.e. 5.

### Descriptive Example:
```
प्रारंभ ( ):
    न = 10 
    क = 0 
    जबतक (न > 0):
        क++
        न/=2
        लिखो([क])
```

_________________________________

## Characters:

* Characters, as we all know, are mere alphabets in the script.
* A sequence of characters is called a string.
* When we declare a variable and assign a character or a string to it, we don't need to use any keyword because the compiler automatically interprets that a character/string is being used.
* When we write a character, we need to write that in double quotations, only when we are using a string assignmnet to a variable.
* Inside the `लिखो()` function, we need not put any string in the double quotations because everything inside that function is treated as a string unless explicitly declared using `[]`.
Example:
```
प्रारंभ():
    म = ”हेलो”+”वर्ल्ड”
    लिखो([म])
```
                   
* The concatenated string of  हेलो and वर्ल्ड  is stored in the variable म as हेलोवर्ल्ड, it will be printed when this line executes लिखो([म]).
_________________________________

## Arrays

* Arrays are used to strore a huge amount of data.
* They are useful when we want to work on a huge data simultaneously.
* They are also useful when we need to make a huge number of variables, so instead of it we make an array of that many variables.
* Arrays in DevaN are dynamically allocated by default.
* If we want to declare a constant array, we can do that as well.

Example:
```
प्रारंभ():
    ह[ ]={1,2,3,4,5}
    लिखो[ह]
```
                    
* ह[ ] : this declares the dynamic array and {1,2,3,4,5} by this, all these elements will be stored in the array during the declaration itself. 
``लिखो[ह]`` 
* This line prints the whole array with spaces as a delimiter.
_________________________________

## Functions & Arguments:
* Functionns in DevaN can be of two types: User Defined and Pre Defined.
* User defined functions gives a lot of freedom to write and preserve code for reusing that again and again.
* Fnuctions in DevaN are defined and declared in the following manner:

`Function Name():`
    `Function Definition`
    
* Functions in DevaN can return more than one values.
* If the name of the variable passed as argument in the function call and the parameter used in the function are the same then the value stored in the variable changes accordingly with the changes made in the function.
```
जाँच_एक (क):                                                                                              
    क = 8

जाँच_दो  (ख):                                                                                        
    ख = 9

प्रारंभ():
    क = 5
    ग = 7
    जाँच_एक( क )
    जाँच_दो ( ग )
    लिखो( क और ग का मूल्य है : [क] , [ग])     
```

* Here for जाँच_एक(क) function the argument and parameters are same so the value stored in  क changes to 8 from 5. 
* For जाँच_दो  (ख) function the argument and parameters are not same so the value stored in  क will not change.

### Descriptive Example 1:
#### Program to swap two numbers and show the difference in paasing arguments differently.
```
अदला_बदली(क, ख):            << since the parameters are same as arguments, change will be reflected in main function>> 
    ग = क 
    क = ख 
    ख = ग

बिना_अदला_बदली(ल, व):        << since the parameters and arguments are different, change won't be reflected in main function>>
    ग = ल 
    ल = व
    व = ग  

प्रारंभ():
    क = 5
    ख = 8
    लिखो (अदला बदली के बाद क का मूल्य [क] है तथा ख का मूल्य [ख] है।)     << prints the initial values of क and ख >>
    बिना_अदला_बदली(क, ख)                                        << क = 5 and ख = 8 after this function call >>
    लिखो(अदला बदली के बाद क का मूल्य [क] है तथा ख का मूल्य [ख] है।)      << no change in the values of  क and ख >>
    अदला_बदली(क, ख)                                            << क = 8 and ख = 5 after this function call >>
    लिखो(अदला बदली के बाद क का मूल्य [क] है तथा ख का मूल्य [ख] है।)      << the values of क and ख gets swapped >> 
```

### Descriptive Example 2:
#### Program to find the median of two numbers:
```
प्रारंभ ( ):                                                     <<  main function starts    >>
    पढ़े ( ग )                                                 <<  reads value to ग,  say 2    >>
    पढ़े ( च )                                                 <<  reads value to च,  say 6    >>
    घ = 0
    माध्यिका  ( घ , ग , च )                                     <<  माध्यिका function call with parameters, घ , ग , च  >>
    लिखो (  [ग], [च] का मध्यिका [घ] है |  )                      <<  prints 2, 6  का माध्यिका 4 है |  >> 

माध्यिका (घ , ग , च ):                                          <<  माध्यिका function>>
    घ = ( ग  + च ) / 2                                       <<  finds median of 2, 6 and stores 4 in घ  >>
```

_________________________________

## Variables & Scopes:
    
* Scope of a function in DevaN varies.
* If a variable is declare inside a conditional or iterative statement, the scope of that variable is limited to that statements only.
* If a variable is passed inside a function and the same variables are used as the parameters of the function declaration, the scope of that variable is spread over both the functions.

Example:
```
जाँच_एक (क):                                                                                              
     क = 8

जाँच_दो  (ख):                                                                                        
    ख = 9
    न = 10 

प्रारंभ():
    क = 5
    ग = 7
    जाँच_एक( क )
    जाँच_दो ( ग )
    लिखो( क और ग का मूल्य है : [क] , [ग])   
```

* The scope of the variable न, ख is within the function ``जाँच_दो  (ख)``, which cannot be accessed outside  the function. 
* The scope of क is within the function ``जाँच_एक (क)``
* The scope of क, ग in the ``प्रारंभ()`` function is within the function ``प्रारंभ()``.

_________________________________
