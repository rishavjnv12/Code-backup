#include<bits/stdc++.h>
using namespace std;
class Complex{
    int real;
    int imag;
public:
    void getData()
    {
        cout<<"Enter the real number\n";
        cin>>real;
        cout<<"Enter the imaginary number\n";
        cin>>imag;
    }
    void showData()
    {
        cout<<"Real:"<<real<<"\n";
        cout<<"Imaginary:"<<imag<<"\n";

    }
    Complex addComplex(Complex c1,Complex c2)
    {
        Complex c;
        c.real=c1.real+c2.real;
        c.imag=c1.imag+c2.imag;
        return c;
    }
    Complex subComplex(Complex c1,Complex c2)
    {
        Complex c;
        c.real=c1.real-c2.real;
        c.imag=c1.imag-c2.imag;
        return c;
    }
    Complex mulComplex(Complex c1,Complex c2)
    {
        Complex c;
        c.real=((c1.real)*(c2.real));
        c.imag=((c1.imag)*(c2.imag));
        return c;
    }
    Complex divideComplex(Complex c1,Complex c2)
    {
        Complex c;
        c.real=((c1.real)/(c2.real));
        c.imag=((c1.imag)/(c2.imag));
        return c;
    }
    Complex mulComp(int val)
    {
        
        Complex* c = new Complex();
        
        c->real=this->real*val;
        c->imag=this->imag*val;

        cout<<"Here"<<endl;
        c->showData();
        return *c;
    }
    Complex(int r=0,int i=0){
        real=r;
        imag=i;
    }

};
int main()
{
    Complex c,c1,c2,c3,c4,c5,c6,c7;
    cout<<"Complex1\n";
    c1.getData();
    cout<<"Complex25\n";

    c2.getData();
    c3=c.addComplex(c1, c2);
    cout<<"Addition:"<<"\n";
    c3.showData();
    c4=c.subComplex(c1, c2);
    cout<<"Subtraction:"<<"\n";
    c4.showData();
    c5=c.mulComplex(c1, c2);
    cout<<"Multiplication:"<<"\n";
    c5.mulComplex(c1, c2);
    c5.showData();
    c6=c.divideComplex(c1, c2);
    cout<<"Division:\n";
    c6.showData();
    int val;
    cout<<"Enter the val:";
    cin>>val;
    cout<<val<<" "<<"value"<<endl;
    c7=c1.mulComp(val);
    cout<<"mulComp:\n";
    c7.showData();

    cout<<"\n";
    return 0;
}