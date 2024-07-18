struct ListNodee {
    public:
    string url;
    ListNodee* prev;
    ListNodee* next;
    ListNodee(string str){
        url = str;
        prev = NULL;
        next = NULL;
    }    
};
class BrowserHistory {
public:
    ListNodee* curr;
    BrowserHistory(string homepage) {
        curr = new ListNodee(homepage);
    }
    
    void visit(string url) {
        ListNodee* neww = new ListNodee(url);
        curr->next = neww;
        neww->prev = curr;
        curr = neww;
    }
    
    string back(int steps) {
        while(curr->prev && steps){
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next && steps){
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */