#ifndef CFIGURE_H
#define CFIGURE_H


class CFigure
{
    char type;
    bool color;
    public:
        CFigure(char type, bool color);
        char GetType ();
        bool GetColor ();
        virtual ~CFigure();
};

//type: P - pawn , C - castel, K - knight, B - bishop, Q - queen, W - king

#endif // CFIGURE_H
