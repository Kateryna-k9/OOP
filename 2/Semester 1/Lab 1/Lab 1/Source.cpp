#include "Header.h"

Component::Component()
{
    designation[0] = '\0';
    type = 'U';
    nominal = 0;
    quantity = 0;
}

char Component::getType() const
{
    return type;
}