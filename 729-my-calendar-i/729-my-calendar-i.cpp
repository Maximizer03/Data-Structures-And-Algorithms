class MyCalendar {
public:
	map<int, int>m;
	MyCalendar() {
	}
	bool book(int start, int end) {
		if (m.empty()) {
			m[start] = end;
			return true;
		}
		auto it = m.upper_bound(start);
		if (it != m.end() && end > it->first) {
			return false;
		}
		if (it != m.begin() && prev(it)->second > start) {
			return false;
		}
		m[start] = end;
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */