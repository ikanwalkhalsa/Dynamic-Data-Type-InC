#include<iostream>
#include<typeinfo>
using namespace std;

template<typename dynamic>
class Dynamic{
    private:
        dynamic data;
    public:
        void operator=(dynamic data){
            this->data=data;
        }
        Dynamic operator + (dynamic &other){
            Dynamic res = *this;
            res->data+=other->data;
            return res;
        }
        void operator += (dynamic &other){
            data+=other->data;
        }
        Dynamic operator - (dynamic &other){
            Dynamic res = *this;
            res->data-=other->data;
            return res;
        }
        void operator -= (dynamic &other){
            data+=other->data;
        }
        Dynamic operator * (dynamic &other){
            Dynamic res = *this;
            res->data*=other->data;
            return res;
        }
        void operator *= (dynamic &other){
            data*=other->data;
        }
        Dynamic operator / (dynamic &other){
            Dynamic res = *this;
            res->data+=other->data;
            return res;
        }
        void operator /= (Dynamic &other){
            data/=other->data;
        }
        bool operator < (Dynamic &other){
            return data<other->data;
        }
        bool operator <= (Dynamic &other){
            return data<=other->data;
        }
        bool operator > (Dynamic &other){
            return data>other->data;
        }
        bool operator >= (Dynamic &other){
            return data>=other->data;
        }
        bool operator == (Dynamic &other){
            return data==other->data;
        }
        bool operator != (Dynamic &other){
            return data!=other->data;
        }
        friend ostream &operator << (ostream &out,Dynamic other){
           out<<other.data;
           return out;
        }
};
class DD{
    public:
        void operator = (initializer_list<auto> arr){
            for(auto a:arr){
                Dynamic<decltype(a)> b;
                b = a;
                cout<<b<<endl;
            }
        }
};

int main(){
    DD dl;
    dl = {1,2,3};
}