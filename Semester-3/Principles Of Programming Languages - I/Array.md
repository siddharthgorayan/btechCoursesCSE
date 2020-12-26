# ARRAY EXAMPLES

* EXAMPLES THAT  CONFORM LANGUAGE SPECIFICATION


### Example 1

```
प्रारंभ ():
    ह[ ] = {  1 ,2 ,3 ,4,5 }
    र[ ] = { 2 ,4 ,6 ,7 } 
    ह = र                
    न = 0 
    क = 0 
    जबतक (न < र.लम्बाई()):
        अगर ( ह[न] == र[न]):
            न  =  न  + 1 
            जारी      <<similar to continue >>
        अन्यथा फिर ( ह[न] != र[न] ):
            लिखो( ह  और र  सामान  नहीं  है | )
            विराम     <<similar to break  >>
    लिखो( ह  और र  सामान  है ) 
    ह[3] = र[3]      <<this is OK if there are atleast  3  numbers  in  both  the  arrays >>
 
<<array size is not fixed. It’s dynamically allocated. Here, the size of ह is dynamically resized to 4.   >>

```
### Example 2

```
प्रारंभ():
    न[ ] = {1, 2, 3, 4}   
    लिखो(न)                     <<prints 1,2,3,4>>
    ह[ ] = { 0,3,5,6,9}
    लिखो(ह)                     <<prints 0,3,5,6,9 >>
    न = न + ह                   <<concatenation of the arrays >> 
    लिखो(न)                     <<prints 1,2,3,4,0,3,5,6,9 >>
   
```         
### Example 3
```
प्रारंभ ( ):
    क[ ] = { 7, 8, 9}
    क.डालो (5)                   <<inserts 5 to क at the end >>
    लिखो ([ क ] )               <<prints [7, 8, 9, 5] >>
    क.डालो (12, 2)              <<क.डालो(value,indexof array), inserts value 12 at 2nd index position  >>
    लिखो ([ क ])                <<prints [ 7, 8, 12, 9, 5 ] >>

```
### Example 4
```
प्रारंभ ():
    क [ ][ ] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}}   <<2D ARRAY >>
    क.डालो({10 , 11, 12}) 
    लिखो([ क ])                <<prints { {1, 2, 3}, {4, 5, 6}, {7, 8, 9},{10 , 11, 12}} >>

```
### Example 5
```
प्रारंभ ():
    क[ ]
    पढ़े(न) 
    पढ़े(क[न])                   <<takes न  inputs at a time and adds them to क  >>
    लिखो ([ क ])              

```
### Example 6
```
प्रारंभ ( ):
    क[ ] = { 7, 8, 9,23 ,21 ,81}
    क.निकालो  (9)
    लिखो ([क] )                <<prints [7, 8,23,21,81] >>
    क.निकालो (23)              <<removes  the  number  23  from  the  array >>
    लिखो ([क])                 <<prints [ 7, 8,21,81]  >>

```
### Example 7
```
प्रारंभ():
    क[ ] = { 7, 8, 9, 23 ,21 ,81}
    लिखो ([क] )               <<prints [7, 8,9,23,21,81] >>
    क.मिटाओ(3)                <<removes the number which has index 3 from the array>>
    लिखो ([क] )               <<prints [7,8,9,21,81] >>

```



* EXAMPLES THAT DO NOT CONFORM  LANGUAGE SPECIFICATION

### Example 1
```
प्रारंभ ( ):
    क[ ]= {1, 2, 3 , 4}
    क[4] = 5       << index out of range in this array >>

```

### Example 2
```
प्रारंभ ( ) :
    ह = {1; 4; 5; 8 ; 9}

```  
### Example 3
```
प्रारंभ ():
    ग[ ] = {10, 9, 8, 7, 11}   <<error when tries to pop an element from an empty array>>
    न=0
    जबतक(न<6):
        ग.निकालो()   << when no parameter is passed , it removes first element of 
        न=न+1
```
### Example 4
```
प्रारंभ ( ):
    ग[5] = {10, 9, 8, 7, 11}  <<declaration error>>  

```
### Example 5
```
प्रारंभ ( ):
    ह[ ] = {1, 2, 7, 4, 8}
    क [ ] = {7, 8, 9 ,10}

    भ[ ] = ह [ ] - क [ ]   <<subtraction of arrays is not possible >>
```



