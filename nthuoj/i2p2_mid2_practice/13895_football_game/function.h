#include<iostream>
using namespace std;

class Ball {
    public:
        Ball(int _x, int _y): x(_x), y(_y) {}
        void SetX(int x) {
            this->x = x;
        }
        void SetY(int y) {
            this->y = y;
        }
        int GetX() {
            return x;
        }
        int GetY() {
            return y;
        }
    private:
        int x, y;
};

class Player {
    public:
        Player(int _x, int _y): x(_x), y(_y), holdball(false) {}
        void CatchBall(Ball* ball) {
            x = ball->GetX();
            y = ball->GetY();
            holdball = true;
        }
        void ReleaseBall() {
            holdball = false;
        }
        bool IsHoldingBall() {
            return holdball;
        }
        bool IsHere(int x, int y) {
            return (this->x == x && this->y == y);
        }
    private:
        int x, y;
        bool holdball;
};

class Field {
    public: 
        Field(int _n, int _m, int _p) {
            n = _n, m = _m, p = _p;
            int x, y;
            cin >> x >> y;
            ball = new Ball(x, y);
            for (int i = 0;i < p; ++i) {
                int x, y;
                cin >> x >> y;
                player[i] = new Player(x, y);
            }
        }
        ~Field() {
            delete ball;
            for (int iter = 0; iter < this->p; ++iter) {
                delete player[iter];
            }
        }
        int GetN() {
            return n;
        }
        int GetM() {
            return m;
        }

        // [TODO] Implement this function
        // Test if any player is at this position.
        bool SomeoneIsHere(int x, int y);

        // [TODO] Implement this function
        // Find the player who is holding the ball now.
        int GetWho();

        // [TODO] Implement this function
        void handleBallKicked(int dx, int dy);

        void GameStart(int rounds) {
            for (int iter = 0;iter < rounds; ++iter) {
                int ty;
                int player_id;
                int dx, dy, who;
                cin >> ty;
                switch (ty) {
                    case 1:
                        cin >> player_id;
                        for (int iter = 0;iter < p; ++iter) player[iter]->ReleaseBall();
                        player[player_id]->CatchBall(ball);
                        break;
                    case 2:
                        cin >> dx >> dy;
                        who = GetWho();
                        if (who != -1) {
                            player[who]->ReleaseBall();
                            handleBallKicked(dx, dy);
                        }
                        break;
                    case 3:
                        cout << "Player " << GetWho() << " is holding the ball!\n";
                        cout << "Ball is at " << ball->GetX() << ", " << ball->GetY() << ".\n";
                        break;
                }
            }
            return ;
        }
    private:
        int n, m, p;
        Ball* ball;
        Player* player[20];
};
