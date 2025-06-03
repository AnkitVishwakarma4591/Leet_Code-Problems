    # include <bits/stdc++.h>
    using namespace std;

    int addDigits(int num) {
        int sum = 0;
        if(num <= 9){
            return num;
        }else{ 
            while(num > 0){
                int r = num % 10;
                sum += r;
                num /= 10;
            }
        }

        return addDigits(sum);
    }

    int main(){
        int num = 38;
        cout<<addDigits(num)<<endl;

        return 0;
    }