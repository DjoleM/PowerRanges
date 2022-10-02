![powerRanges logo](https://raw.githubusercontent.com/DjoleM/powerRanges/master/powerRanges.png)

# Power Ranges

A C++ ranges library - it's finally here!
Have you ever wanted to generate a range in C++ as easy as you can in python? Now you can.

## Usage:

Simply load the powerRanges.h library and you'll have access to some helpers within the powerRanges namespace.

the `rangeBounds` is a helper class which can enapsulate a range definition for easier management

The `range` function can be used with any iterable type, given 2 bounds it will build and return a vector 
of all elements from left bound to the right bound.

Currently the library is in it's primitive state, it does not support reverse or deminishing ranges. (will be added soon)