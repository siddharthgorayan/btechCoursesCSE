# while loop examples
## Examples which do not conform our language specifications
### Example 1
```
प्रारंभ ():
    क = 0 
    जबतक(क<10):
        क=क+1
        लिखो([क])
      क्ष=0                         << Throws an indentation error of loop >>
```
### Example 2
```
     प्रारंभ ():
        क=0
        जबतक(क<10)                << Throws a syntax error of while loop >>
           अगर(क%2==0):
                 लिखो([क] इस इवन)
           अगर(क%2!=0):
                   लिखो([क] इस ओड )
           क=क+1
```
### Example 3
```
       प्रारंभ():
           जबतक(क<5):       << Throws an initialisation error >>
                लिखो([क*क])
                क=क+1
```
### Example 4
```
          प्रारंभ():
              क=0
              क्ष=0
              जबतक(क=0):          << Throws conditional error in loop >>
                    अगर(क्ष>क):
                        क्ष=क
                    क=क+1
```
### Example 5
```
       प्रारंभ():
            क=0
            जबतक(1):              << Infinite loop >>
                   क=क+1
```


## Examples which conforms our language specifications

### Example 1
```
प्रारंभ():
    इ =1
    जबतक( इ <= 10 ):        << Loop continues until इ becomes greaterthan or equal to 10 >>
      लिखो( [इ] )
      इ = इ + 1

```
### Example 2
```
प्रारंभ():
    पढ़े(ज)
    जबतक( ज <=20 ):         << Loop continues until ज becomes greaterthan or equal to 20 >>
        लिखो( [ज] )
        ज = ज + 2 

```
### Example 3
```
प्रारंभ():
    इ  = 1
    पढ़े( अ )   
    जबतक( इ<=10 ):        << Loop continues until इ becomes greaterthan or equal to 10 >>
        ब = अ * इ
        लिखो( [ब] )
        इ = इ + 1

```
### Example 4
```
प्रारंभ():
    व = 10
    य = 2
    जबतक( व+य ):                << Loop continues until व+य becomes 0 >>
        लिखो( [व] [य] )
         व = व - 1
         य = य - 1

```
### Example 5
```
प्रारंभ ():
    पढ़े( न )
    ण = न
    स = 0
    जबतक( न > 0 ):            << while loop continues till न becomes negative >>
        र = न % 10;
        स = स + र 
        न = न / 10;              
    लिखो( सम ऑफ़ डिजिट्स ऑफ़ [ण] इस [स] )   << Prints the sum of digits of न >>

```
