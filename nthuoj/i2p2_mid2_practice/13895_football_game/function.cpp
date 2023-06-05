    #include "function.h"

    bool Field::SomeoneIsHere(int x, int y) {
        for (int i = 0; i < p; ++i) {
            if (player[i]->IsHere(x, y)) 
                return true;
        }
        return false;
    }

    int Field::GetWho() {
        for (int i = 0; i < p; ++i) {
            if (player[i]->IsHoldingBall()) {
                return i;
            }
        }
        return -1;
    }

    void Field::handleBallKicked(int dx, int dy) {
        int now_x = ball->GetX(), now_y = ball->GetY();
        while (now_x+dx >= 0 && now_x+dx < n && now_y+dy >= 0 && now_y+dy < m) {
            now_x += dx, now_y += dy;
            if (SomeoneIsHere(now_x, now_y)) {
                for (int i = 0; i < p; ++i) {
                    if (player[i]->IsHere(now_x, now_y)) {
                        ball->SetX(now_x);
                        ball->SetY(now_y);
                        // player[i]->CatchBall(ball);
                        return ;
                    }
                }
                break;
            }
        }
        ball->SetX(now_x);
        ball->SetY(now_y);
    }