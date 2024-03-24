#ifndef NODE_H
#define NODE_H

template<class Type>
class Node 
{
    private:
        Type value;
        Node<Type>* previous;
    
    public:
        Node() {}
        Node(const Type& val)
        { value = val; }
        Node(const Type& val, Node<Type>* point)
        { value = val; previous = point; }
        Type getItem(void)
        { return value; }
        void setItem(Type entry)
        { value = entry; }
        Node<Type>* getPrevious(void)
        { return previous; }
        void setPrevious(Node<Type>* point)
        { previous = point; }

};

#endif