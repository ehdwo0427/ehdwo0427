#include<iostream>
using namespace std;

class car{
private:
    int gasolineGauge;
public:
    car(int Gauge) : gasolineGauge(Gauge)
    {}
    int GetGasGauge(){
        return gasolineGauge;
    }
};

class HybridCar : public car{
private:
    int electricGauge;
public:
    HybridCar(int Gauge, int electricfuel) :car(Gauge),electricGauge(electricfuel)
    {}
    int GetElecGauge(){
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar{
private:
    int waterGauge;
public:
    HybridWaterCar(int Gauge, int electricfuel, int Water) : HybridCar(Gauge, electricfuel), waterGauge(Water)
    {}
    void ShowCurrentGauge(){
        cout<<"잔여 가솔린: "<< GetGasGauge()<<'\n';
        cout<<"잔여 전기량: "<< GetElecGauge()<<'\n';
        cout<<"잔여 워터량: "<< waterGauge << '\n';
    }
};

int main(){
    HybridWaterCar watercar(10, 15, 20);
    watercar.ShowCurrentGauge();
    return 0;
}
