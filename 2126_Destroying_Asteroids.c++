# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long result = mass;
        for(int i = 0 ; i < asteroids.size() ; i++){
            if(result >= asteroids[i]){
                result += asteroids[i];
            }else if(result >= 1e5){
                return true;
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s1;
    int mass = 10;
    vector<int> asteroids = {3,9,19,5,21};

    cout<<s1.asteroidsDestroyed(mass, asteroids)<<endl;
    
    return 0;
}