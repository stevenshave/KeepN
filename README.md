#KeepN (a very useful hpp file)
KeepN is a C++11 header only templated datastructure which allows you to keep the best (or worst) N of an object.

Simply
`#include "KeepN.h"`

Then, to keep the top 500 of CustomObject by score:

`KeepNDescending<CustomObject> keep(500);`

`keep.insert(object, score);`

You can keep inserting and only the best (up to) 500 will be kept.

Access the best at any time via keep.best, which is a std::list<std::pair<CustomObject, float\>\>, where float is the score.



KeepNAscending also exists, to enable reverse sorting.



Simple example included.
