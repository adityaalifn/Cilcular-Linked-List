#include "circularlist.h"

void createList(List &L)
{
    first(L) = NULL;
}
address alokasi(infotype x)
{
    address P;
    P = new Elmlist;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void dealokasi(address &P)
{
    delete(P);
}

void insertFirst(List &L, address P)
{
    address Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertAfter(List &L, address Prec, address P)
{
    if (next(Prec) == first(L))
    {
        next(Prec) = P;
        next(P) = first(L);
    } else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertLast(List &L, address P)
{
    address Q;
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void deleteFirst(List &L, address &P)
{
    address Q;
    if (first(L) != NULL)
    {
        P = first(L);
        if(next(P) == NULL)
        {
            first(L) == NULL;
        }
        else
        {
            Q = first(L);
            while (next(Q) != first(L))
            {
                Q=next(Q);
            }
            first(L) = next(P);
            next(Q) = next(P);
            next(P) = NULL;

        }
    }
}
void deleteAfter(List &L, address Prec, address &P)
{
    if (next(Prec) == first(L))
    {
        P = first(L);
        first(L) = next(P);
        next(Prec) = first(L);
        next(P) = NULL;
    } else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void deleteLast(List &L, address &P)
{
    address Q;

    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            first(L) = NULL;
        } else
        {
            Q = first(L);
            while (next(next(Q)) != first(L))
            {
                Q =next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
            next(P) = NULL;

        }
    }
}

address findElm(List L, infotype x)
{
    address P;
    P = first(L);
    while (info(P) != x && next(P) != first(L))
    {
        P = next(P);
    }
    if (info(P) == x)
    {
        return P;
    } else
    {
        return NULL;
    }
}

void printInfo(List L)
{
    address P;

    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == first(L))
        {
            cout <<info(P);
        } else
        {

            do {
                cout <<info(P)<<endl;
                P = next(P);
            } while (P != first(L));
        }
    } else
    {
        cout << "LIST KOSONG";
    }
}
