#include <iostream>
#include <queue>
using namespace std;

struct Topic
{
    int id, old_score;
    long long new_score, change;

    // hàm operator để priority_queue push vào như yêu cầu đề bài
    bool operator<(const Topic &other) const {
        return change < other.change || (change == other.change && id < other.id); // max heap
    }
};

int main() {
    int n; cin >> n;
    int id, old_score, P, L, C, S;
    long long new_score;
    priority_queue<Topic> pq;

    while (n--) {
        cin >> id >> old_score >> P >> L >> C >> S;
        new_score = 50*P + 5*L + 10*C + 20*S;
        pq.push(Topic{id, old_score, new_score, new_score-old_score});
    }

    for (int i = 0; i < 5; i++) {
        Topic t = pq.top();
        pq.pop();
        cout << t.id << " " << t.new_score << "\n";
    }
    return 0;
}