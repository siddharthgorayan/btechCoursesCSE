# Example 5
## Program to show Function Calling with Arguments and showing the difference in using the same or different parameters as those are arguments.

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



