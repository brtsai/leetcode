class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizontal = 0;
        auto end = moves.end();
        for (auto itor = moves.begin(); itor != end; ++itor) {
            char c = *itor;
            switch (c) {
                case 'U':
                    ++vertical;
                    break;
                case 'D':
                    --vertical;
                    break;
                case 'L':
                    --horizontal;
                    break;
                case 'R':
                    ++horizontal;
                    break;
            }
        }
        
        return vertical == 0 && horizontal == 0;
    }
};
