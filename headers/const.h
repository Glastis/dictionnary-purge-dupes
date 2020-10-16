/*
** Created by glastis
** Date: 15-Oct-20
** Contact: developers@glastis.com
*/

#ifndef PURGE_DUPES_CONST_H
#define PURGE_DUPES_CONST_H

#define MAX_RAM_ALLOCATION      100000000u //100Mo

#define LINE_MAX_LEN            500u
#define MAX_LINE_PER_READ       ((MAX_RAM_ALLOCATION)/(LINE_MAX_LEN))


#define TRUE                    1
#define FALSE                   0

#endif //PURGE_DUPES_CONST_H
