#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;
char a[8][8];
int change = 0;

void board(int bm) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    if (bm == 1) {
        cout << '\t';
        for (int k = 1; k <= 8; k++)
            cout << k << '\t';
        cout << endl;
        cout << endl;
        for (int i = 0; i < 8; i++) {
            cout << i + 1 << '\t';
            for (int j = 0; j < 8; j++) {
                cout << a[i][j] << '\t';
            }
            cout << endl << endl;
        }
    } else {
        
        int k = 249;    //you can change the background color by changing this number and the next k integer
        SetConsoleTextAttribute(hConsole, k);
        cout << "   1   2   3   4   5   6   7   8  " << "\n";
        cout << " +---+---+---+---+---+---+---+---+" << endl;
        for (int i = 0; i < 8; i++) {
            cout << i + 1;
            for (int j = 0; j < 8; j++) {
                cout << "| " << a[i][j] << " ";
            }
            cout << "|" << endl;

        }
        cout << " +---+---+---+---+---+---+---+---+" << endl;
    }
    int k = 7;
    SetConsoleTextAttribute(hConsole, k);
}

int east(int x, int y, char ch, int flag) {
    int l = y, f = 0;
    if (a[x][y + 1] == ch || a[x][y + 1] == '-')
        return 0;
    for (int i = y + 2; i < 8; i++) {
        if (a[x][i] == '-')
            return 0;
        if (a[x][i] == ch) {
            l = i;
            break;
        }
    }
    for (int j = l - 1; j >= y; j--) {
        if (flag == 1) // 1=user and pc , 0=AI check
        {
            a[x][j] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int west(int x, int y, char ch, int flag) {
    int l = y, f = 0;
    if (a[x][y - 1] == ch || a[x][y - 1] == '-')
        return 0;
    for (int i = y - 2; i >= 0; i--) {
        if (a[x][i] == '-')
            return 0;
        if (a[x][i] == ch) {
            l = i;
            break;
        }
    }
    for (int j = l + 1; j <= y; j++) {
        if (flag == 1) {
            a[x][j] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int north(int x, int y, char ch, int flag) {
    int l = x, f = 0;
    if (a[x - 1][y] == ch || a[x - 1][y] == '-')
        return 0;
    for (int i = x - 2; i >= 0; i--) {
        if (a[i][y] == '-')
            return 0;
        if (a[i][y] == ch) {
            l = i;
            break;
        }
    }
    for (int j = l + 1; j <= x; j++) {
        if (flag == 1) {
            a[j][y] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int south(int x, int y, char ch, int flag) {
    int l = x, f = 0;
    if (a[x + 1][y] == ch || a[x + 1][y] == '-')
        return 0;
    for (int i = x + 2; i < 8; i++) {
        if (a[i][y] == '-')
            return 0;
        if (a[i][y] == ch) {
            l = i;
            break;
        }
    }
    for (int j = l - 1; j >= x; j--) {
        if (flag == 1) {
            a[j][y] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int southwest(int x, int y, char ch, int flag) {
    int m = x, n = y, f = 0;
    if (a[x + 1][y - 1] == ch || a[x + 1][y - 1] == '-')
        return 0;
    for (int i = x + 2, j = y - 2; i < 8 && j >= 0; i++, j--) {
        if (a[i][j] == '-') {
            return 0;
        }
        if (a[i][j] == ch) {
            m = i;
            n = j;
            break;
        }
    }
    for (int i = m - 1, j = n + 1; i >= x && j <= y; i--, j++) {
        if (flag == 1) {
            a[i][j] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int southeast(int x, int y, char ch, int flag) {
    int m = x, n = y, f = 0;
    if (a[x + 1][y + 1] == ch || a[x + 1][y + 1] == '-')  // if the selected element was empty or same as the last one
        return 0;
    for (int i = x + 2, j = y + 2; i < 8 && j < 8; i++, j++)
    {
        if (a[i][j] == '-')
            return 0;
        if (a[i][j] == ch)
        {
            m = i;
            n = j;
            break;
        }
    }
    for (int i = m - 1, j = n - 1; i >= x && j >= y; i--, j--) {
        if (flag == 1)
        {
            a[i][j] = ch;
        }
        f = f +
            1;
    }
    if (f != 0)
    {
        change = 1;
        return f - 1; 
    } else
        return 0;
}

int northwest(int x, int y, char ch, int flag) {
    int m = x, n = y, f = 0;
    if (a[x - 1][y - 1] == ch || a[x - 1][y - 1] == '-')
        return 0;
    for (int i = x - 2, j = y - 2; i >= 0 && j >= 0; i--, j--) {
        if (a[i][j] == '-')
            return 0;
        if (a[i][j] == ch) {
            m = i;
            n = j;
            break;
        }
    }
    for (int i = m + 1, j = n + 1; i <= x && j <= y; i++, j++) {
        if (flag == 1) {
            a[i][j] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int northeast(int x, int y, char ch, int flag) {
    int m = x, n = y, f = 0;
    if (a[x - 1][y + 1] == ch || a[x - 1][y + 1] == '-')
        return 0;
    for (int i = x - 2, j = y + 2; i >= 0 && j < 8; i--, j++) {
        if (a[i][j] == '-')
            return 0;
        if (a[i][j] == ch) {
            m = i;
            n = j;
            break;
        }
    }
    for (int i = m + 1, j = n - 1; i <= x && j >= y; i++, j--) {
        if (flag == 1) {
            a[i][j] = ch;
        }
        f = f + 1;
    }
    if (f != 0) {
        change = 1;
        return f - 1;
    } else
        return 0;
}

int pc_turn(char c) {
    int high = 0;
    int pc_entry = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == '-') {
                int check = 0;
                check = check + north(i, j, c, 0) + south(i, j, c, 0) + east(i, j, c, 0) + west(i, j, c, 0) +
                        northeast(i, j, c, 0) + northwest(i, j, c, 0) + southeast(i, j, c, 0) + southwest(i, j, c, 0);
                if (check > high) {
                    high = check;
                    pc_entry = (i * 10) + j;
                }
            }
        }
    }
    return pc_entry;
}

void score(int mode) {
    int white = 0, black = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 'w')
                white++;
            else
                black++;
        }
    }
    if (mode == 1)
        (white == black) ? (cout << "DRAW!!") : ((white > black) ? cout << "PC IS WINNER!!" : cout
                << "PLAYER IS WINNER!!" << endl);
    if (mode == 2)
        (white == black) ? (cout << "DRAW!!") : ((white > black) ? cout << "PLAYER 2 IS WINNER!!" : cout
                << "PLAYER 1 IS WINNER!!" << endl);

}

void load(int mode, int change, int x, int y, int c, int bm, char a[][8]) {
    ifstream myfile;
    myfile.open("data.txt");
    if (myfile.is_open()) {
        myfile >> mode;
        myfile >> change;
        myfile >> x;
        myfile >> y;
        myfile >> c;
        myfile >> bm;
        string line;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++) {
                getline(myfile, line);
                a[i][j] = line[0];
            }
        a[0][0] = '-';
        myfile.close();
    } else
        cout << "Error";
}


void save(int mode, int change, int x, int y, int c, int bm, char a[][8]) {
    ofstream myfile;
    myfile.open("data.txt");
    if (myfile.is_open()) {
        myfile << mode << "\n";
        myfile << change << "\n";
        myfile << x << "\n";
        myfile << y << "\n";
        myfile << c << "\n";
        myfile << bm << "\n";
        for (int i = 1; i < 9; i++)
            for (int j = 1; j < 9; j++)
                myfile << a[i][j] << "\n";
        myfile.close();
    } else
        cout << "Error";
}


int main() {
    int x, y, mode = 1, bm = 1;
    char c;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {    //filling all the board
            a[i][j] = '-';
        }
    }
    a[3][3] = a[4][4] = 'W';  //defaults
    a[3][4] = a[4][3] = 'B';
    cout << "____________________________________________________" << endl
         << " \n\tWelcome to this game! Othello by M.A. Asef \n" << endl << "\tKey Features " << endl
         << "\t- 2 different board (small size and super-size)" << endl
         << "\t- 2 playing mode (single player with AI and multi-player) " << endl
         << "\t- 2 way of starting the game (load the previous game or a starting a new game)" << endl
         << "\t Press any key to continue..." << endl << "____________________________________________________" << endl;

    cin.get();
    cout << "____________________________________________________" << endl << " \n\tPlease choose " << endl
         << "\t1. New game" << endl << "\t2. Load the previous game " << endl
         << "____________________________________________________" << endl;
    int gt = 0;
    cin >> gt;
    if (gt == 2) {
        load(mode, change, x, y, c, bm, a);
        board(bm);
        if (mode == 1) goto sp;
        else goto mp;

    }
    cout << "____________________________________________________" << endl << " \n\t Othello by M.A. Asef \n" << endl
         << "\tPlease choose " << endl << "\t1. Single player " << endl << "\t2. Multi-player " << endl
         << "____________________________________________________" << endl;
    int ch;
    cin >> ch;
    cout << "____________________________________________________" << endl << "\tPlease choose the board type " << endl
         << "\t1. 1.Super-size " << endl << "\t2. 2.Small size " << endl
         << "____________________________________________________" << endl;
    cin >> bm;
    cout << endl << "PLAYER 1 = B  _________  PLAYER 2 = W " << endl << " SAVE THE GAME BY ENTERING 10 10" << endl;
    board(bm);
    switch (ch) {
        case 1:
        sp:
            for (int move = 60; move > 0; move--) {
                (move % 2 == 0) ? cout << "PLAYER 1 (B) TURN : " << endl : cout << "COMPUTER (W) TURN : " << endl;
                c = ((move % 2) == 0) ? 'B' : 'W';
                if (move % 2 == 0) {
                    cout << "ENTER THE ROW AND COLUMN (EX: 4 3)";
                    cin >> x >> y;
                    x = x - 1;
                    y = y - 1;
                    if (a[x][y] == '-') {
                        east(x, y, c, 1);
                        west(x, y, c, 1);
                        north(x, y, c, 1);
                        south(x, y, c, 1);
                        northeast(x, y, c, 1);
                        northwest(x, y, c, 1);
                        southeast(x, y, c, 1);
                        southwest(x, y, c, 1);
                        if (change == 0) {
                            cout << "INVALID ENTRY, PLEASE TRY AGAIN" << endl;
                            move++;
                        }
                    } else {
                        if (x == 9 && y == 9) {
                            save(mode, change, x, y, c, bm, a);
                            cout << "The game has been saved successfully!" << endl;
                            goto one1;
                        }
                        cout << "INVALID ENTRY, PLEASE TRY AGAIN" << endl;
                        one1:
                        move++;
                    }
                } else {
                    int pc_entry = pc_turn(c);
                    x = pc_entry / 10;
                    y = pc_entry % 10;
                    cout << "COMPUTER ENTRY : " << x + 1 << " " << y + 1 << endl << endl;
                    east(x, y, c, 1);
                    west(x, y, c, 1);
                    north(x, y, c, 1);
                    south(x, y, c, 1);
                    northeast(x, y, c, 1);
                    northwest(x, y, c, 1);
                    southeast(x, y, c, 1);
                    southwest(x, y, c, 1);
                }
                board(bm);
                change = 0;
            }
            score(mode);

        mp:
        case 2:

            mode = 2;
            for (int move = 60; move > 0; move--) {
                change = 0;
                (move % 2 == 0) ? cout << "PLAYER 1 (B) TURN : " << endl : cout << "PLAYER 2 (W) TURN : " << endl;
                c = ((move % 2) == 0) ? 'B' : 'W';
                if (move % 2 == 0) {
                    cout << "ENTER THE ROW AND COLUMN (EX: 4 3)";
                    cin >> x >> y;
                    x = x - 1;
                    y = y - 1;
                    if (a[x][y] == '-') {
                        east(x, y, c, 1);
                        west(x, y, c, 1);
                        north(x, y, c, 1);
                        south(x, y, c, 1);
                        northeast(x, y, c, 1);
                        northwest(x, y, c, 1);
                        southeast(x, y, c, 1);
                        southwest(x, y, c, 1);
                        if (change == 0) {
                            cout << move << endl;
                            cout << "INVALID ENTRY, PLEASE TRY AGAIN" << endl;
                            move++;
                            cout << move << endl;
                        }
                    } else {
                        if (x == 9 && y == 9) {
                            save(mode, change, x, y, c, bm, a);
                            cout << "The game has been saved successfully!" << endl;
                            goto one;
                        }
                        cout << "INVALID ENTRY, PLEASE TRY AGAIN" << endl;
                        one:
                        move++;
                    }
                } else {
                    change = 0;
                    cout << "ENTER THE ROW AND COLUMN (EX: 4 3)";
                    cin >> x >> y;
                    x = x - 1;
                    y = y - 1;
                    if (a[x][y] == '-') {
                        east(x, y, c, 1);
                        west(x, y, c, 1);
                        north(x, y, c, 1);
                        south(x, y, c, 1);
                        northeast(x, y, c, 1);
                        northwest(x, y, c, 1);
                        southeast(x, y, c, 1);
                        southwest(x, y, c, 1);
                        if (change == 0) {
                            cout << "INVALID ENTRY, PLEASE TRY AGAIN" << endl;
                            move++;
                        }
                    } else {
                        if (x == 9 && y == 9) {
                            save(mode, change, x, y, c, bm, a);
                            cout << "The game has been saved successfully!" << endl;
                            goto one11;
                        }
                        cout << "INVALID ENTRY, PLEASE TRY AGAIN" << endl;  // if the selected element was empty or did'nt exist
                        one11:
                        move++;
                    }
                }
                board(bm);
            }
            score(mode);
            return 0;
    }
}
