#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    const double f = 152.819;
    int a;
    double Ja, Ka, Jb, Kb; // 앱실론 행렬
    double Del_xa;
    double Del_ya;
    double Del_za;
    double Del_xb;
    double Del_yb;
    double Del_zb;
    double xa, ya, za;

    cout << "xa : ";
    cin >> xa;
    cout << "ya :";
    cin >> ya;
    cout << "za : ";
    cin >> za;

    Del_xa = xa - 0;
    Del_ya = ya - 0;
    Del_za = za - 152.905;
    Del_xb = xa - 93.285;
    Del_yb = ya - 1.013;
    Del_zb = za - 152.167;


    double b14a, b15a, b16a;
    double b24a, b25a, b26a;
    double b14b, b15b, b16b;
    double b24b, b25b, b26b;

    double m11, m12, m13, m21, m22, m23, m31, m32, m33;
    double sm11, sm12, sm13, sm21, sm22, sm23, sm31, sm32, sm33;
    double r_a, r_b, s_a, s_b, q_a, q_b;
    double omega, kapa, pie;

    cout << "오메카 : ";
    cin >> omega;
    cout << "카파 : ";
    cin >> kapa;
    cout << "파이 : ";
    cin >> pie;

    double tomega, tkapa, tpie;

    cout << "오메가 2 :";
    cin >> tomega;
    cout << "카파 2 :";
    cin >> tkapa;
    cout << "파이 2 : ";
    cin >> tpie;


    m11 = cos(pie) * cos(kapa);
    m12 = sin(omega) * sin(pie) * cos(kapa) + cos(omega) * sin(kapa);
    m13 = -1 * cos(omega) * sin(pie) * cos(kapa) + sin(omega) * sin(kapa);
    m21 = -1 * cos(pie) * sin(kapa);
    m22 = (-1 * sin(omega) * sin(pie) * sin(kapa)) + cos(omega) * cos(kapa);
    m23 = cos(omega) * sin(pie) * sin(kapa) + sin(omega) * cos(kapa);
    m31 = sin(pie);
    m32 = -1 * sin(omega) * cos(pie);
    m33 = cos(omega) * cos(pie);

    sm11 = cos(tpie) * cos(tkapa);
    sm12 = sin(tomega) * sin(tpie) * cos(tkapa) + cos(tomega) * sin(tkapa);
    sm13 = -1 * cos(tomega) * sin(tpie) * cos(tkapa) + sin(tomega) * sin(tkapa);
    sm21 = -1 * cos(tpie) * sin(tkapa);
    sm22 = (-1 * sin(tomega) * sin(tpie) * sin(tkapa)) + cos(tomega) * cos(tkapa);
    sm23 = cos(tomega) * sin(tpie) * sin(tkapa) + sin(tomega) * cos(tkapa);
    sm31 = sin(tpie);
    sm32 = -1 * sin(tomega) * cos(tpie);
    sm33 = cos(tomega) * cos(tpie);

    r_a = m11 * Del_xa + m12 * Del_ya + m13 * Del_za;
    r_b = sm11 * Del_xb + sm12 * Del_yb + sm13 * Del_zb;
    s_a = m21 * Del_xa + m22 * Del_ya + m23 * Del_za;
    s_b = sm21 * Del_xb + sm22 * Del_yb + sm23 * Del_zb;
    q_a = m31 * Del_xa + m32 * Del_ya + m33 * Del_za;
    q_b = sm31 * Del_xb + sm32 * Del_yb + sm33 * Del_zb;

  //  cout << "r_a :" << r_a << "S_a : " << s_a << "q_a : " << q_a;

    b14a = (f / (q_a * q_a)) * (r_a * m31 - q_a * m11);
    b15a = (f / (q_a * q_a)) * (r_a * m32 - q_a * m12);
    b16a = (f / (q_a * q_a)) * (r_a * m33 - q_a * m13);

    b24a = (f / (q_a * q_a)) * (s_a * m31 - q_a * m21);
    b25a = (f / (q_a * q_a)) * (s_a * m32 - q_a * m22);
    b26a = (f / (q_a * q_a)) * (s_a * m33 - q_a * m23);

    b14b = (f / (q_b * q_b)) * (r_b * sm31 - q_b * sm11);
    b15b = (f / (q_b * q_b)) * (r_b * sm32 - q_b * sm12);
    b16b = (f / (q_b * q_b)) * (r_b * sm33 - q_b * sm13);

    b24b = (f / (q_b * q_b)) * (s_b * sm31 - q_b * sm21);
    b25b = (f / (q_b * q_b)) * (s_b * sm32 - q_b * sm22);
    b26b = (f / (q_b * q_b)) * (s_b * sm33 - q_b * sm23);

    Ja = 68.6710 + 152.819 * r_a / q_a;
    Jb = -30.699 + 152.819 * r_b / q_b;
    Ka = 17.768 + 152.819 * s_a / q_a;
    Kb = 14.656 + 152.819 * s_b / q_b;

    cout << "m1행렬" << endl;
    cout << m11 << " " << m12 << " " << m13 << endl;
    cout << m21 << " " << m22 << " " << m23 << endl;
    cout << m31 << " " << m32 << " " << m33 << endl;
    cout << "\n";

    cout << "m2행렬" << endl;
    cout << sm11 << " " << sm12 << " " << sm13 << endl;
    cout << sm21 << " " << sm22 << " " << sm23 << endl;
    cout << sm31 << " " << sm32 << " " << sm33 << endl;
    cout << "\n";


    cout << "b행렬" << endl;
    cout << "      ( " << b14a << " )    ( " << b15a << " )     ( " << b16a << " )" << endl;
    cout << "      ( " << b24a << " )    ( " << b25a << " )     ( " << b26a << " )" << endl;
    cout << "      ( " << b14b << " )    ( " << b15b << " )     ( " << b16b << " )" << endl;
    cout << "      ( " << b24b << " )    ( " << b25b << " )     ( " << b26b << " )" << endl;
    cout << "\n";

    cout << "앱실론 행렬" << endl;
    cout << Ja << "\n" << Ka << "\n" << Jb << "\n " << Kb << "\n ";
    cout << "\n";

    cin >> a;

    return 0;
}