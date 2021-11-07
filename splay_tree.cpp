#include <iostream>
#include <vector>
using namespace std;
// https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5418167#1
struct SplayNode{
    SplayNode *left, *right, *parent;
    int size, value;

    SplayNode(){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        size = 1;
    }

    void rotate(){
        SplayNode *pp, *p, *c;
        p = this->parent;
        pp = p->parent;

        if(p->left == this){
            c = this->right;
            this->right = p;
            p->left = c;
        }
        else{
            c = this->left;
            this->left = p;
            p->right = c;
        }
        if(pp && pp->left == p)pp->left = this;
        if(pp && pp->right == p)pp->right = this;
        this->parent = pp;
        p->parent = this;
        if(c)c->parent = p;

        p->update();
        this->update();
    }

    int state(){
        if(!this->parent)return 0;
        if(this->parent->left == this)return 1;
        if(this->parent->right == this)return -1;
        return 0;
    }
    
    void splay(){
        while(this->state() != 0){
            if(this->parent->state() == 0){
                this->rotate();
            }
            else if(this->state() == this->parent->state()){
                this->parent->rotate();
                this->rotate();
            }else{
                this->rotate();
                this->rotate();
            }
        }
    }
    
    void update(){
        this->size = 1;
        if(this->left)this->size += this->left->size;
        if(this->right)this->size += this->right->size;
    }    
};


SplayNode *get(int ind, SplayNode * root){
    SplayNode *now = root;
    while(true){
        int lsize = now->left ? now->left->size : 0;
        if(ind < lsize){
            now = now->left;
        }
        if(ind == lsize){
            now->splay();
            return now;
        }
        if(ind > lsize){
            now = now->right;
            ind = ind - lsize - 1;
        }
    }
}
