#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a;
    const double kie = 3.141592;
    const double f = 152.916;
    double Del_xl;
    double Del_yl;
    double Del_zl;
    cout << "Del_xl : ";
    cin >> Del_xl;
    cout << "Del_yl :";
    cin >> Del_yl;
    cout << "Del_zl : ";
    cin >> Del_zl;
    double m11, m12, m13, m21, m22, m23, m31, m32, m33;
    double omega, kapa, pie;
    double Del_xa = 1268.102 - Del_xl;
    double Del_ya = 1455.027 - Del_yl;
    double Del_za = 22.606 - Del_zl;
    double Del_xb = 732.181 - Del_xl;
    double Del_yb = 545.344 - Del_yl;
    double Del_zb = 22.299 - Del_zl;
    double Del_xc = 1454.553 - Del_xl;
    double Del_yc = 731.666 - Del_yl;
    double Del_zc = 22.649 - Del_zl;
    double Del_xd = 545.245 - Del_xl;
    double Del_yd = 1268.232 - Del_yl;
    double Del_zd = 22.336 - Del_zl;
    double r_a, r_b, r_c, r_d, s_a, s_b, s_c, s_d, q_a, q_b, q_c, q_d;
    cout << "오메카 : ";
    cin >> omega;
    cout << "카파 : ";
    cin >> kapa;
    cout << "파이 : ";
    cin >> pie;


    m11 = cos(pie) * cos(kapa);
    m12 = sin(omega) * sin(pie) * cos(kapa) + cos(omega) * sin(kapa);
    m13 = -1 * cos(omega) * sin(pie) * cos(kapa) + sin(omega) * sin(kapa);
    m21 = -1 * cos(pie) * sin(kapa);
    m22 = (-1 * sin(omega) * sin(pie) * sin(kapa)) + cos(omega) * cos(kapa);
    m23 = cos(omega) * sin(pie) * sin(kapa) + sin(omega) * cos(kapa);
    m31 = sin(pie);
    m32 = -1 * sin(omega) * cos(pie);
    m33 = cos(omega) * cos(pie);
    r_a = m11 * Del_xa + m12 * Del_ya + m13 * Del_za;
    r_b = m11 * Del_xb + m12 * Del_yb + m13 * Del_zb;
    r_c = m11 * Del_xc + m12 * Del_yc + m13 * Del_zc;
    r_d = m11 * Del_xd + m12 * Del_yd + m13 * Del_zd;
    s_a = m21 * Del_xa + m22 * Del_ya + m23 * Del_za;
    s_b = m21 * Del_xb + m22 * Del_yb + m23 * Del_zb;
    s_c = m21 * Del_xc + m22 * Del_yc + m23 * Del_zc;
    s_d = m21 * Del_xd + m22 * Del_yd + m23 * Del_zd;
    q_a = m31 * Del_xa + m32 * Del_ya + m33 * Del_za;
    q_b = m31 * Del_xb + m32 * Del_yb + m33 * Del_zb;
    q_c = m31 * Del_xc + m32 * Del_yc + m33 * Del_zc;
    q_d = m31 * Del_xd + m32 * Del_yd + m33 * Del_zd;


    double b11a, b12a, b13a, b14a, b15a, b16a;
    double b21a, b22a, b23a, b24a, b25a, b26a;
    double b11b, b12b, b13b, b14b, b15b, b16b;
    double b21b, b22b, b23b, b24b, b25b, b26b;
    double b11c, b12c, b13c, b14c, b15c, b16c;
    double b21c, b22c, b23c, b24c, b25c, b26c;
    double b11d, b12d, b13d, b14d, b15d, b16d;
    double b21d, b22d, b23d, b24d, b25d, b26d;
    double Ja, Ka, Jb, Kb, Jc, Kc, Jd, Kd; // 앱실론 행렬

    b11a = (f / (q_a * q_a)) * (r_a * (-1 * m33 * Del_ya + m32 * Del_za) - q_a * (-1 * m13 * Del_ya + m12 * Del_za));
    b12a = (f / (q_a * q_a)) * (r_a * (cos(pie) * Del_xa + sin(omega) * sin(pie) * Del_ya - cos(omega) * sin(pie) * Del_za) - q_a * (-1 * sin(pie) * cos(kapa) * Del_xa + sin(omega) * cos(pie) * cos(kapa) * Del_ya - cos(omega) * cos(pie) * cos(kapa) * Del_za));
    b13a = -1 * f / q_a * (m21 * Del_xa + m22 * Del_ya + m23 * Del_za);
    b14a = (f / (q_a * q_a)) * (r_a * m31 - q_a * m11);
    b15a = (f / (q_a * q_a)) * (r_a * m32 - q_a * m12);
    b16a = (f / (q_a * q_a)) * (r_a * m33 - q_a * m13);

    b21a = (f / (q_a * q_a)) * (s_a * (-1 * m33 * Del_ya + m32 * Del_za) - q_a * (-1 * m23 * Del_ya + m22 * Del_za));
    b22a = (f / (q_a * q_a)) * (s_a * (cos(pie) * Del_xa + sin(omega) * sin(pie) * Del_ya - cos(omega) * sin(pie) * Del_za) - q_a * (sin(pie) * sin(kapa) * Del_xa - sin(omega) * cos(pie) * sin(kapa) * Del_ya + cos(omega) * cos(pie) * sin(kapa) * Del_za));
    b23a = f / q_a * (m11 * Del_xa + m12 * Del_ya + m13 * Del_za);
    b24a = (f / (q_a * q_a)) * (s_a * m31 - q_a * m21);
    b25a = (f / (q_a * q_a)) * (s_a * m32 - q_a * m22);
    b26a = (f / (q_a * q_a)) * (s_a * m33 - q_a * m23);

    b11b = (f / (q_b * q_b)) * (r_b * (-1 * m33 * Del_yb + m32 * Del_zb) - q_b * (-1 * m13 * Del_yb + m12 * Del_zb));
    b12b = (f / (q_b * q_b)) * (r_b * (cos(pie) * Del_xb + sin(omega) * sin(pie) * Del_yb - cos(omega) * sin(pie) * Del_zb) - q_b * (-1 * sin(pie) * cos(kapa) * Del_xb + sin(omega) * cos(pie) * cos(kapa) * Del_yb - cos(omega) * cos(pie) * cos(kapa) * Del_zb));
    b13b = -1 * f / q_b * (m21 * Del_xb + m22 * Del_yb + m23 * Del_zb);
    b14b = (f / (q_b * q_b)) * (r_b * m31 - q_b * m11);
    b15b = (f / (q_b * q_b)) * (r_b * m32 - q_b * m12);
    b16b = (f / (q_b * q_b)) * (r_b * m33 - q_b * m13);

    b21b = (f / (q_b * q_b)) * (s_b * (-1 * m33 * Del_yb + m32 * Del_zb) - q_b * (-1 * m23 * Del_yb + m22 * Del_zb));
    b22b = (f / (q_b * q_b)) * (s_b * (cos(pie) * Del_xb + sin(omega) * sin(pie) * Del_yb - cos(omega) * sin(pie) * Del_zb) - q_b * (sin(pie) * sin(kapa) * Del_xb - sin(omega) * cos(pie) * sin(kapa) * Del_yb + cos(omega) * cos(pie) * sin(kapa) * Del_zb));
    b23b = f / q_b * (m11 * Del_xb + m12 * Del_yb + m13 * Del_zb);
    b24b = (f / (q_b * q_b)) * (s_b * m31 - q_b * m21);
    b25b = (f / (q_b * q_b)) * (s_b * m32 - q_b * m22);
    b26b = (f / (q_b * q_b)) * (s_b * m33 - q_b * m23);

    b11c = (f / (q_c * q_c)) * (r_c * (-1 * m33 * Del_yc + m32 * Del_zc) - q_c * (-1 * m13 * Del_yc + m12 * Del_zc));
    b12c = (f / (q_c * q_c)) * (r_c * (cos(pie) * Del_xc + sin(omega) * sin(pie) * Del_yc - cos(omega) * sin(pie) * Del_zc) - q_c * (-1 * sin(pie) * cos(kapa) * Del_xc + sin(omega) * cos(pie) * cos(kapa) * Del_yc - cos(omega) * cos(pie) * cos(kapa) * Del_zc));
    b13c = -1 * f / q_c * (m21 * Del_xc + m22 * Del_yc + m23 * Del_zc);
    b14c = (f / (q_c * q_c)) * (r_c * m31 - q_c * m11);
    b15c = (f / (q_c * q_c)) * (r_c * m32 - q_c * m12);
    b16c = (f / (q_c * q_c)) * (r_c * m33 - q_c * m13);

    b21c = (f / (q_c * q_c)) * (s_c * (-1 * m33 * Del_yc + m32 * Del_zc) - q_c * (-1 * m23 * Del_yc + m22 * Del_zc));
    b22c = (f / (q_c * q_c)) * (s_c * (cos(pie) * Del_xc + sin(omega) * sin(pie) * Del_yc - cos(omega) * sin(pie) * Del_zc) - q_c * (sin(pie) * sin(kapa) * Del_xc - sin(omega) * cos(pie) * sin(kapa) * Del_yc + cos(omega) * cos(pie) * sin(kapa) * Del_zc));
    b23c = f / q_c * (m11 * Del_xc + m12 * Del_yc + m13 * Del_zc);
    b24c = (f / (q_c * q_c)) * (s_c * m31 - q_c * m21);
    b25c = (f / (q_c * q_c)) * (s_c * m32 - q_c * m22);
    b26c = (f / (q_c * q_c)) * (s_c * m33 - q_c * m23);

    b11d = (f / (q_d * q_d)) * (r_d * (-1 * m33 * Del_yd + m32 * Del_zd) - q_d * (-1 * m13 * Del_yd + m12 * Del_zd));
    b12d = (f / (q_d * q_d)) * (r_d * (cos(pie) * Del_xd + sin(omega) * sin(pie) * Del_yd - cos(omega) * sin(pie) * Del_zd) - q_d * (-1 * sin(pie) * cos(kapa) * Del_xd + sin(omega) * cos(pie) * cos(kapa) * Del_yd - cos(omega) * cos(pie) * cos(kapa) * Del_zd));
    b13d = -1 * f / q_d * (m21 * Del_xd + m22 * Del_yd + m23 * Del_zd);
    b14d = (f / (q_d * q_d)) * (r_d * m31 - q_d * m11);
    b15d = (f / (q_d * q_d)) * (r_d * m32 - q_d * m12);
    b16d = (f / (q_d * q_d)) * (r_d * m33 - q_d * m13);

    b21d = (f / (q_d * q_d)) * (s_d * (-1 * m33 * Del_yd + m32 * Del_zd) - q_d * (-1 * m23 * Del_yd + m22 * Del_zd));
    b22d = (f / (q_d * q_d)) * (s_d * (cos(pie) * Del_xd + sin(omega) * sin(pie) * Del_yd - cos(omega) * sin(pie) * Del_zd) - q_d * (sin(pie) * sin(kapa) * Del_xd - sin(omega) * cos(pie) * sin(kapa) * Del_yd + cos(omega) * cos(pie) * sin(kapa) * Del_zd));
    b23d = f / q_d * (m11 * Del_xd + m12 * Del_yd + m13 * Del_zd);
    b24d = (f / (q_d * q_d)) * (s_d * m31 - q_d * m21);
    b25d = (f / (q_d * q_d)) * (s_d * m32 - q_d * m22);
    b26d = (f / (q_d * q_d)) * (s_d * m33 - q_d * m23);

    Ja = 86.421 + 152.916 * r_a / q_a;
    Jb = -100.916 + 152.916 * r_b / q_b;
    Jc = -98.322 + 152.916 * r_c / q_c;
    Jd = 78.812 + 152.916 * r_d / q_d;
    Ka = -83.977 + 152.916 * s_a / q_a;
    Kb = 92.582 + 152.916 * s_b / q_b;
    Kc = -89.161 + 152.916 * s_c / q_c;
    Kd = 98.123 + 152.916 * s_d / q_d;

    cout << "m행렬" << endl;
    cout << m11 << " " << m12 << " " << m13 << endl;
    cout << m21 << " " << m22 << " " << m23 << endl;
    cout << m31 << " " << m32 << " " << m33 << endl;


    cout << "b행렬" << endl;
    cout << b11a << " " << b12a << " " << b13a << " " << -1 * b14a << " " << -1 * b15a << " " << -1 * b16a << " " << endl;
    cout << b21a << " " << b22a << " " << b23a << " " << -1 * b24a << " " << -1 * b25a << " " << -1 * b26a << " " << endl;
    cout << b11b << " " << b12b << " " << b13b << " " << -1 * b14b << " " << -1 * b15b << " " << -1 * b16b << " " << endl;
    cout << b21b << " " << b22b << " " << b23b << " " << -1 * b24b << " " << -1 * b25b << " " << -1 * b26b << " " << endl;
    cout << b11c << " " << b12c << " " << b13c << " " << -1 * b14c << " " << -1 * b15c << " " << -1 * b16c << " " << endl;
    cout << b21c << " " << b22c << " " << b23c << " " << -1 * b24c << " " << -1 * b25c << " " << -1 * b26c << " " << endl;
    cout << b11d << " " << b12d << " " << b13d << " " << -1 * b14d << " " << -1 * b15d << " " << -1 * b16d << " " << endl;
    cout << b21d << " " << b22d << " " << b23d << " " << -1 * b24d << " " << -1 * b25d << " " << -1 * b26d << " " << endl;

    cout << "앱실론 행렬" << endl;
    cout << Ja << "\n" << Ka << "\n" << Jb << "\n " << Kb << "\n " << Jc << "\n " << Kc << "\n " << Jd << "\n " << Kd << "\n " << endl;

    cin >> a;
    return 0;
}