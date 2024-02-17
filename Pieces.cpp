#include <iostream>
#include <string>


using namespace std;

#define xune pair<int, int>
#define R first
#define C second

string brd[8][8];


bool solve (string str, char clr) {
    if (str.length() == 5)
        str = 'S' + str;
    
    xune s, e;
    s.R = str[2] - '1';
    s.C = str[1] - 'a';
    e.R = str[5] - '1';
    e.C = str[4] - 'a';
    
    string tmp;
    int s_r, s_c;
    
    switch (str[0]) {
        case 'S' :
            //Pawns
            tmp = "";
            tmp += clr;
            tmp += 'S';
            if (brd[s.R][s.C] != tmp)
                return false;
            if (brd[e.R][e.C][0] == clr)
                return false;
            
            if (clr == 'W') {
                if (s.C - e.C == 0) {
                    if (e.R - s.R <= 0)
                        return false;
                    if (e.R - s.R > 2)
                        return false;
                    if (e.R - s.R == 2)
                        if (s.R != 1)
                            return false;
                    if (brd[e.R][e.C] != "EM" || str[3] != '-')
                        return false;
                }
                else {
                    if (abs(s.C - e.C) != 1)
                        return false;
                    if (e.R - s.R != 1)
                        return false;
                    if (brd[e.R][e.C] == "EM" || str[3] != 'x')
                        return false;
                }
            }
            else {
                if (s.C - e.C == 0) {
                    if (s.R - e.R <= 0)
                        return false;
                    if (s.R - e.R > 2)
                        return false;
                    if (s.R - e.R == 2)
                        if (s.R != 6)
                            return false;
                    if (brd[e.R][e.C] != "EM" || str[3] != '-')
                        return false;
                }
                else {
                    if (abs(s.C - e.C) != 1)
                        return false;
                    if (s.R - e.R != 1)
                        return false;
                    if (brd[e.R][e.C] == "EM" || str[3] != 'x')
                        return false;
                }
            }
            
            brd[e.R][e.C] = brd[s.R][s.C];
            brd[s.R][s.C] = "EM";
            return true;
            
            break;
        case 'Q' :
            //Queen/////////////////////////////////////////////////////////////////////////////////
            tmp = "";
            tmp += clr;
            tmp += 'Q';
            if (brd[s.R][s.C] != tmp)
                return false;
            if (brd[e.R][e.C][0] == clr)
                return false;
            
            
            if (s.R == e.R && s.C == e.C)
                return false;
            
            if (abs(s.R - e.R) == abs(s.C - e.C)) {
                s_r = s_c = 1;
                if (e.R < s.R)
                    s_r = -1;
                if (e.C < s.C)
                    s_c = -1;
                
                for (int i = s.R + s_r, j = s.C + s_c; i != e.R; i += s_r, j += s_c)
                    if (brd[i][j] != "EM")
                        return false;
            
            }
            else if (s.R == e.R || s.C == e.C) {
                if (s.R != e.R) {
                    for (int i = min(s.R, e.R) + 1; i < max(s.R, e.R); ++i)
                        if (brd[i][s.C] != "EM")
                            return false;
                }
                else if (s.C != e.C) {
                    for (int j = min(s.C, e.C) + 1; j < max(s.C, e.C); ++j)
                        if (brd[s.R][j] != "EM")
                            return false;
                }
            }
            else
                return false;
            
            if (brd[e.R][e.C] == "EM" && str[3] != '-')
                return false;
            if (brd[e.R][e.C] != "EM" && str[3] != 'x')
                return false;
            
            brd[e.R][e.C] = brd[s.R][s.C];
            brd[s.R][s.C] = "EM";
            return true;
            //////////////////////////////////////////////////////////////////////////////////////////
            break;
        case 'K' :
            //King
            tmp = "";
            tmp += clr;
            tmp += 'K';
            if (brd[s.R][s.C] != tmp)
                return false;
            if (brd[e.R][e.C][0] == clr)
                return false;
            if (brd[e.R][e.C] == "EM" && str[3] != '-')
                return false;
            if (brd[e.R][e.C] != "EM" && str[3] != 'x')
                return false;
            if (!( abs(s.R - e.R) <= 1 && abs(s.C - e.C) <= 1 && abs(s.R - e.R) + abs(s.C - e.C) >= 1 ))
                return false;
            
            brd[e.R][e.C] = brd[s.R][s.C];
            brd[s.R][s.C] = "EM";
            return true;
            
            break;
        case 'R' :
            //Rooks
            tmp = "";
            tmp += clr;
            tmp += 'R';
            if (brd[s.R][s.C] != tmp)
                return false;
            if (brd[e.R][e.C][0] == clr)
                return false;
            if (s.R != e.R) {
                if (s.C != e.C)
                    return false;
                for (int i = min(s.R, e.R) + 1; i < max(s.R, e.R); ++i)
                    if (brd[i][s.C] != "EM")
                        return false;
            }
            else if (s.C != e.C) {
                if (s.R != e.R)
                    return false;
                for (int j = min(s.C, e.C) + 1; j < max(s.C, e.C); ++j)
                    if (brd[s.R][j] != "EM")
                        return false;
            }
            else
                return false;
            
            if (brd[e.R][e.C] == "EM" && str[3] != '-')
                return false;
            if (brd[e.R][e.C] != "EM" && str[3] != 'x')
                return false;
            
            brd[e.R][e.C] = brd[s.R][s.C];
            brd[s.R][s.C] = "EM";
            return true;
            
            break;
        case 'B' :
            //Bishop
            tmp = "";
            tmp += clr;
            tmp += 'B';
            if (brd[s.R][s.C] != tmp)
                return false;
            if (brd[e.R][e.C][0] == clr)
                return false;
            if (abs(s.R - e.R) != abs(s.C - e.C))
                return false;
            if (s.R == e.R)
                return false;
            
            s_r = s_c = 1;
            if (e.R < s.R)
                s_r = -1;
            if (e.C < s.C)
                s_c = -1;
            
            for (int i = s.R + s_r, j = s.C + s_c; i != e.R; i += s_r, j += s_c)
                if (brd[i][j] != "EM")
                    return false;
            
            if (brd[e.R][e.C] == "EM" && str[3] != '-')
                return false;
            if (brd[e.R][e.C] != "EM" && str[3] != 'x')
                return false;
            
            brd[e.R][e.C] = brd[s.R][s.C];
            brd[s.R][s.C] = "EM";
            return true;
            
            break;
        case 'N' :
            //Knight
            tmp = "";
            tmp += clr;
            tmp += 'N';
            if (brd[s.R][s.C] != tmp)
                return false;
            if (brd[e.R][e.C][0] == clr)
                return false;
            if (brd[e.R][e.C] == "EM" && str[3] != '-')
                return false;
            if (brd[e.R][e.C] != "EM" && str[3] != 'x')
                return false;
            if (!( (abs(s.R - e.R) == 1 && abs(s.C - e.C) == 2) || (abs(s.R - e.R) == 2 && abs(s.C - e.C) == 1) ))
                return false;
            
            brd[e.R][e.C] = brd[s.R][s.C];
            brd[s.R][s.C] = "EM";
            return true;
            
            break;
    }
    
    
    return false;
}


int main () {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            brd[i][j] = "EM";
    
    for (int i = 0; i < 8; ++i)
        brd[1][i] = "WS";
    for (int i = 0; i < 8; ++i)
        brd[6][i] = "BS";
    
    brd[0][0] = "WR";
    brd[0][7] = "WR";
    brd[7][0] = "BR";
    brd[7][7] = "BR";
    
    brd[0][1] = "WN";
    brd[0][6] = "WN";
    brd[7][1] = "BN";
    brd[7][6] = "BN";
    
    brd[0][2] = "WB";
    brd[0][5] = "WB";
    brd[7][2] = "BB";
    brd[7][5] = "BB";
    
    brd[0][4] = "WK";
    brd[0][3] = "WQ";
    
    brd[7][4] = "BK";
    brd[7][3] = "BQ";
    
    while (true) {
        string imp;
        getline(cin, imp);
        
        
        string tmp = "";
        int flag = 1;
        while (imp[flag - 1] != '.') {
            cout << imp[flag - 1];
            ++flag;
        }
        
        while (imp[flag] != ' ') {
            tmp += imp[flag];
            flag++;
        }
        
        if (solve(tmp, 'W'))
            cout << '.' << "valid ";
        else
            cout << '.' << "invalid ";
        
        tmp = "";
        
        while (flag + 1 < imp.length() && imp[flag + 1] != '#') {
            tmp += imp[flag + 1];
            flag++;
        }
        
        if (solve(tmp, 'B'))
            cout << "valid\n";
        else
            cout << "invalid\n";
        
        if (imp[imp.length() - 1] == '#')
            break;
    }
    
    return 0;
}


