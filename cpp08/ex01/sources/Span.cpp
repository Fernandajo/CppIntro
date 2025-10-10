#include "../includes/Span.hpp"

Span::Span(unsigned int _n) : _NumLim(_n)
{
    std::cout << "Span constructor created!" << std::endl;
}

Span::Span(const Span &other) : _NumLim(other._NumLim)
{
    if (!_Store.empty())
    {
        _Store.clear();
        _Store.assign(other._Store.begin(), other._Store.end());
    }
    
}

Span &Span::operator=(const Span &other)
{
    if(this != &other)
    {
        _NumLim = other._NumLim;
        _Store.clear();
        _Store.assign(other._Store.begin(), other._Store.end());
    }
    return *this;
}

void Span::addNumber(int Num)
{
    if (_Store.size() >= _NumLim)
        throw std::out_of_range("Reached limit amount of elements");
    else 
        _Store.push_back(Num);
}

void Span::addMultiNumbers()
{
    if (_Store.size() >= _NumLim)
        throw std::out_of_range("Reached limit amount of elements");
    else 
    {
        int size = _Store.size();
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (unsigned int i = size; i < _NumLim; i++)
        {
            addNumber(std::rand());
        }
        
    }
}


Span::~Span() {
    _Store.clear();
    std::cout << "Span deconstructor called!" << std::endl;
}

int Span::shortestSpan()
{
    if(_Store.size() <= 1)
        throw std::out_of_range("no span can be found");
    std::sort(_Store.begin(), _Store.end());
    int d = __INT_MAX__;
    int d1;
    for (long unsigned int i = 0; i < _Store.size() - 1; i++)
    {
        d1 = _Store.at(i + 1) - _Store.at(i);
        if(d1 < d)
            d = d1;
    }
    return d;
}

int Span::longestSpan()
{
    if(_Store.size() <= 1)
        throw std::out_of_range("no span can be found");
    std::sort(_Store.begin(), _Store.end());
    int ret = _Store.back() - _Store.front();
    return ret;
}