#include <iostream>

class Rational
{
public:
   Rational(int numerator, int denominator = 1) : numer{numerator}, denom{denominator} {
       if (denominator<0) numer=-numer,
       denom=-denom;
       initialize(numer, denom);
   };
   ~Rational() {}
   Rational(const Rational& copy): numer{copy.numer}, denom{copy.denom}, gcdND{copy.gcdND} {};


   Rational& operator=(const Rational& other){
       if (this!= &other) {
       this->numer=other.numer;
       this->denom=other.denom;
       this->gcdND=other.gcdND;

   }
       return *this;

   };

   Rational& operator=(int i)
   { this->numer = i;
       this->denom = 1;
       this->gcdND = 1;
       return *this;
   } ;

   int numerator() const { return numer; }
   int denominator() const { return denom; }

   static Rational normalize(const Rational& other){

       return Rational(other.numerator()/other.gcdND, other.denominator()/other.gcdND);
   };

   static Rational normalized(int numerator, int denominator){
       return normalize(Rational(numerator, denominator));
   };

   Rational operator+(const Rational& other) const{
       return Rational::normalize(Rational((this->numerator()*other.denominator())+(other.numerator()*this->numerator()), this->denominator()*other.denominator()));
   };
   Rational operator-(const Rational& other) const{
       return Rational::normalize(Rational((this->numerator()*other.denominator())-(other.numerator()*this->denominator()), this->denominator()*other.denominator()));
   };
   Rational operator*(const Rational& other) const{
       return normalize(Rational(this->numerator()*other.numerator(), this->denominator()*other.denominator()));
   };
   Rational operator/(const Rational& other) const{
       return normalize(Rational(this->numerator()*other.denominator(), this->denominator()*other.numerator()));
   };

   Rational operator+() const{
       return Rational(+(this->numerator()), +(this->denominator()));

   };
   Rational operator-() const{
       return Rational(-(this->numerator()), -(this->denominator()));
   };

   bool operator==(const Rational& other) const{
       if(other.numerator()==this->numerator() && other.denominator()==this->denominator())
           return true;
       else return false;
   };
   bool operator>=(const Rational& other) const{
       if(this->numerator()/this->denominator()>=other.numerator()/other.denominator())
           return true;
       else return false;
   };
   bool operator<=(const Rational& other) const{
       if(this->numerator()/this->denominator()<=other.numerator()/other.denominator())
           return true;
       else return false;
   };
   bool operator>(const Rational& other) const{
       if(this->numerator()/this->denominator()>other.numerator()/other.denominator())
           return true;
       else return false;
   };;
   bool operator<(const Rational& other) const{
       if(this->numerator()/this->denominator()<other.numerator()/other.denominator())
           return true;
       else return false;
   };;

private:
   int numer;
   int denom;
   int gcdND;

   void initialize(int numerator, int denominator){
       if (numerator == 0)
               gcdND=denominator;
       else
           initialize(denominator%numerator, numerator);
         };



   friend std::ostream& operator<<(std::ostream &, const Rational &);
   friend std::istream& operator>>(std::istream &, Rational &);
};

Rational operator+(const Rational& r, int i){
    return Rational::normalize(Rational(r.numerator()+i*r.denominator(), r.denominator()));
};
Rational operator+(int i, const Rational& r){
    return Rational::normalize(Rational(r.numerator()+i*r.denominator(), r.denominator()));
};

Rational operator-(const Rational& r, int i){
    return Rational::normalize(Rational(r.numerator()-i*r.denominator(), r.denominator()));
};
Rational operator-(int i, const Rational& r){
    return Rational::normalize(Rational(r.numerator()-i*r.denominator(), r.denominator()));
};

Rational operator*(const Rational& r, int i){
    return Rational(r.numerator()*i, r.denominator());
};
Rational operator*(int i, const Rational& r){
    return Rational(r.numerator()*i, r.denominator());
};

Rational operator/(const Rational& r, int i){
    return Rational::normalize(Rational(r.numerator(),r.denominator()*i));
};
Rational operator/(int i, const Rational& r){
    return Rational::normalize(Rational(r.numerator(),r.denominator()*i));
};

std::ostream &operator<<(std::ostream &os, const Rational &r){
    if (r.numer<0 ) os<<"("<<r.numer<<"/"<<r.denom<<")";
    else os<<r.numer<<"/"<<r.denom;
    return os;
};


std::istream& operator>>(std::istream &is, Rational &r){
    is >> r.numer;
    is >> r.denom;
    return is;
}
