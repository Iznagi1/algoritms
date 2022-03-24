struct LinkedList
{
    struct Node
    {
        int data;
        Node* next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };
    Node* root = nullptr;

    ~LinkedList()
    {
        if(nullptr == root)
            return;

        while(root)
        {
            Node* cur = root->next;
            //cout << root->data;
            delete(root);
            root = cur;
        }
    }
public:
    void Push(int data);
    void Print();
    int operator[](int);
};



int main()
{
    LinkedList l;
    for(int i = 0; i < 10; i++)
        l.Push(i);
    //l.Print();

    cout << l[5];
}

void LinkedList::Push(int data)
{
    if(nullptr == root)
    {
        root = new Node(data);
        return;
    }

    Node* cur = root;
    while(cur->next)
    {
        cur = cur->next;
    }
    cur->next = new Node(data);
}

void LinkedList::Print()
{
    if(nullptr != root)
    {
        Node* cur = root;
        while(cur->next)
        {
            cout << cur->data << ' ';
            cur = cur->next;
        }
        cout << cur->data;
    }
    cout << '\n';
}

int LinkedList::operator [](int n)
{
    if(nullptr == root)
        return 1337;
    Node* cur = root;
    for(int i = 0; i <= n && nullptr != cur; i++)
    {
        cur = cur->next;
    }
    return cur->data;

}
