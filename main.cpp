#include <iostream>
#include <cstdlib>
using namespace std;
void meniu()
{
    cout<<"1.Citire matrici"<<endl;
    cout<<"2.Transpusa"<<endl;
    cout<<"3.Adunarea"<<endl;
    cout<<"4.Scaderea"<<endl;
    cout<<"5.Inmultirea"<<endl;
    cout<<"6.Determinant"<<endl;
    cout<<"7.Iesire"<<endl;
}
void citire(int M[][21],int &lm,int &cm,char nume)
{
    int i,j;
    for(i=1;i<=lm;i++)
        for(j=1;j<=cm;j++)
        {
            cout<<nume<<'['<<i<<"]["<<j<<"]=";
            cin>>M[i][j];
        }
}
void afisare(int M[][21],int lm,int cm)
{
    int i,j;
    for(i=1;i<=lm;i++)
    {
        for(j=1;j<=cm;j++)
            cout<<M[i][j]<<' ';
        cout<<endl;
    }
}
void transpusa(int M[][21],int N[][21],int lm,int cm)
{
    int i,j;
    for(i=1;i<=cm;i++)
        for(j=1;j<=lm;j++)
            N[i][j]=M[j][i];
}
void adunare(int M[][21],int N[][21],int O[][21],int lm,int cm)
{
    int i,j;
    for(i=1;i<=lm;i++)
        for(j=1;j<=cm;j++)
            O[i][j]=M[i][j]+N[i][j];
}
void scadere(int M[][21],int N[][21],int O[][21],int lm,int cm)
{
    int i,j;
    for(i=1;i<=lm;i++)
        for(j=1;j<=cm;j++)
            O[i][j]=M[i][j]-N[i][j];
}
void inmultire(int M[][21],int N[][21],int O[][21],int lm,int cm,int ln,int cn)
{
    int i,j,k;
    k=cm;
    for(i=1;i<=lm;i++)
        for(j=1;j<=cn;j++)
        {
            O[i][j]=0;
            for(k=1;k<=cm;k++)
                O[i][j]=O[i][j]+(M[i][k]*N[k][j]);
        }
}
int determinant(int M[][21],int n)
{
    int det,submat[21][21],k,i,j,subi,subj;
    if(n==1)
        return M[1][1];
    else
    {
        det=0;
        for(k=1;k<=n;k++)
        {
            subi=1;
            for(i=2;i<=n;i++)
            {
                subj=1;
                for(j=1;j<=n;j++)
                    if(j!=k)
                    {
                        submat[subi][subj]=M[i][j];
                        subj++;
                    }
                subi++;
            }
            if((k+1)%2==0)
                det=det+M[1][k]*determinant(submat,n-1);
            else
                det=det+(-1)*M[1][k]*determinant(submat,n-1);
        }
        return det;
    }
}
void optiune(int opt,int A[][21],int B[][21],int C[][21],int la,int ca,int lb,int cb)
{
    switch(opt)
    {
        case 1:if(la==ca)
            {
                inmultire(A,A,C,la,ca,la,ca);
                cout<<"Inmultirea lui A cu A este:"<<endl;
                afisare(C,la,ca);
            }
            else
                cout<<"Nu este posibila inmultirea."<<endl;
            system("pause");
        break;
        case 2:if(lb==cb)
            {
                inmultire(B,B,C,lb,cb,lb,cb);
                cout<<"Inmultirea lui B cu B este:"<<endl;
                afisare(C,lb,cb);
            }
            else
                cout<<"Nu este posibila inmultirea."<<endl;
            system("pause");
        break;
        case 3:if(la==cb)
            {
                inmultire(A,B,C,la,ca,lb,cb);
                cout<<"Inmultirea lui A cu B este:"<<endl;
                afisare(C,la,cb);
            }
            else
                cout<<"Nu este posibila inmultirea."<<endl;
            system("pause");
            break;
        case 4:if(lb==ca)
            {
                inmultire(B,A,C,lb,cb,la,ca);
                cout<<"Inmultirea lui B cu A este:"<<endl;
                afisare(C,lb,ca);
            }
            else
                cout<<"Nu este posibila inmultirea."<<endl;
            system("pause");
        break;
        default:cout<<"Incercati din nou."<<endl;
            system("pause");
        break;
    }
}
int main()
{
    system("Color F0");
    int A[21][21],B[21][21],C[21][21],la,ca,lb,cb,opt,opt2;
    la=lb=0;ca=cb=0;
    do
    {
        cout<<"Matricea A:"<<endl;
        afisare(A,la,ca);
        cout<<endl<<"Matricea B:"<<endl;
        afisare(B,lb,cb);
        cout<<endl;
        meniu();
        cin>>opt;
        switch(opt)
        {
            case 1:system("cls");
                cout<<"Alegeti matricea pe care doriti sa o cititi:"<<endl;
                cout<<"1.Matricea A"<<endl;
                cout<<"2.Matricea B"<<endl;
                cin>>opt2;
                if(opt2==1)
                {
                    cout<<"Numarul de linii: ";
                    cin>>la;
                    cout<<"Numarul de coloane: ";
                    cin>>ca;
                    citire(A,la,ca,'A');
                }
                else
                {
                    if(opt2==2)
                    {
                        cout<<"Numarul de linii: ";
                        cin>>lb;
                        cout<<"Numarul de coloane: ";
                        cin>>cb;
                        citire(B,lb,cb,'B');
                    }
                    else
                        cout<<"Incercati din nou."<<endl;
                }
                system("pause");
            break;
            case 2:cout<<"Alegeti matricea pentru care doriti sa-i aflati transpusa:"<<endl;
                cout<<"1.Matricea A"<<endl;
                cout<<"2.Matricea B"<<endl;
                cin>>opt2;
                if(opt2==1)
                {
                    transpusa(A,C,la,ca);
                    cout<<"Transpusa lui A este:"<<endl;
                    afisare(C,ca,la);
                }
                else
                {
                    if(opt2==2)
                    {
                        transpusa(B,C,lb,cb);
                        cout<<"Transpusa lui B este:"<<endl;
                        afisare(C,cb,lb);
                    }
                    else
                        cout<<"Incercati din nou."<<endl;
                }
                system("pause");
            break;
            case 3:if(la==lb and ca==cb)
                    {
                        cout<<"Suma matricelor A si B este:"<<endl;
                        adunare(A,B,C,la,ca);
                        afisare(C,la,ca);
                    }
                    else
                    cout<<"Matricele trebuie sa fie de acelasi tip."<<endl;
                    system("pause");
            break;
            case 4:cout<<"Alegeti una dintre urmatoarele optiuni:"<<endl;
                cout<<"1.A-B"<<endl;
                cout<<"2.B-A"<<endl;
                cin>>opt2;
                if(opt2==1)
                {
                    if(la==lb and ca==cb)
                    {
                        cout<<"Scaderea A-B este:"<<endl;
                        scadere(A,B,C,la,ca);
                        afisare(C,la,ca);
                    }
                    else
                        cout<<"Matricele trebuie sa fie de acelasi tip."<<endl;
                }
                else
                {
                    if(opt2==2)
                    {
                        if(la==lb and ca==cb)
                        {
                            cout<<"Scaderea B-A este:"<<endl;
                            scadere(B,A,C,la,ca);
                            afisare(C,la,ca);
                        }
                        else
                            cout<<"Matricele trebuie sa fie de acelasi tip."<<endl;
                    }
                    else
                        cout<<"Incercati din nou"<<endl;
                }
                system("pause");
            break;
            case 5:cout<<"Alegeti una dintre urmatoarele optiuni:"<<endl;
                cout<<"1.A*A"<<endl;
                cout<<"2.B*B"<<endl;
                cout<<"3.A*B"<<endl;
                cout<<"4.B*A"<<endl;
                cin>>opt2;
                optiune(opt2,A,B,C,la,ca,lb,cb);
            break;
            case 6:cout<<"Alegeti matricea careia doriti sa-i calculati determinantul"<<endl;
                cout<<"1.Matricea A"<<endl;
                cout<<"2.Matricea B"<<endl;
                cin>>opt2;
                if(opt2==1)
                {
                    if(la==ca and la!=0)
                        cout<<"Determinantul matricei A este: "<<determinant(A,la)<<endl;
                    else
                    {
                        if(la==0)
                            cout<<"Determinantul matricei A este multimea vida."<<endl;
                        else
                            cout<<"Nu se poate calcula determinantul."<<endl;
                    }
                }
                else
                {
                    if(opt2==2)
                    {
                        if(lb==cb and lb!=0)
                            cout<<"Determinantul matricei B este: "<<determinant(B,lb)<<endl;
                        else
                        {
                            if(lb==0)
                                cout<<"Determinantul matricei B este multimea vida."<<endl;
                            else
                                cout<<"Nu se poate calcula determinantul."<<endl;
                        }
                    }
                    else
                        cout<<"Incercati din nou."<<endl;
                }
                system("pause");
            break;
        }
        system("cls");
    }while(opt!=7);
    system("cls");
    cout<<"La revedere!"<<endl;
    system("pause");
}
