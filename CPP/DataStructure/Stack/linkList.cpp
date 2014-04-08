/*template <class T>
class SLinkedList { // a singly linked list
    public:
        SLinkedList(); // empty list constructor
        ~SLinkedList(); // destructor
        bool empty() const; // is list empty?
        const T& front() const; // return front element
        void addFront(const T& e); // add to front of list
        void removeFront(); // remove front item list
    private:
        SNode<T>* head; // head of the list
};*/

template <class T>
SLinkedList::SLinkedList():m_head(NULL){}

template <class T>
bool SLinkedList::empty() const{
    return (head == NULL ? true:false);
}

template <class T>
T &SLinkedList::front() const{
    return head->elem;
}

template <class T>
void SLinkedList::addFront(const T &e) {
    SNode<T> *temp = new SNode<T>;
    temp->elem  = e;
    temp->next  = head;
    head  = temp;
}

template <class T>
void SLinkedList::removeFront(){
    SNode<T> *temp  = head;
    head = temp->next;
    delete temp;
}

template <class T>
SLinkedList::~SLinkedList(){
    
}

