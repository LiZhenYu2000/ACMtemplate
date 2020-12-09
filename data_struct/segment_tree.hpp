#include <iostream>
#include <vector>
#include <stack>

namespace data_struct{
    struct node{
        size_t left{0}, right{0}, pos{0};
        bool tag {false};
        long long sum{0};
        
        node(){}
        node(size_t l, size_t r, size_t p, bool t, long long s);
    };
    
    template<typename T>
    class segment_tree
    {
    private:
        std::vector<node> tree{0};
        size_t size{0};
    protected:
        std::stack<node> tmp_tree;
        void build_tree(std::vector<T> terms);
    public:
        segment_tree(T terms[], size_t size);
        segment_tree(std::vector<T> terms);
        segment_tree(){}
        void update_tree(size_t i);
        void output();
        // ~segment_tree();
    };
    
    node::node(size_t l, size_t r, size_t p, bool t, long long s)
    :left{l}, right{r}, pos{p}, tag{t}, sum{s}{}

    template<typename T>
    void segment_tree<T>::update_tree(size_t i){
        if (i >= size)
        {
            return ;
        }
        while (i)
            if (i%2)
            {
                tree[i/2].sum = tree[i].sum + tree[i + 1].sum;
                i /= 2;
            }
            else
            {
                tree[(i - 2) / 2].sum = tree[i].sum + tree[i - 1].sum;
                i /= 2;
            }
    }

    template<typename T>
    void segment_tree<T>::output(){
        for (auto &&i : tree)
        {
            std::cout << i.sum << ' ';
        }
        std::cout << std::endl;
    }

    template<typename T>
    void segment_tree<T>::build_tree(std::vector<T> terms){
        size_t left = 0;
        size_t right = terms.size() - 1;
        size_t mid;
        
        tmp_tree.push(node{left, right, 0, false, 0});
        
        while(!tmp_tree.empty()){
            node top = tmp_tree.top();
            mid = (top.left + top.right) / 2;
            
            if (top.left == top.right)
            {
                top.sum = terms[top.left];
                top.tag = true;
                tree[top.pos] = top;
                tmp_tree.pop();
            }
            else if (tree[2 * top.pos + 1].tag || tree[2 * top.pos + 2].tag)
            { 
                top.sum = tree[2 * top.pos + 1].sum + tree[2 * top.pos + 2].sum;
                top.tag = true;
                tree[top.pos] = top;
                tmp_tree.pop();
            }
            else
            {
                tmp_tree.push(node{top.left, mid, 2 * top.pos + 1, false, 0});
                tmp_tree.push(node{mid+1, top.right, 2 * top.pos + 2, false, 0}); 
            }
        }
    }

    template<typename T>
    segment_tree<T>::segment_tree(T terms[], size_t s)
    :size{s}
    {
        if (size != 0)
        {
            tree.resize(2 * size, node());
            build_tree(std::vector<T>(terms, terms + s));
        }
    }
    
    template<typename T>
    segment_tree<T>::segment_tree(std::vector<T> terms)
    :size{terms.size()}
    {
        if (size != 0)
        {
            tree.resize(2 * size, node());
            build_tree(terms);
        }
    }
}