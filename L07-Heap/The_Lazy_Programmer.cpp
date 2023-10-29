#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

struct Job
{
    int a, b, d;

    bool operator<(const Job &other) const {
        return a < other.a;
    }
};

bool cmp(const Job &x, const Job &y) {
    return x.d < y.d; 
}

int main() {
    int t, N;
    cin >> t;
    priority_queue<Job> pq;
    
    while (t--) {
        cin >> N;
        vector<Job> job(N);

        for (int i = 0; i < N; i++)
            cin >> job[i].a >> job[i].b >> job[i].d;

        sort(job.begin(), job.end(), cmp);
        double ans = 0;
        int time = 0;

        for (int i = 0; i < N; i++) {
            time += job[i].b;
            pq.push(job[i]);

            while (time > job[i].d) {
                Job top = pq.top();
                pq.pop();

                if (top.b > time - job[i].d) {
                    ans += 1.0*(time - job[i].d)/top.a;
                    top.b -= time - job[i].d;
                    pq.push(top);
                    time = job[i].d;
                }
                else {
                    ans += 1.0*top.b/top.a;
                    time -= top.b;
                    top.b = 0;
                }
            }
        }

        cout << fixed << setprecision(2) << ans << "\n";
        while (!pq.empty()) {
            pq.pop();
        }
    }

    return 0;
}