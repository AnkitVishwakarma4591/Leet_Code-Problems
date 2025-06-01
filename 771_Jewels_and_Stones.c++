    # include <bits/stdc++.h>
    using namespace std;
    
    int numJewelsInStones(string jewels, string stones) {

        int n = stones.size();
        int count = 0;
        vector<bool> check(n,true);

        for(int i = 0 ; i < jewels.size() ; i++){
            for(int j = 0 ; j < n ; j++){
                if(jewels[i] == stones[j] && check[j] == true){
                    count++;
                    check[j] = false;
                }
            }
        }
        return count;
    }

    int main(){
        string jewels = "aA", stones = "aAAbbbb";

        cout<<numJewelsInStones(jewels,stones)<<endl;
        return 0;
    }