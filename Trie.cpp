struct node {
    node *next[26];     //Массив указателей на следующие вершины
    //next[i] - указатель на следующую вершину, соответствующую символу ('a' + i)
    //(предполагается, что используются только строчные латинские буквы)

    int strings;        //Количество строк, заканчивающихся в этой вершине.
    node() {
        for (int i = 0; i < 26; i++) {   //изначально заполняем next нулевыми указателями,
            next[i] = nullptr;           //так как следующие вершины ещё не созданы
        }

        strings = 0;
    }
};
node *root = new node();
string cur_str = "";
void add(const string& s) {
    node *cur_v = root;     //текущая вершина

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (cur_v->next[c - 'a'] == nullptr) {
            cur_v->next[c - 'a'] = new node();
        }
        cur_v = cur_v->next[c - 'a'];
    }

    cur_v->strings++;
}

bool has(const string& s) {
    node *cur_v = root;


    for (int i = 0; i < s.length(); i++) {
        cur_v = cur_v->next[s[i] - 'a'];
        if (cur_v == nullptr) {
            return false;
        }
    }

    return cur_v->strings > 0;
}



void write(node *v = root) {
    for (int i = 0; i < v->strings; i++) {
        cout << cur_str << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (v->next[i] != nullptr) {
            cur_str.push_back('a' + i);
            write(v->next[i]);
            cur_str.pop_back();
        }
    }
}

void remove(string &s)
{
    node *cur_v = root;
    stack <node*> st;
    for(int i = 0; i < s.length(); i ++)
    {
        char c = s[i];
        cur_v = cur_v->next[c - 'a'];
        st.push(cur_v);
    }
    if (cur_v->strings > 1)
    {
        cur_v->strings--;
    }
    else
    {
        while(cur_v->strings == 1)
        {
            delete cur_v;
            cur_v = st.top();
            st.pop();
        }
    }
}
