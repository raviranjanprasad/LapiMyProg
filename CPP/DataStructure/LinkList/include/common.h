#ifndef COMMON_H
#define COMMON_H
template <class T>
typedef struct nodeType{
 T info;
 nodeType<T> *link;
}node;


#endif
