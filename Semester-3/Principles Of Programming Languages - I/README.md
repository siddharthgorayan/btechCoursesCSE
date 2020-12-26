# language-manual-iiitr2
language-manual-iiitr2 created by GitHub Classroom

# Language Manual
# Name of the Language: DevaN
    We derived the name of our programming language from Devanagari Script on which Hindi Language is based.
----------------------------------------------------------------------------

## Basic Idea:
1. The idea is to design and implement a language which is different from the existing languages and help a large section of people to start programming.
2. We have thought of designing a language which has everything written in Hindi Script, from syntax to variable and strings, everything in Hindi!
----------------------------------------------------------------------------

## Goal Of The Language:
1. The goal is to target the people who neither understand English, nor can they write it down but have an interest in programming.
2. The goal also targets a large section of students in Engineering Colleges who have never been introduced to English in their School times. 
3. There exists a large number of students from various state/central boards where the subjects like Physics, Chemistry and even Mathematics are taught in Hindi Language.
4. Even the most important Entrance Exam for Engineering students - JEE gives an option to attempt the Exam either in Hindi or in English, which may be further extended to other languages too.
    Keeping in mind that a considerable number of students coming to the best colleges in India have Hindi as their main language, it is quite fair to design and implement a language where the students can code in Hindi.
5. The language also aims at avoiding any complex rules and regulations which makes the language difficult to understand and code.
6. The aim is to provide a seamless coding experience to the user by making it as simple as possible.
7. Summing up all the points above, our language aims at providing such a programming experience to the user that even a person with no background of science can easily code in Hindi Language. 
----------------------------------------------------------------------------

## USP Of Our Language:
1. The unique feature of our language is that there exists no such language as of now which can be written in Hindi Script and so much ease.
2. The one such language which exists as of now is [Kalaam](https://www.kalaam.io) which isn’t designed properly till now:
    * It offers just 8 functions as of now with functionality limited to printing, scanning, if, else and while loop.
    * It doesn’t have any defined programming paradigm which it aims to achieve when the language is developed completely.
    * The language appears to be just a translation from English to Hindi of C language.
    * Even the translation is not done properly and variables like “a”, “b” … alphabets are still used in the language.
    * Some predefined function names are just translated to Hindi Script and it still has the English Words, like: पुश()
    * To sum up, the Kalaam language appears to be just an INCOMPLETE translation from C English Script to C Hindi Script.
    * It didn’t aim to improve the user experience and make it seamless and easy so that anyone with just basic knowledge can use it.
3. All the above things make our language stand apart in terms of Script, Ease and User Experience.
----------------------------------------------------------------------------

## Programming Paradigm:
1. The paradigm for our language is Imperative Paradigm.
2. It consists of both procedural and object oriented programming.
3. The procedural aspect of our programming language consists of building the program with the help of various functions.
4. The object oriented aspect of our language allows to create objects and can contain data in the form of attributes and code in the form of methods.
5. Every block of code is written with the help of indention rather then the use of braces.
6. The use of colon ( : ) at the start of loops and conditional statements allows to make the language easier to read and write.
7. The data types are automatically identified by the compiler and there's no need to declare any specific data type.
----------------------------------------------------------------------------

## A Tutorial Introduction: (Based on Chapter 1 of Kernighan Ritchie)

### First Program In Hindi:
    
    प्रारंभ ():
        लिखो (नमस्कार)
    
The program starts executing from the प्रारंभ (): function. Here we use indentation instead of braces, to make it more simpler. In the प्रारंभ ()  function we have a statement लिखो  which prints the message given as an argument to it. 
``लिखो (नमस्कार)``
The above sample code prints  `नमस्कार`
_________________________________

### Variables And Arithmetic Expressions:

    प्रारंभ ():
        न =10 
        ना = 11
        क = न + ना
        लिखो([क])           << outputs 21  >>
        ग = “हे”
        लिखो([न]+[ग])      << outputs  10हे  >>

The above code introduces variables, arithmetic expressions, comments, assignments.

This is a simple addition program which has some statements in ` प्रारंभ ()` function, the statements
`न = 10 
 ना = 11`
assigns integer values to न, ना. These  न, ना variables store integer values. And the statement   `ग = ‘हे’` is assigning a string to the ग variable. The sum of the values stored in न, ना is computed and stored in क variable.
        ``क = न + ना``
And then we have a लिखो statement which prints the value stored at variable क. [क] here indicates the value stored at variable क.
        ``लिखो([न]+[ग])``
The above statement prints the concatenation of a string stored at ग  and the number stored at न. The two lines
        ``<< outputs  10हे  >> ``
        ``<<  outputs  21 >>``
are comments, any characters between << and >> are ignored by the interpreter.
_________________________________

### Loops:
    प्रारंभ ():
        न =10 
        क = 0 
        जबतक (न > 0):
            क++
            न-=2
            लिखो([क])
            
जबतक is the generalisation of while loop, क = 0 is the initialisation, न > 0 is the condition and न-=2 is the increment step(decrement here), this program outputs the value stored in क variable i.e. 5.
_________________________________

### Chars:
         प्रारंभ():
                   म = ”हेलो”+”वर्ल्ड”
                   लिखो([म])
                   
The concatenated string of  हेलो and वर्ल्ड  is stored in the variable म as हेलोवर्ल्ड, it will be printed when this line executes लिखो([म]).
_________________________________

### Arrays
        प्रारंभ():
                    ह[ ]={1,2,3,4,5}
                    लिखो[ह]
                    
ह[ ] : this declares the dynamic array and {1,2,3,4,5} by this, all these elements will be stored in the array during the declaration itself. 
``लिखो[ह]`` 
This line prints the whole array with spaces as a delimiter.
_________________________________

### Functions & Arguments:

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
                   
If the name of the variable passed as argument in the function call and the parameter used in the function are the same then the value stored in the variable changes accordingly with the changes made in the function. Here for जाँच_एक(क) function the argument and parameters are same so the value stored in  क changes to 8 from 5. 

For जाँच_दो  (ख) function the argument and parameters are not same so the value stored in  क will not change.
_________________________________

### Variables & Scopes:
    
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

The scope of the variable न, ख is within the function ``जाँच_दो  (ख)``, which cannot be accessed outside  the function. And the scope of क is within the function ``जाँच_एक (क)`` and the scope of क, ग in the ``प्रारंभ()`` function is within the function ``प्रारंभ()``.
_________________________________

### Some Reserved Words:
1. प्रारंभ  
2. लिखो 
3. पढ़े
4. अगर
5. अन्यथा फिर
6. अन्यथा
7. जबतक
_________________________________
--------------------------------------------------------------------------------------
