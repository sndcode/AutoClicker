# AutoClicker
C++ autoclicker for the mouse using its X and Y coordinates on screen


NumPad1 = save mouse position
NumPad2 = activate autoclicker on saved position
NumPad3 = STOP
Escape  = Close

----

TO DO: ADD 
#in <json/value.h>

EXAMPLE:
```
//if include <json/value.h> line fails (latest kernels), try also:
//  #include <jsoncpp/json/json.h>
#include <json/value.h>
#include <fstream>

std::ifstream people_file("people.json", std::ifstream::binary);
Json::Value people;
people_file >> people;

cout<<people; //This will print the entire json object.

//The following lines will let you access the indexed objects.
cout<<people["Anna"]; //Prints the value for "Anna"
cout<<people["ben"]; //Prints the value for "Ben"
cout<<people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

cout<<people["profession"]; //NULL! There is no element with key "profession". Hence a new empty element will be created.
```
