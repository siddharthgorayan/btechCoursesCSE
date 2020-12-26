# Tutorial Introduction:

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

* Arrays are used to store a huge amount of data.
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

* There are many build-in methods which are helpful in performing various activities on arrays. 

Example : 
```
प्रारंभ ( ):
    क[ ] = { 7, 8, 9}   
    क.डालो (5)               
    क.डालो (13, 2)  << 7, 8, 13, 9, 5 >>
```

* डालो method (when one parameter passed) inserts the element given as argument at the end of the array.
* डालो method when two argumments passed, inserts the element at a given position. In the above example, 13 is inserted at pos with index 2.

Example : 
```
प्रारंभ():
    ह[ ]={1,2,3,4,5}
    क=ह.अधिकतम()    << returns 5 >>
    न= ह.न्यूनतम()     << returns 1 >>

```

* अधिकतम method returns max element in the array.
* न्यूनतम method returns min element of the array.

Example :
```
 प्रारंभ():
    ह[ ]={1,2,3,4,5}
    क= ह.खोज(0)     << returns 0 >
    लिखो([क]) 

```

* खोज method returns 1 if number is found in the array, else returns 0.

Example :
```
 प्रारंभ():
     ह[ ]={1,20,5,3,50}
     ह.छंटनी()          
     लिखो[ह]        <<prints 1,3,5,20,50>>

```

* छंटनी method sorts the array.

Example :
```
प्रारंभ ( ):
    क[ ] = { 7, 8, 9}
    क.डालो (12, 2)       
    लिखो ([ क ])        <<  prints [ 7, 8, 12, 9, 5 ] >>
    क.निकालो (9)       <<removes  the  number 9  from  the  array >>
    लिखो ([क])         << prints [ 7, 8, 12, 5]  >>    
    क.मिटाओ(3)         << removes the number which has index 3 from the array>>
    लिखो ([क] )        << prints [7,8,12] >> 
```

* निकालो method removes the element which is passed as argument, from the array. 
* मिटाओ method removes the element based on its position (value of index is passed as argument). If no argument is passed it removes 1st element from the array.

Example :
```
प्रारंभ():
    ह[ ]={1,20,5,3,50}
    ह.उलटना()                  <<This method modifies the array ह by reversing it’s elements>>
    लिखो([ह])                   <<Prints  50,3,5,20,1 >>
```

* उलटना method reverses the given array.
_________________________________

## Functions & Arguments:
* Functions in DevaN can be of two types: User Defined and Pre Defined.
* User defined functions gives a lot of freedom to write and preserve code for reusing that again and again.
* Functions in DevaN are defined and declared in the following manner:

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

# Appendix:

## Introduction

This Manual describes the DevaN language designed by our team and gives the details about various aspects of the language like various definitions, meanings and uses of keywords, identifiers, conversions, expressions etc.
For the most part, this Appendix contains the broad outline of the language and being the first edition of this appendix, any changes can be made as and when needed.

-------------------------------

## Contents

[Lexical Conventions](#lexical-conventions)

[Syntax Notation](#Syntax-Notation)

[Conversions](#Conversions)

[Expressions](#Expressions)

[Declarations](#Declarations)

[Statements](#Statements)

[External Declarations](#External-Declarations)

[Scope](#Scope)

[Grammar](#grammar)

-------------------------------

## Lexical Conventions
A program consists of various translation units stored in a file. It is translated in various phases, which is beyond the scope of this project as we aim at only designing the language.
When the low level processing is over, the program gets reduced to a sequence of tokens. 
- Source: Kernighan Ritchie C Programming Language

### Tokens:
#### Comments: 
* The characters `<<` introduces a slash, which terminates with character `>>`
* Comments are often used to convey the meaning and motive of a code snippet so that it’s easy to understand by all the people.
* Comments can’t be used inside and string and if used, they will be treated as a string rather than a comment.

#### Identifiers:
* A sequence of letters and digits is called an identifier. 
* An identifier may also have `_` 
* The first character should be an alphabet.
* Identifiers are case-sensitive, i.e. even if the pronounciation of the words remain same, it should have have the same letters as declared.
Example: `प्रारंभ` and `प्रारम्भ` are different identifiers. 
* It shouldn’t have any special characters.

#### Keywords:
* The identifiers which are reserved for specific use and can't be used otherwise are called Keywords.
Some of the Keywords:
`प्रारंभ`   `लिखो`   `पढ़े`     `अगर`    `अन्यथा फिर`    `अन्यथा`    `जबतक`     `विराम`     `ज़ारी`     `डालो`      `निकालो`    `वापसी`
* Since it's the first edition of this Appendix, more keywords may be added in future as per the needs.

#### String Literals:
* String Literal is a sequence of characters and is automatically identified by the compiler in our language.
* It need not be in double quotes since anything without any specific declaration containing characters is treated as a string whether it is in the `लिखो()` function or in any assignment.
Example: `लिखो(यह एक शृंखला है।)` 
                Here `यह एक शृंखला है।` is treated as a string.

---------------------
               
### Syntax Notation
* A language which has everything written in “Hindi Script”, from syntax to variables and strings, everything in Hindi and used  indentation is used instead of braces.

---------------------

## Conversions
When an integer,float or string value is assigned to a variable(`क`) there is no need to declare the data type because the interpreter interprets what the datatype is i.e. integer / float / string etc..
This section explains the conversions when different types of datatypes are added and several others.

* In this language,
There is no need to type cast a datatype manually as, when an integer/string/float value is assigned to a variable then interpreter interprets automatically when it is declared for the first time.If we want to change the datatype of that variable, we again need to assign it to value of that particular type.

* For example, when `क` = 4 , here the interpreter interprets the datatype  is an integer automatically.If we again do  `क` = 4.1 here the datatype will be 
changed to float type from integer type

### Arithmetic Conversions :
Many operators cause conversions and yield result types in a similar way. The effect is to bring operands into a common type, which is also the type of the result. This pattern is called the usual arithmetic conversions.
       
* First,if either operand is an integer, the result is also an integer.

Ex: `क` = 5 

`र` = 7 

`ट` = `क`+ `र`

Here `क` and `र` are interpreted as integers by interpreter. `ट` is also interpreted as an integer.

* Otherwise, if either operand is float, the result is also a float.

Ex : `क` = 5.23

`र` = 6.01

`ल` = `क` + `र`

Here `क` and `र` are interpreted as float by the interpreter,then `ल` is also interpreted as a float.

* Similarly when two of operands are strings  then the result is also interpreted as string.

* Otherwise, if one operand is  float and the other is integer,the result is also a float.

Ex : `क`= 5.23 

`र` = 6 

`ल` = `क` + `र`

Here `क` is interpreted as float and `र` is interpreted as integer by interpreter then `ल` is also interpreted as a float.

* Otherwise, if one operand is string and other is an integer/float, the result is also a string.

Ex : `क` = “हिंदी”

`र`= 5 

`ल`= `क` +`र`

`ल` is “हिंदी5”

Here  `क` is interpreted as string and `र` is interpreted as integer by interpreter then `ल` is also interpreted as a string.

So, when either operand is of the same type then the result is also interpreted as same type and  String does not support subtraction.

-------------------

## Expressions:

An expression is a combination of operators, constants and variables. An expression may consist of one or more operands, and zero or more operators to produce a value.

### Multiplicative Operators

The multiplicative operators  are `*`, `/`, and `%`.
Note: any operation kept in closed brackets `( )` will be given first highest precedence.
Precedence : second highest precedence goes to `*`, third highest precedence goes to `/`, fourth highest precedence goes to `%`.

`/` : this operator gives quotient
`%` : this operator gives remainder
`*` : this operator gives multiplication
 
Examples for multiplicative-expression:
 * `क*र*ल`  (`क`,`र`,`ल` should belong to same datatype whether they can be int or float)
 * `क*र/ल`  (`क`,`र`,`ल` should belong to same datatype whether they can be int or float but `ल` should not be equal to Zero)
 * `क*र%ल`  (`क`,`र`,`ल` should belong to integer datatype but `ल` should not be equal to zero )
 
###  Additive Operators

The additive operators  are `+` and `-` .
* Note: any operation kept in closed brackets `( )` will be given first highest precedence.
Precedence : second highest precedence goes to `+`, third highest precedence goes to `–`
      `+`  : this operator gives addition
      `-`  : this operator gives subtraction
      
Examples for additive-expression:
 * `क+र-ल` (`क`,`र`,`ल` should belong to the same datatype whether they can be int or float).
  * `क+र` (`क`,`र` should belong to the same datatype whether they can be int or float or string ).
* Note : one cannot perform subtraction on strings

### Relational Operators

* The relational operators are `>`,`>=`,`<`,`<=` .
* These expressions will be evaluated from left to right.
* Examples for relational-expression
  * `क>र` (`क`,`र` should belong to same datatype whether they can be int or float or string)
  * `क<र` (`क`,`र` should belong to same datatype whether they can be int or float or string)
  * `क<=र` (`क`,`र` should belong to same datatype whether they can be int or float or string)
  * `क>=र` (`क`,`र` should belong to same datatype whether they can be int or float or string)
  
* The return type for expression based on relational operator will be integer type. If the statement is true then it will return 1. If the statement is false then it will return 0.
###  Equality Operator

* The equality operators are `==`,`!=`.
* Equality operators will have lower precedence than relational operators.
* Examples for equality operator
  * `क==र` (`क`,`र` should belong to same datatype whether they can be int or float or string)
  * `क!=र` (`क`,`र` should belong to same datatype whether they can be int or float or string)
  
* The return type for expression based on equality operator will be integer type. If the statement is true then it will return 1. If the statement is false then it will return 0

###  Bitwise AND(&) Operator

* This operation can be performed only on bits i.e(1,0)
* The expressions using this operator will return either 0 or 1
* Examples  

```
for expressions   Result

   1&1          1
           
   1&0              0
           
   0&0              0
           
   0&1              0
```
           
           
###  Bitwise OR(|) Operator

* This operation can be performed only on bits i.e(1,0)
* The expressions using this operator will return either 0 or 1
* Examples 

``` 
    for expressions                Result

               1|1                           1
           
               1|0                           1
           
               0|0                           0
           
               0|1                           1 
```
           
           
### Logical AND(&&) Operator
 
 * These expressions will be evaluated from left to right. These expressions will return 1 if both of its operands are non-zero, if any one of its operands is zero then it will return 0.
 ```
 Examples               result
 
    3&&0                  0
    
    3&&1                  1
    
 ```
    
    
### Logical OR(||) Operator

* These expressions will be evaluated from left to right. These expressions     will return 0 if both of its operands are zero, if any one of its operands is non-zero then it will return 1.
``` 
  Examples:           result

   3||0                    1
   
   3||1                    1
   
   0||0                    0
   
```
   
### Assignment Expressions

* The assignment operators are  `=` ,`*=`, `/=`, `%=`, `+=`, `-=`, `&=` ,`^=` ,`|=` etc.
* This expressions will be evaluated from right-left
* Examples
    `क` `=` 1,  here `क` is assigned to 1
    `क` `+=` 1
Assume `क` is initialized to 1,the expression `क` `+=` 1 is equivalent to `क` = `क`+ 1,after performing this expression the `क` value will be 2
-------------------------

## Declarations
  * As our language is dynamically typed, it doesn’t require any declarations before. 
  * When a value is assigned to a variable, the interpreter interprets the data type and allocates respective blocks.

------------------
## Statements

### Expression statements:

* Statements have the form:
  expression-statement
* These are generally assignments, function calls . 

### Compound Statements:

Compound statements contain (groups of) other statements; they affect or control the execution of those other statements in some way. The body of a function definition is a compound statement. 

### Selection statements:

* `अगर` ( expression ) statement
* `अगर` ( expression ) statement `अन्यथा` statement
* The expression can be arithmetic or pointer type.
* In an `अगर` statement, if the expression evaluated is not equal to 0, then the statement is executed, else the second sub-statement( in the second example, `अन्यथा` ) is executed.
* It is possible to have nested `अगर` statements. Each `अगर` (if) can have only one `अन्यथा` (else) but can contain multiple `अन्यथा फिर` (elseif) blocks.

### Iteration statements:

* Iteration statements specify looping.
* Iteration-statement:
  `जबतक` ( expression ): statement
  The expression can be arithmetic or pointer type.
  As long as the expression does not evaluate to zero, the statements in the loop are executed. 
* Structure of loop:
  Initialization : Done before executing loop.      
  Condition : Expression in the loop ( check in the above example ) . 
  Incrementation : Done inside the loop.
  If there is any error in the above conditions, the loop may not execute properly and may also give you some errors (ex: runtime error etc…)

### Jump statements:

* Jump statements transfer the control unconditionally. 
* Jump-statement:
  `विराम`   ( similar to break )
  `जारी`     ( similar to continue )
  `वापसी` expression
* `जारी`  statement may appear only within an iteration statement. It causes control to pass to the loop-continuation portion of the smallest enclosing such statement.
* `विराम` statement may appear only in iteration statements. It is primarily used to exit from a block (in this case, used for breaking loops).
* A function returns to its caller using  `वापसी`. `वापसी` is also used to return values to the caller function. It is also used in functions.
------------------------------

## External Declarations

### Function Definition:

Function definitions have the form:
function-name ( parameter-list ):
    Statements (body)

A function may return multiple values. These can be arithmetic, void( no value is returned  )etc ... You need not declare the type of value returned by the function.

direct-declarator ( identifier-list ) 
where the direct-declarator is an identifier, identifier-list names the parameters.
Example:
```
जाँच_एक (क): 
    
   क = 8  
    
   वापसी क
```

parameter-list here is `क`, function-name is `जाँच_एक`.

-------------------

## Scope

Communication among the functions of a program may be carried out both through calls and through manipulation of external data. 

### Lexical Scope

Lexical scope of an identifier is the region of the program text within which the identifier's characteristics are understood. The scope of a parameter of a function definition begins at the start of the block (if the name of the parameter is not same as in the caller function) defining the function, and persists through the function and ends at the end of the block (if the name of the parameter is not same as in the caller function).

---------------------

## Grammar

### Unary Operator:
(one of) `+` `-` `*` `!`

### Additional Expression:
`वाक्यांश1 + वाक्यांश2`
`वाक्यांश1 + वाक्यांश2`

### Multiplicative Expression:
`वाक्यांश1 * वाक्यांश2`
`वाक्यांश1 / वाक्यांश2`
`वाक्यांश1 % वाक्यांश2`

### Equality Expression:
`वाक्यांश1 == वाक्यांश2`
`वाक्यांश1 != वाक्यांश2`

### Relational Expression:
`वाक्यांश1 < वाक्यांश2`
`वाक्यांश1 > वाक्यांश2`
`वाक्यांश1 <= वाक्यांश2`
`वाक्यांश1 >= वाक्यांश2`

### Jump Statements:
`वापसी *वाक्यांश*`
`विराम`
`ज़ारी`

### Iterative Statements:
`जबतक` (वाक्यांश):
    कथन

### Selective Statements :
`अगर` (वाक्यांश):
    कथन 
`अनयथा फिर` (वाक्यांश):
    कथन 
`अनयथा`
    कथन 
    
-------------------------------
