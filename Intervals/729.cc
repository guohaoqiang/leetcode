class MyCalendar {
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        auto it = t.lower_bound(start);
        if (it!=t.end() && (*it).first<end)    return false;
        if (it!=t.begin() && (*--it).second>start)    return false;
        t[start] = end;
        return true;
    }
    map<int,int> t;
};
