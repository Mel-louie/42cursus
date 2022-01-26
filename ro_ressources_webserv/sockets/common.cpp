/*
 * File: common.cpp
 * Project: sockets
 * Created Date: 24 Jan 2022
 * Author: mel louie
 * -----
 * Last Modified: Fri Dec 10 2021
 * Modified By: mel louie
 * -----
 * Copyright (c) 2021 mel louie
 * -----
 */

#include "common.hpp"

char    *bin2hex(const unsigned char *input, size_t len)
{
    char    *result;
    char    *hexits = "0123456789ABCDEF";

    if (input == NULL || len <= 0)
        return (NULL);
    
    int resultlenght  = (len * 3 ) + 1;
    result = (char*)malloc(size_t(resultlenght));
    bzero(result, resultlenght);

    for ( int i = 0 ; i < len ; i++)
    {
        result[i * 3] = hexits[input[i] >> 4];
        result[(i * 3) + 1] = hexits[input[i] & 0x0F];
        result[(i * 3) + 2] = ' '; // for readability
    }

    return (result);
}
