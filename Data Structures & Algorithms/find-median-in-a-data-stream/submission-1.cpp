class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>> max;

    MedianFinder() {}

    void addNum(int num) {

        if (max.empty() || num <= max.top()) {
            max.push(num);
        } 
        else {
            min.push(num);
        }

        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        }
        else if (min.size() > max.size() + 1) {
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian() {

        if (max.size() == min.size()) {
            return ((double)max.top() + min.top()) / 2.0;
        }

        if (max.size() > min.size()) {
            return max.top();
        }

        return min.top();
    }
};