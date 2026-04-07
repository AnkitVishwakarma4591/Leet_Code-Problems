#include <bits/stdc++.h>
using namespace std;

class Robot {
public:
    int idx = 0;
    bool moved = false;
    vector<vector<int>> pos; // {x, y, dir}

    Robot(int width, int height) {

        if(height == 1){
            for(int x = 0; x < width; x++){
                pos.push_back({x, 0, 0});
            }
            for(int x = width - 2; x >= 0; x--){
                pos.push_back({x, 0, 2});
            }
        }
        else if(width == 1){
            for(int y = 0; y < height; y++){
                pos.push_back({0, y, 1});
            }
            for(int y = height - 2; y >= 0; y--){
                pos.push_back({0, y, 3});
            }
        }
        else{
            for (int x = 0; x < width; x++)
                pos.push_back({x, 0, 0});

            for (int y = 1; y < height; y++)
                pos.push_back({width - 1, y, 1});

            for (int x = width - 2; x >= 0; x--)
                pos.push_back({x, height - 1, 2});

            for (int y = height - 2; y > 0; y--)
                pos.push_back({0, y, 3});
        }

        pos[0][2] = 3;
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }

    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }

    string getDir() {
        if(!moved) return "East";

        int d = pos[idx][2];
        if(d == 0) return "East";
        if(d == 1) return "North";
        if(d == 2) return "West";
        return "South";
    }
};

int main(){
    // Example input simulation
    Robot* obj = new Robot(6, 3);

    obj->step(2);
    obj->step(2);

    vector<int> p1 = obj->getPos();
    cout << "[" << p1[0] << "," << p1[1] << "]" << endl;

    cout << obj->getDir() << endl;

    obj->step(2);
    obj->step(1);
    obj->step(4);

    vector<int> p2 = obj->getPos();
    cout << "[" << p2[0] << "," << p2[1] << "]" << endl;

    cout << obj->getDir() << endl;

    return 0;
}