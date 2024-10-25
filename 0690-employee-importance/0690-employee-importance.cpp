/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int solve (vector<Employee*> employees, int id){
        int imp =0;
        for(auto e:employees){
            if(e->id == id){
                imp +=e->importance;
                if(e->subordinates.empty()) return imp;
                for(int sid:e->subordinates){
                    imp += solve(employees,sid);
                }
            }
        }
        return imp;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ans = solve(employees, id);
        return ans;
    }
};