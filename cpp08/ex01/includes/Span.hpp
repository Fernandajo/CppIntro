#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>
#include <ctime>

class Span
{
private:
   unsigned int _NumLim;
   std::vector<int> _Store;
public:
    Span(unsigned int _n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int Num);
    void addMultiNumbers();
    int shortestSpan();
    int longestSpan();
    ~Span();
};



#endif