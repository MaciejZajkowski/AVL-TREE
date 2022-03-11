#include <iostream>
#include <fstream>
template <typename Key, typename Info>
class AVL_TREE{
    struct element{
        element* right;
        element* left;
        Key key;
        Info info;
    };
    int number_of_elements;
    element* head;
    element* Find(const Key where);
    element* FindInsertplace(const Key newkey);
    bool Balance(element* location);
    int height(element* location);
    bool insertion(const Key newkey,const Info newinfo,element* place);
    int Max(int a, int b);
    bool CheckB(element* location);
    element* FindParent(const Key key);
    bool rightRotate(element* n);
    bool leftRotate(element* n);
    bool printing(bool flag, element* n);
    element* cp(element* location);
    bool del(element* location);
    bool comp(element* location1, element* location2);
    bool print_distance(element* location, int h);
    int distance(element* location);
public:
    AVL_TREE();
    AVL_TREE(const AVL_TREE& a);
    ~AVL_TREE();
    bool CheckBalance(){ return CheckB(head);}
    bool operator ==(const AVL_TREE&);
    int getcount();
    bool CheckParameter(const Key key);
    bool Insert(Key newKey, Info newinfo);
    bool Removal(Key where);
    bool GetInfo(Key where, Info& info);
    bool ChangeInfo(Key where, Info& info);
    bool Print(bool flag);
    bool Visual_Print();
    AVL_TREE<Key, Info>& operator = (AVL_TREE<Key, Info>& b){
        this->~AVL_TREE();
        element* l;
        l = cp(b.head);
        this->head = l;
        this->number_of_elements = b.getcount();
        return *this;
    };
    bool ReturnSmallest(Key& key, Info& info);
    bool ReturnBiggest(Key& key, Info& info);
};
template <typename Key, typename Info>
AVL_TREE<Key, Info> ::AVL_TREE(){
    head = nullptr;
    number_of_elements = 0;
};
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>:: operator==( const AVL_TREE<Key, Info>& x){
    return comp(head, x.head);
}
template <typename Key, typename Info>
bool AVL_TREE<Key, Info> ::comp(element* location1, element* location2){
    if(location1 ==  nullptr && location2 ==  nullptr)
        return true;
    else if(location1 !=  nullptr && location2 !=  nullptr){
    if(location1->info != location2->info || location1->info != location2->info)
        return false;
    return  comp(location1->left, location2->left) && comp(location1->right, location2->right);
    }
    else
        return false;
};
template <typename Key, typename Info>
AVL_TREE<Key, Info> ::~AVL_TREE(){
    del(head);
};
template <typename Key, typename Info>
bool AVL_TREE<Key, Info> ::del(element* locaction){
    if(locaction ==  nullptr)
        return true;
    head =  nullptr;
    bool flag = del(locaction->left) && del(locaction->right);
    delete locaction;
    return flag;
};
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>::GetInfo(Key where, Info& info){
    if(!Find(where))
        return false;
    else
        info = Find(where)->info;
    return true;
};
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>::ChangeInfo(Key where, Info& info){
    if(!Find(where))
        return false;
    else
        Find(where)->info =  info;
    return true;
};
template <typename Key, typename Info>
AVL_TREE<Key, Info> ::AVL_TREE(const AVL_TREE& a){
    head = cp(a.head);
};
template <typename Key, typename Info>
typename AVL_TREE<Key,Info> :: element* AVL_TREE<Key,Info>::cp(element* location){
    if(location == nullptr)
        return nullptr;
    element* ne =  new element();
    ne->key = location->key;
    ne->info= location->info;
    ne->left = cp(location->left);
    ne->right = cp(location->right);
    return ne;
};
using namespace std;
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::Insert(const Key newkey,const Info newinfo){
    if(CheckParameter(newkey))
        return false;
    if(!insertion(newkey,newinfo,FindInsertplace(newkey)))
        return false;
    element* location = FindParent(newkey);
    int bal;
    if(!location)
        return true;
    while(location!= nullptr)  {
        bal = height(location->left) - height(location->right);
        if (bal > 1 && newkey < location->left->key){
            rightRotate(location);
        }
        else if (bal < -1 && newkey > location->right->key){
            leftRotate(location);
        }
        else if (bal > 1 && newkey > location->left->key)
        {
            leftRotate(location->left);
            rightRotate(location);
        }
        else if (bal < -1 && newkey < location->right->key)
        {
            rightRotate(location->right);
            leftRotate(location);
        }
    location = FindParent(location->key);
    }
    return CheckBalance();
};
template <typename Key, typename Info>
int AVL_TREE<Key,Info>::height(element* location){
    if(location == nullptr)
        return 0;
    int h;
    h = Max(height(location->right),height(location->left)) + 1;
    return h;
};
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::CheckB(element* location){
    if(location == nullptr)
        return true;
    bool flag =  true;
    int a = 0;
    a = height(location->left) - height(location->right);
    if (a < 0)
        a = a* (-1);
    if(a > 1)
        return false;
    flag = CheckB(location->left) && CheckB(location->right);
    return flag;
};
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::insertion(const Key newkey,const Info newinfo,element* place){
    element* ne = new element();
    ne->info = newinfo;
    ne->key = newkey;
    if(place == nullptr){
        number_of_elements = 1;
        head = ne;
        return true;
    }
    if(newkey > place->key){
        if(place->right ==  nullptr){
            place->right = ne;
    }
    else
        return false;
    }
    if(newkey < place->key){
        if(place->left ==  nullptr){
                place->left = ne;
    }
    else
        return false;
    }
    if(newkey == place->key)
        return false;
    number_of_elements++;
    return true;
}
using namespace std;
template <typename Key, typename Info>
typename AVL_TREE<Key,Info> :: element* AVL_TREE<Key,Info>::Find(const Key where){
    element* current = new element();
    current = head;
    while(current != nullptr){
        if(where == current->key)
            return current;
        if(where< current->key)
            current = current->left;
        else if (where> current->key)
            current = current->right;
    }
    return nullptr;
}
template <typename Key, typename Info>
typename AVL_TREE<Key,Info> :: element* AVL_TREE<Key,Info>::FindInsertplace( const Key where){
    element* current = head;
    if(head == nullptr)
        return head;
    while(current != nullptr){
        if(where == current->key)
            return nullptr;
        if(where< current->key){
            if(current->left == nullptr)
                return current;
            current = current->left;
            }
        if (where> current->key){
            if(current->right == nullptr)
                return current;
            current = current->right;
        }
    }
    return nullptr;
}
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::rightRotate(element* loc){
    element* parent = FindParent(loc->key);
    element* a = loc->left;
    element* b = a->right;
    a->right = loc;
    loc->left = b;
    if(parent){
        if( a->key < parent->key)
            parent->left = a;
        if( a->key > parent->key)
            parent->right = a;
    }
    if(head == loc)
        head = a;
    return true;
}
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::leftRotate(element* loc){
    element* parent = FindParent(loc->key);
    element* a = loc->right;
    element* b = a->left;
    a->left = loc;
    loc->right = b;
    if(parent){
        if( a->key < parent->key)
            parent->left = a;
        if( a->key > parent->key)
            parent->right = a;
    }
    if(head == loc)
        head = a;
    return true;
};
using namespace std;
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::printing(bool flag, element* n){
     if(n ==  nullptr)
        return false;
     cout<< "Key: " << n->key <<" Info: "<< n->info << endl;
     if(flag){
        printing(flag,n->left);
        printing(flag,n->right);
     }
     else{
        printing(flag,n->right);
        printing(flag,n->left);
     }
     return true;
};
using namespace std;
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::Print(bool flag){
    cout<<"printing AVL tree from";
    if(flag)
        cout<<" left to right"<<endl;
    else{
        cout<<" right to left"<< endl;
    }
    printing(flag,head);
    return true;
};
template <typename Key, typename Info>
typename AVL_TREE<Key,Info> :: element* AVL_TREE<Key,Info>::FindParent(Key where){
    if (head->key == where){
        return nullptr;
    }
    element* current = head;
    element* parent = head;
    while(current != nullptr){
        if(where == current->key)
            return parent;;
        if(where< current->key){
            parent = current;
            current = current->left;
        }
        if (where> current->key){
            parent = current;
            current = current->right;
        }
    }
    return nullptr;
};
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::CheckParameter(const Key key){
    if(!Find(key))
        return false;
    return true;
};
template <typename Key, typename Info>
int AVL_TREE<Key,Info>::Max(int a, int b){
    if (a >= b)
        return a;
    else return b;
};
template <typename Key, typename Info>
bool AVL_TREE<Key,Info>::Removal(Key where){
    element* current = Find(where);
    element* parent = FindParent(where);
    element* nx;
    if(!current)
        return false;
    number_of_elements--;
    if(current->left ==  nullptr && current ->right == nullptr){
        if(current== head)
            head =  nullptr;
        else if(parent->key < where)
            parent->right =  nullptr;
        else
            parent->left = nullptr;
        delete current;
        nx =  parent;
        if(head == nullptr)
            return true;
    }
    else if(current->left ==  nullptr || current ->right == nullptr){
        if(current->left ==  nullptr){
             nx = current->right;
        }
        else{
            nx = current->left;
        }
        if(current== head)
            head =  nx;
        else if(parent->key < where)
            parent->right =  nx;
        else
            parent->left = nx;
        delete current;
        if(head == nx)
            return true;
    }
    else if(current->left != nullptr && current->right != nullptr){
        nx = current->right;
        while(nx->left){
            nx = nx->left;
        }
        if(FindParent(nx->key) != current)
            FindParent(nx->key)->left =  nx->right;
        if(current ==  head){
            head = nx;
        }
        else{
            if(parent->key< current-> key)
                parent->right = nx;
            else
                parent->left =  nx;
        }
        nx->left = current->left;
        if(nx == current->right)
            nx->right = nullptr;
        else
            nx->right = current->right;
    }

    if(!nx)
        return true;
    if(FindParent(nx->key))
        nx = FindParent(nx->key);
    int bal;
    bal = height(nx->left) - height(nx->right);
    if (bal > 1 && nx->left != nullptr &&
        height(nx->left->left) - height(nx->left->right) >= 0)
        return rightRotate(nx);
    else if (bal > 1 &&
        nx->left != nullptr &&
        height(nx->left->left) - height(nx->left->right) < 0)
    {
        leftRotate(nx->left);
        return rightRotate(nx);
    }
    // Right Right Case
    else if (bal < -1 &&nx->right != nullptr &&
        height(nx->right->left) - height(nx->right->right)<= 0)
        return leftRotate(nx);
    // Right Left Case
    else if (bal < -1 &&
        nx->right != nullptr &&
        height(nx->right->left) - height(nx->right->right) > 0)
    {
        rightRotate(nx->right);
        return leftRotate(nx);
    }
    return true;
}
template <typename Key, typename Info>
int AVL_TREE<Key,Info>::getcount(){
return number_of_elements;};
using namespace std;
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>::  Visual_Print(){
    int headheight = height(head);
    int currheight = headheight;
    cout<<"Visual Printing tree"<<endl;
    int dis =1;
    while(headheight >= dis){
        cout <<" Height: " <<currheight<<" -    ";
        print_distance(head,dis);
        dis++;
        currheight --;
        cout<<endl<<endl;
    }
    return true;
};
using namespace std;
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>:: print_distance(element* location, int h){
    if(h < 1)
        return false;
    if(location ==  nullptr){
        cout<<"empty   ";
        return true;
    }
    element* parent = FindParent(location->key);
    int dis = distance(location);
    if(h < dis)
        return false;
    if(h == dis){
        cout<<"Key: " << location->key <<" Info: " << location->info;
        if(parent)
            cout<<" -Parent("<< parent->key<<")";
        cout<<"    ";
        return true;
    }
    if( dis < h){
        print_distance(location->left,h);
        print_distance(location->right,h);
        return true;
    }
    return false;
};
template <typename Key, typename Info>
int AVL_TREE<Key, Info>::distance(element* location){
    if(location == nullptr)
        return 0;
    int sum = 1;
    element* parent = FindParent(location->key);
    while(parent){
        location = parent;
        parent = FindParent(location->key);
        sum++;
    }
        return sum;
}
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>::ReturnSmallest(Key& key, Info& info){
    element* curr = head;
    if(!curr)
        return false;
    while(curr->left){
        curr = curr->left;
    }
    key = curr->key;
    info = curr->info;
    return true;
};
template <typename Key, typename Info>
bool AVL_TREE<Key, Info>::ReturnBiggest(Key& key, Info& info){
    element* curr = head;
    if(!curr)
        return false;
    while(curr->right){
        curr = curr->right;
    }
    key = curr->key;
    info = curr->info;
    return true;
};
