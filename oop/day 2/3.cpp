#include <iostream>

using namespace std;

class Complex{
    private:
        int real;
        int imag;
    public:
        void get_data();
        void show_data();
        Complex add_complex(Complex);
        Complex sub_complex(Complex);
        Complex mul_complex(Complex);
        Complex mul_complex(int);

        Complex();
        Complex(const Complex&);
};

void Complex::get_data(){
    cout<<"Enter real part:";
    cin>>real;
    cout<<"Enter imaginary part:";
    cin>>imag;
}

void Complex::show_data(){
    char sign = (imag<0)?'-':'+';
    cout<<real<<sign<<abs(imag)<<'i'<<endl;
}

Complex Complex::add_complex(Complex c){
    Complex ans = c;
    ans.real+=this->real;
    ans.imag+=this->imag;

    return ans;
}

Complex Complex::sub_complex(Complex c){
    Complex ans = *this;
    ans.real-=c.real;
    ans.imag-=c.imag;

    return ans;
}

Complex Complex::mul_complex(Complex c){
    Complex ans;
    ans.real=(this->real * c.real) - (this->imag * c.imag);
    ans.imag=(this->real * c.imag) + (this->imag * c.real);
    return ans;
}

Complex Complex::mul_complex(int n){
    Complex ans=*this;
    ans.real*=n;
    ans.imag*=n;
    return ans;
}


Complex::Complex(){
    real=0;
    imag=0;
}

Complex::Complex(const Complex& c){
    real = c.real;
    imag = c.imag;
}

int main(){
    Complex c1,c2;
    c1.get_data();
    c2.get_data();

    cout<<"First complex number: ";
    c1.show_data();
    cout<<"Second complex number: ";
    c1.show_data();

    Complex sum=c1.add_complex(c2);
    Complex diff=c1.sub_complex(c2);
    Complex prod1=c1.mul_complex(c2);
    Complex prod2=c1.mul_complex(6);

    cout<<"Sum:";
    sum.show_data();

    cout<<"Difference:";
    diff.show_data();

    cout<<"Product:";
    prod1.show_data();

    cout<<"Scalar product:";
    prod2.show_data();





    return 0;
}

