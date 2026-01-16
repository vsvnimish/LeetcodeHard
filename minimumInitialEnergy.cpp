bool comp(vector<int>& a, vector<int>& b){
             int s1 = max(0,b[1] - a[1] + a[0]) + a[1];
             int s2 = max(0,a[1] - b[1] + b[0]) + b[1];
             if(s1<s2) return true;
             return false;
}
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
         sort(tasks.begin(),tasks.end(),comp);
         int upperbound = tasks[0][1];
         int totalenergy = tasks[0][0];
         for(int i=1;i<tasks.size();i++){
             int reduced = upperbound - totalenergy;
             int diff = max(0,tasks[i][1] - reduced);
             upperbound+=diff;
             totalenergy += tasks[i][0];
         }
         return upperbound;
    }
};
