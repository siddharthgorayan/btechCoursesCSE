# Functions 

## Conform 

### Example 1:
* A function can return more than one values.
```
जोड़ना_गुणा(क, ख):
    जोड़ना = क + ख 
    गुणा = क * ख 
    वापसी जोड़ना, गुणा 
    
प्रारंभ():
    म = 4
    ग = 5
    जोड़ना, गुणा = जोड़ना_गुणा(म, ग)
```
--------------------------------------------------

### Exmaple 2:
* if parameter and argument are same while function calling, any change in the values of the variable in the function causes a change in the value of the variables in the function from where it was called.
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
    बिना_अदला_बदली(क, ख)                                         << क = 5 and ख = 8 after this function call >>
    लिखो(अदला बदली के बाद क का मूल्य [क] है तथा ख का मूल्य [ख] है।)      << no change in the values of  क and ख >>
    अदला_बदली(क, ख)                                            << क = 8 and ख = 5 after this function call >>
    लिखो(अदला बदली के बाद क का मूल्य [क] है तथा ख का मूल्य [ख] है।)      << the values of क and ख gets swapped >> 
```
--------------------------------------------------

### Example 3:
* We can pass an array as a parameter in a function.
* If the parameter and argument has the same array variable then any change made in the function would reflect in the main function as well.
```
सारणी(क[]):
    म = 0
    जबतक(म < 10):
        क[म] = म
        म = म + 1

सारणी_बदली(ख[]):
    म = 0
    जबतक(म < 10):
        ख[म] = म 
        म = म + 1
        
प्रारंभ():
    ख[10] = 0
    सारणी(ख[])
    लिखो([ख])                << prints 0 0 0 0 0 0 0 0 0 0 >>
    सारणी_बदली(ख[])
    लिखो([ख]);               << prints 0 1 2 3 4 5 6 7 8 9 >>
```
--------------------------------------------------

### Example 4:
* passing a function inside another function is allowed as long as the function being passed has a valid return value.
```
जोड़ना(क, ख):
    वापसी क + ख 
    
गुणा(क, ख):
    वापसी क * ख 
    
प्रारंभ(): 
    ग = 5
    म = 8
    च = गुणा(ग, गुणा(ग,म))
    लिखो(च)
```
--------------------------------------------------

### Example 5:
* functions can be added, subtracted etc as long as the functions being operated on returns a valid return value.
```
घटाना(क, ख):
    वापसी क - ख 

जोड़ना(प, फ):
    वापसी प + फ 
    
प्रारंभ():
    च = 3
    छ = 2
    गुणा = घटाना(च, छ) * जोड़ना(च,छ) 
```
----------------------------------------------------------------------------------------------------


## Do Not Conform :

### Example 1:
* Mis-spelt Functions
```
संदेश():
    लिखो(जाँच की जा रही है ।)
    
प्रारंभ():
    सन्देश()                   << funtion not found! Although both the functions are written right but spelling matters.>>
```
--------------------------------------------------

### Example 2:
* returning many values and assigning less values.
```
घटाना_विभाजन(क, ख):
    घटाना = क - ख 
    विभाजन = क/ख 
    वापसी घटाना, विभाजन 
    
प्रारंभ():
    म = 4
    ग = 5
    घटाना = घटाना_विभाजन(ग, म)   << shows an error since two values are assigned to a single variable.
```
--------------------------------------------------

### Example 3:
*  definaition of a function inside another function is not allowed.
```
प्रारंभ():
    म = 4
    ग = 5
    घटाना_विभाजन(क, ख):       << function definition not allowed here. >>
        घटाना = क - ख 
        विभाजन = क/ख 
    घटाना = घटाना_विभाजन(ग, म)
```
--------------------------------------------------

### Example 4:
* syntactical error
```
प्रारंभ():
म = 4                       << indents are not used as per the rules. >>
ग = 5
```
--------------------------------------------------

### Example 5:
* redifinition of funcion is not allowed.
```
घटाना_विभाजन(क, ख):
    घटाना = क - ख 
    विभाजन = क/ख 
    वापसी घटाना, विभाजन 
    
घटाना_विभाजन(य, र ):            << redifinition not allowed >>
    घटाना = ख - क 
    विभाजन = ख/क 
    वापसी घटाना, विभाजन 
    
प्रारंभ():
    म = 4
    ग = 5
    घटाना = घटाना_विभाजन(ग, म)   << shows an error since two values are assigned to a single variable.
```
----------------------------------------------------------------------------------------------------
