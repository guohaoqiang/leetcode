class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = jobs.upper_bound(start);
        if (it==jobs.end() || (*it).second>=end){
            jobs[end] = start;
            return true;
        }
        return false;
    }
    map<int,int> jobs;
};

